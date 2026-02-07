#include <iostream>
#include "commands.h"
#include "storage.h"

using namespace std;

int main(){
    cout <<"=== TinyDB v1 ===\n";
    while(true)
    {
        string line;
        cout << ">> ";
        getline(cin, line);
        parse(line);
    }
}
