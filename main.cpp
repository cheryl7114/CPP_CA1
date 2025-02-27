#include "employee.h"

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees, employeesByDepartment, employeesMatchingInput;
    map<string, int> departmentHeadcount;
    string departmentToFind;
    Employee youngest, oldest;
    string textInput;
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

    return 0;
}
