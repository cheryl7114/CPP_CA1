#include "employee.h"

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees;
    vector<Employee> employeesByDepartment;
    map<string, int> departmentHeadcount;
    string departmentToFind;
    Employee youngest, oldest;
    int id, avgAge;

    readfile(fileName, employees);

    // cout << "Enter an employee ID to search for: ";
    // cin >> id;
    // displayEmployeeByID(employees, 98);

    // // Display department counts
    // countEmployeesByDepartment(employees, departmentHeadcount);
    // displayDepartmentCounts(departmentHeadcount);

    // cout << "\nEnter a department and I will display the employees in it: ";
    // cin >> departmentToFind;
    // loadEmployeeByDepartment(departmentToFind, employees, employeesByDepartment);

    avgAge = findAgeStatistics(employees, youngest, oldest);

    cout << "\nAverage age: " << avgAge << endl;
    cout << "\nYoungest employee: " << endl;
    displayEmployeeByID(employees, youngest.id);
    cout << "\nOldest employee: " << endl;
    displayEmployeeByID(employees, oldest.id);

    return 0;
}
