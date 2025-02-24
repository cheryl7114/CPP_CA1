//
// Created by Cheryl Kong on 24/02/2025.
//
#include "employee.h"
#include <fstream>
#include <sstream>
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
}

void displayEmployees(const vector<Employee> &employees) {
    // Table Header
    cout << left << setw(6) << "ID"
         << setw(23) << "Name"
         << setw(7) << "Age"
         << setw(13) << "Department"
         << setw(12) << "Salary"
         << setw(10) << "Experience" << endl;

    cout << string(73, '-') << endl; // Horizontal line

    // Display Employee Data
    for (const Employee &emp : employees) {
        cout << left << setw(6) << emp.id
             << setw(23) << emp.name
             << setw(7) << emp.age
             << setw(13) << emp.department
             << "$" << setw(12) << fixed << setprecision(2) << emp.salary
             << emp.yearsOfExperience << " years" << endl;
    }
    cout << "\n";
}

int findIndexOfEmployeeByID(const vector<Employee> &employees, int id) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void displayEmployeeByID(const vector<Employee> &employees, int id) {
    int index = findIndexOfEmployeeByID(employees, id);

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
