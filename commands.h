#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <vector>

using namespace std;

void parse(string line);
vector<string> tokenize(string line);

#endif