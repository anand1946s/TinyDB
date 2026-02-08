#include "commands.h"
#include "storage.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;
int flush_count = 0;

void parse_insert(const vector<string>& tokens)
{
    if(tokens.size() !=3){
        cout << "FORMAT: INSERT <key> <value>\n";
        return;
    }

    const string& key = tokens[1];
    const string& value = tokens[2];
    if(storage_insert(key,value))
        cout <<"INSERT: OK" << "\n";
    
    else
        cout << "ACTION: FAILED\n";


}


void parse_find(vector<string> tokens){
    if(tokens.size() != 2){
        cout << "FORMAT: FIND <key>\n";
        return;
    }

    string value;
    if(storage_select(tokens[1],value))
        cout << value <<"\n";
    else
        cout << "ACTION: KEY NOT FOUND\n";
}


vector<string> tokenize(string line)
{
    vector<string> tokens;
    string word = "";

    for(char c : line)
    {
        if(c == ' ')
        {
            if(word.size() > 0)
            {
                tokens.push_back(word);
                word = "";
            }
        }
        else
            word += c;
    }

    if(word.size() > 0)
        tokens.push_back(word);

    return tokens;
}

void parse(string line)
{
    vector<string> tokens = tokenize(line);

    if(tokens.size() == 0)
        return;

    string cmd = tokens[0];

    if(cmd == "INSERT")
        parse_insert(tokens);
    else if(cmd == "FIND")
        parse_find(tokens);
    else if (cmd == "LIST")
        print_all();
    else if(cmd == "DEL")
        storage_delete(tokens[1]);
    else if(cmd == "UPDATE")
        storage_update(tokens[1],tokens[2]);
    else if(cmd == "EXIT"){
        storage_flush();
        exit(0);
    }
    else
        cout << "Unknown command\n";
    flush_count++;
    if(flush_count%5 == 0)
        storage_flush();
}
