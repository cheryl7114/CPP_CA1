#include "employee.h"

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees;

    readfile(fileName, employees);
    displayEmployees(employees);

    return 0;
}
