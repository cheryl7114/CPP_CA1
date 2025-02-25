//
// Created by Cheryl Kong on 24/02/2025.
//
#include "employee.h"
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>

void readfile(const string &filePath, vector<Employee>& employees) {
    ifstream fin(filePath);

    if (!fin) {
        cout << "File could not be opened" << endl;
        return;
    }

    string line;
    getline(fin, line); // Read and discard header row

    while (getline(fin, line)) {
        stringstream ss(line);
        Employee emp;
        string temp;

        // Parse id
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.id = stoi(temp);

        // Parse name
        if (!getline(ss, emp.name, ',')) continue;

        // Parse age
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.age = stoi(temp);

        // Parse department
        if (!getline(ss, emp.department, ',')) continue;

        // Parse salary
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.salary = stof(temp);

        // Parse years of experience
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.yearsOfExperience = stoi(temp);

        // Add employee to the vector
        employees.push_back(emp);
    }

    fin.close();
    displayEmployees(employees);
}

void displayEmployees(const vector<Employee> &employeesSubset) {
    if (employeesSubset.empty()) {
        cout << "No employees to display." << endl;
        return;
    }

    // Table header
    cout << "\n" << left << setw(6) << "ID"
         << setw(23) << "Name"
         << setw(7) << "Age"
         << setw(13) << "Department"
         << setw(12) << "Salary"
         << setw(10) << "Experience" << endl;

    cout << string(73, '-') << endl; // Horizontal line

    // Display employee data
    for (const Employee &emp : employeesSubset) {
        cout << left << setw(6) << emp.id
             << setw(23) << emp.name
             << setw(7) << emp.age
             << setw(13) << emp.department
             << "$" << setw(12) << fixed << setprecision(2) << emp.salary
             << emp.yearsOfExperience << " years" << endl;
    }
}

int findIndexOfEmployeeByID(const vector<Employee> &employees, int id) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            // Return i if employee[i]'s id matches id to find
            return i;
        }
    }

    // Return -1 if employee id is not found
    return -1;
}

void displayEmployeeByID(const vector<Employee> &employees, int id) {
    int index = findIndexOfEmployeeByID(employees, id);

    // Display employee details based on found index
    if (index == -1) {
        cout << "\nEmployee with ID " << id << " not found." << endl;
    } else {
        cout << "\nEmployee found!" << endl;
        cout << "Name: " << employees[index].name << endl;
        cout << "Age: " << employees[index].age << endl;
        cout << "Department: " << employees[index].department << endl;
        cout << "Salary: " << employees[index].salary << endl;
        cout << "Experience: " << employees[index].yearsOfExperience << " years\n";
    }
}

void countEmployeesByDepartment(const vector<Employee> &employees, map<string, int> &departmentHeadcount) {
    for (const Employee& emp : employees) {
        // Map according to department
        departmentHeadcount[emp.department]++;
    }
}

void displayDepartmentCounts(const map<string, int> &departmentHeadcount) {
    cout << "\n" << left << setw(15) << "Department"
         << setw(10) << "Headcount" << endl;
    cout << string(25, '-') << endl; // Horizontal line

    // Detect type of variable automatically
    for (const auto &[department, count] : departmentHeadcount) {
        cout << left << setw(15) << department
             << setw(10) << count << endl;
    }
}

void loadEmployeeByDepartment(string department, const vector<Employee> &employees, vector<Employee> &employeesByDepartment) {
    for (const Employee& emp : employees) {
        if (emp.department == department) {
            employeesByDepartment.push_back(emp);
        }
    }
    displayEmployees(employeesByDepartment);
}
