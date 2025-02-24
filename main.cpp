#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Employee {
    string name;
    int age;
    string department;
    float salary;
    int yearsOfExperience;
};

void readfile(const string &filePath, vector<Employee>& employees) {
    ifstream fin(filePath);

    if (!fin) {
        cout << "File could not be opened" << endl;
        return;
    }

    string line;
    getline(fin, line); // read and discard header row

    while (getline(fin, line)) {
        stringstream ss(line);
        Employee emp;
        string temp;

        // parse name
        if (!getline(ss, emp.name, ',')) continue;

        // parse age
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.age = stoi(temp);

        // parse department
        if (!getline(ss, emp.department, ',')) continue;

        // parse salary
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.salary = stof(temp);

        // parse years of experience
        if (!getline(ss, temp, ',') || temp.empty()) continue;
        emp.yearsOfExperience = stoi(temp);

        // add employee to the vector
        employees.push_back(emp);
    }

    fin.close();
}

void displayEmployees(const vector<Employee> &employees) {
    // table Header
    cout << left << setw(25) << "Name"
         << setw(7) << "Age"
         << setw(13) << "Department"
         << setw(12) << "Salary"
         << setw(10) << "Experience" << endl;

    cout << string(70, '-') << endl; // horizontal line

    // Display Employee Data
    for (const Employee &emp : employees) {
        cout << left << setw(25) << emp.name
             << setw(7) << emp.age
             << setw(13) << emp.department
             << "$" << setw(12) << fixed << setprecision(2) << emp.salary
             << emp.yearsOfExperience << " years" << endl;
    }
}

int main() {
    const string fileName = "employees.csv";
    vector<Employee> employees;

    readfile(fileName, employees);
    displayEmployees(employees);

    return 0;
}
