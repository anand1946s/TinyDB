#include <iostream>
#include "commands.h"

using namespace std;

int main()
{
    while(true)
    {
        string line;
        getline(cin, line);
        parse(line);
    }
}
