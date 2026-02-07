#include "storage.h"
#include "commands.h"
#include <iostream>
#include <fstream>

using namespace std;

const char* DB_FILE = "data.db";

bool storage_insert(const string& key, const string& value) {
    ofstream file(DB_FILE, ios::binary | ios::app);
    if (!file) return false;

    uint32_t key_size = key.size();
    uint32_t value_size = value.size();

    file.write(reinterpret_cast<char*>(&key_size), sizeof(key_size));
    file.write(key.data(), key_size);

    file.write(reinterpret_cast<char*>(&value_size), sizeof(value_size));
    file.write(value.data(), value_size);

    return true;
}

bool storage_select(const string& key,string& out_value) {
    ifstream file(DB_FILE,ios::binary);
    if (!file.is_open()) return false;

    while (file.peek() != EOF) {
        uint32_t key_size;
        uint32_t value_size;

        file.read(reinterpret_cast<char*>(&key_size), sizeof(key_size));
        if (file.eof()) break;

        string stored_key(key_size, '\0');
        file.read(&stored_key[0], key_size);

        file.read(reinterpret_cast<char*>(&value_size), sizeof(value_size));
        string stored_value(value_size, '\0');
        file.read(&stored_value[0], value_size);

        if (stored_key == key) {
            out_value = stored_value;
            
        }
    }

    file.close();
    return !out_value.empty();
}
