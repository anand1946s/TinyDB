#include "commands.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

void parse_insert(vector<string> tokens)
{
    cout << "INSERT command received\n";
}

void parse_delete(vector<string> tokens)
{
    cout << "DELETE command received\n";
}

void parse_find(vector<string> tokens)
{
    cout << "FIND command received\n";
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
    else if(cmd == "DELETE")
        parse_delete(tokens);
    else if(cmd == "FIND")
        parse_find(tokens);
    else if(cmd == "EXIT")
        exit(0);
    else
        cout << "Unknown command\n";
}
