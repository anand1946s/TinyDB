#ifndef STORAGE_H
#define STORAGE_H
#include <string>

using namespace std;

bool storage_insert(const string& key,const string& value);
bool storage_select(const string& key,string& value);
bool storage_delete(const string& key);
bool storage_update(const string& key,const string& newvalue);
bool storage_load();
bool storage_flush();  
void print_all();

#endif