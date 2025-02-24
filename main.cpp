#include "employee.h"

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees;
    int id;

    readfile(fileName, employees);
    displayEmployees(employees);

    // cout << "Enter an employee ID to search for: ";
    // cin >> id;
    // displayEmployeeByID(employees, id);

    // Count employees per department
    map<string, int> departmentHeadcount = countEmployeesByDepartment(employees);

    // Display department counts
    displayDepartmentCounts(departmentHeadcount);

    return 0;
}
