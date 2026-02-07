#include "commands.h"
#include "storage.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

void parse_insert(const vector<string>& tokens)
{
    if(tokens.size() !=3){
        cout << "FORMAT: INSERT <key> <value>";
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
    else if(cmd == "EXIT")
        exit(0);
    else
        cout << "Unknown command\n";
}
