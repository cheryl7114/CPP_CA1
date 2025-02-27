#include "employee.h"

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees, employeesByDepartment, employeesMatchingInput, descendingSalary;
    map<string, int> departmentHeadcount;
    string departmentToFind;
    Employee youngest, oldest;
    string textInput;
    int id, avgAge;

    readfile(fileName, employees);
    descendingSalary = employees;
    // cout << "Enter an employee ID to search for: ";
    // cin >> id;
    // displayEmployeeByID(employees, 98);

    // // Display department counts
    // countEmployeesByDepartment(employees, departmentHeadcount);
    // displayDepartmentCounts(departmentHeadcount);

    // cout << "\nEnter a department and I will display the employees in it: ";
    // cin >> departmentToFind;
    // loadEmployeeByDepartment(departmentToFind, employees, employeesByDepartment);

    // cout << "\nEnter text to search for: ";
    // getline(cin, textInput);
    // employeesMatchingInput = nameMatchInput(employees, textInput);
    // displayEmployees(employeesMatchingInput);

    sortDescendingSalary(descendingSalary);

    return 0;
}

void menu() {
    cout << "Employee App Menu" << endl <<
            "1. Display all employees" << endl <<
            "2. Find employee by ID" << endl <<
            "3. Display headcount for each department" << endl <<
            "4. Display employees in a department" << endl <<
            "5. Employee age statistics" << endl <<
            "6. Search for an employee" << endl <<
            "7. Display employee data according to descending salary" << endl <<
            "8. Exit" << endl;
}
