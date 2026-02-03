#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    char name[50];
    int age;
    float marks;
};

int main(){

    Student s = {"John",12,80};
    ofstream file ("student.dat",ios::binary);
    file.write((char*)&s,sizeof(s));
    file.close();
    cout <<"data saved";


}