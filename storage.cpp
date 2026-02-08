#include "storage.h"
#include "commands.h"
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

const char* DB_FILE = "data.db";

unordered_map <string,string> kv;
bool dirty = false;

void print_all(){
    if(kv.empty()){
        cout << "DB EMPTY\n";
        return;
    }
    cout << "\n";
    cout << "---------------------\n";

    for(const auto& it : kv){
        
        cout << it.first << "\t|\t" << it.second <<"\n";
    }
    cout << "---------------------\n";
    cout << "\n";
}

bool storage_load() {
    ifstream file(DB_FILE, ios::binary);
    if (!file.is_open()) return true; 
    while (true) {
        uint32_t key_size, value_size;
        file.read(reinterpret_cast<char*>(&key_size), sizeof(key_size));
        if (file.eof()) break;

        string key(key_size, '\0');
        file.read(&key[0], key_size);

        file.read(reinterpret_cast<char*>(&value_size), sizeof(value_size));
        string value(value_size, '\0');
        file.read(&value[0], value_size);

        kv[key] = value;  
    }
    return true;
}



bool storage_insert(const string& key,const string& value){
    if(kv.find(key) != kv.end()){
        cout << "[KEY EXISTS]\n";
        return false;
    }
    kv[key] = value;
    dirty = true;
    return dirty;
}

bool storage_update(const string& key,const string& newvalue){
    auto it = kv.find(key);
    if(it == kv.end())
        return false;
    it->second = newvalue;
    return true;
}

bool storage_select(const string& key, string& out_value) {
    auto it = kv.find(key);
    if (it == kv.end()) return false;

    out_value = it->second;
    return true;
}

bool storage_delete(const string& key) {
    auto it = kv.find(key);
    if (it == kv.end()) {
        cout << "KEY NOT FOUND]\n";
        return false;  
    }

    kv.erase(it);
    dirty = true;
    return true;
}


bool storage_flush() {
    cout << "[FLUSH CALLED]\n";
    if (!dirty) return true;

    ofstream file(DB_FILE, ios::binary | ios::trunc);
    if (!file) return false;

    for (auto& it : kv) {
        const string& key = it.first;
        const string& value = it.second; 

        uint32_t key_size = key.size();
        uint32_t value_size = value.size();

        file.write(reinterpret_cast<char*>(&key_size), sizeof(key_size));
        file.write(key.data(), key_size);

        file.write(reinterpret_cast<char*>(&value_size), sizeof(value_size));
        file.write(value.data(), value_size);
    }

    dirty = false;
    return true;
}

