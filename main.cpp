#include "employee.h"

void menu();
int choiceInput();

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees, employeesMatchingInput;
    string departmentToFind;
    Employee youngest, oldest;
    string textInput;
    int avgAge, choice;

    // Read file to load employee data
    readfile(fileName, employees);
    // Make a copy of the original data
    vector<Employee> descendingSalary = employees;

    do {
        menu();
        choice = choiceInput();

        switch(choice) {
            case 1: {
                displayEmployees(employees);
                break;
            }
            case 2: {
                int id = getValidInt("\nEnter an employee ID to search for: ");
                displayEmployeeByID(employees, id);
                break;
            }
            case 3: {
                map<string, int> departmentHeadcount = countEmployeesByDepartment(employees);
                displayDepartmentCounts(departmentHeadcount);
                break;
            }
            case 4: {
                cout << "\nEnter a department and I will display the employees in it: ";
                cin >> departmentToFind;
                vector<Employee> employeesByDepartment = loadEmployeeByDepartment(departmentToFind, employees);
                displayEmployees(employeesByDepartment);
                break;
            }
            case 8: {
                cout << "\nExiting program..." << endl;
                break;
            }
        }
    } while(choice!=8);

    // cout << "\nEnter text to search for: ";
    // getline(cin, textInput);
    // employeesMatchingInput = nameMatchInput(employees, textInput);
    // displayEmployees(employeesMatchingInput);

    // sortDescendingSalary(descendingSalary);

    return 0;
}

void menu() {
    cout << "\nEmployee App Menu" << endl <<
            "1. Display all employees" << endl <<
            "2. Find employee by ID" << endl <<
            "3. Display headcount for each department" << endl <<
            "4. Display employees in a department" << endl <<
            "5. Employee age statistics" << endl <<
            "6. Find employee by name" << endl <<
            "7. Display employee data according to descending salary" << endl <<
            "8. Exit" << endl;
}

int choiceInput() {
    return getValidInt("\nEnter your choice: ", 1, 8);
}
