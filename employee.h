//
// Created by Cheryl Kong on 24/02/2025.
//
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>

using namespace std;

struct Employee {
    int id;
    string name;
    int age;
    string department;
    float salary;
    int yearsOfExperience;
};

void readfile(const string &filePath, vector<Employee>& employees);
void displayEmployees(const vector<Employee> &employees);
int findIndexOfEmployeeByID(const vector<Employee> &employees, int id);
void displayEmployeeByID(const vector<Employee> &employees, int id);

#endif // EMPLOYEE_H
