//
// Created by Cheryl Kong on 24/02/2025.
//
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <map>

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
void countEmployeesByDepartment(const vector<Employee> &employees, map<string, int> &departmentHeadcount);
void displayDepartmentCounts(const map<string, int> &departmentHeadcount);
void loadEmployeeByDepartment(string department, const vector<Employee> &employees, vector<Employee> &employeesByDepartment);

#endif // EMPLOYEE_H