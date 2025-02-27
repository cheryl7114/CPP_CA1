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
        emp.salary = stod(temp);

        // Parse years of experience
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.yearsOfExperience = stoi(temp);

        // Add employee to the vector
        employees.push_back(emp);
    }

    fin.close();
}

void displayEmployees(const vector<Employee> &employees) {
    if (employees.empty()) {
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
    for (const Employee &emp : employees) {
        cout << left << setw(6) << emp.id
             << setw(23) << emp.name
             << setw(7) << emp.age
             << setw(13) << emp.department
             << "€" << setw(12) << fixed << setprecision(2) << emp.salary
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

void loadEmployeeByDepartment(const string& department, const vector<Employee> &employees, vector<Employee> &employeesByDepartment) {
    for (const Employee& emp : employees) {
        if (emp.department == department) {
            employeesByDepartment.push_back(emp);
        }
    }
    displayEmployees(employeesByDepartment);
}

int findAgeStatistics(const vector <Employee> &employees, Employee &youngest, Employee &oldest) {
    if (employees.empty()) return 0; // Avoid code crash bcos of division by zero

    int totalAge = 0;
    youngest = oldest = employees[0];

    for (const Employee &emp : employees) {
        totalAge += emp.age;

        if (emp.age < youngest.age) {
            youngest = emp;
        }

        if (emp.age > oldest.age) {
            oldest = emp;
        }
    }

    return totalAge/employees.size();
}

string toLower(string s) {
    // Referenced https://www.geeksforgeeks.org/how-to-convert-std-string-to-lower-case-in-cpp/
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

vector<Employee> nameMatchInput(const vector<Employee> &employees, string &textInput) {
    vector<Employee> match;

    // Convert textInput to lowercase
    textInput = toLower(textInput);

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        string empName = it->name;

        // Convert employee name to lowercase
        empName = toLower(empName);

        // https://www.geeksforgeeks.org/string-find-in-cpp/
        // string::npos is a constant that represents a non-position or invalid index. When string find() cannot locate the substring or character, it returns string::npos.
        if (empName.find(textInput) != string::npos) {
            match.push_back(*it);
        }
    }

    return match;
}

void sortDescendingSalary(vector<Employee> &descendingSalary) {
    // https://www.digitalocean.com/community/tutorials/sorting-a-vector-in-c-plus-plus
    sort(descendingSalary.begin(), descendingSalary.end(), [](const Employee &a, const Employee&b) {
        return a.salary > b.salary;
    });

    displayEmployees(descendingSalary);
}