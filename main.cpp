#include "employee.h"

void menu();
int choiceInput();

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees, employeesByDepartment, employeesMatchingInput, descendingSalary;
    map<string, int> departmentHeadcount;
    string departmentToFind;
    Employee youngest, oldest;
    string textInput;
    int id, avgAge, choice;

    // Read file to load employee data
    readfile(fileName, employees);
    // Make a copy of the original data
    descendingSalary = employees;

    do {
        menu();
        choice = choiceInput();
        cout << "Your choice: " << choice << endl;
    } while(choice!=8);

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

int choiceInput() {
    int choice;
    // https://www.geeksforgeeks.org/how-to-validate-user-input-in-cpp/
    while(true) {
        cout << "Enter your choice: ";

        if (cin >> choice && choice >= 1 && choice <= 8) {
            return choice;
        } else {
            cout << "Invalid input. Please enter a number between 1 and 8: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
}