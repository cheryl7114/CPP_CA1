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
    double salary;
    int yearsOfExperience;
};

void readfile(const string &filePath, vector<Employee>& employees);
void displayEmployees(const vector<Employee>& employees);
int findIndexOfEmployeeByID(const vector<Employee> &employees, int id);
void displayEmployeeByID(const vector<Employee> &employees, int id);
map<string, int> countEmployeesByDepartment(const vector<Employee> &employees);
void displayDepartmentCounts(const map<string, int> &departmentHeadcount);
void loadEmployeeByDepartment(const string& department, const vector<Employee> &employees, vector<Employee> &employeesByDepartment);
int findAgeStatistics(const vector <Employee> &employees, Employee &youngest, Employee &oldest);
vector<Employee> nameMatchInput(const vector<Employee> &employees, string &textInput);
void sortDescendingSalary(vector<Employee> &descendingSalary);
int getValidInt(const string &prompt, int minValue = INT_MIN, int maxValue = INT_MAX);


#endif // EMPLOYEE_H