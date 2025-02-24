#include "employee.h"

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees;
    map<string, int> departmentHeadcount;
    int id;

    readfile(fileName, employees);
    displayEmployees(employees);

    // cout << "Enter an employee ID to search for: ";
    // cin >> id;
    displayEmployeeByID(employees, 98);

    // Display department counts
    countEmployeesByDepartment(employees, departmentHeadcount);
    displayDepartmentCounts(departmentHeadcount);

    return 0;
}
