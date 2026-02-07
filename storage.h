#ifndef STORAGE_H
#define STORAGE_H
#include <string>

using namespace std;

bool storage_insert(const string& key,const string& value);
bool storage_select(const string& key,string& value);

#endif