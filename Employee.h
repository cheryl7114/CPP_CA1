#include <iostream>
#include <fstream>
using namespace std;

struct Employee {
    string name;
    int age;
    string department;
    float salary;
    int yearsOfExperience;
};

void readfile(const string &filePath, vector<Employee>& employees);
