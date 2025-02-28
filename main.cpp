#include "employee.h"

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

void handleSearchByID(const vector<Employee>& employees) {
    int id = getValidInt("\nEnter an employee ID to search for: ");
    displayEmployeeByID(employees, id);
}

void handleDepartmentHeadcount(const vector<Employee>& employees) {
    map<string, int> departmentHeadcount = countEmployeesByDepartment(employees);
    displayDepartmentCounts(departmentHeadcount);
}

void handleSearchByDepartment(const vector<Employee>& employees) {
    string departmentToFind;
    cout << "\nEnter a department and I will display the employees in it: ";
    cin >> departmentToFind;
    vector<Employee> employeesByDepartment = loadEmployeeByDepartment(departmentToFind, employees);
    displayEmployees(employeesByDepartment);
}

void handleAgeStatistics(const vector<Employee>& employees, Employee& youngest, Employee& oldest) {
    int avgAge = findAgeStatistics(employees, youngest, oldest);
    cout << "\nAverage age: " << avgAge << endl;
    cout << "\nYoungest Employee";
    displayEmployeeByID(employees, youngest.id);
    cout << "\nOldest Employee";
    displayEmployeeByID(employees, oldest.id);
}

void handleSearchByName(const vector<Employee>& employees) {
    cout << "\nEnter name to search for: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear previous input like Java's scanner.nextLine()
    string textInput;
    getline(cin, textInput);
    vector<Employee> employeesMatchingInput = nameMatchInput(employees, textInput);
    displayEmployees(employeesMatchingInput);
}

void handleSortDescendingSalary(vector<Employee>& descendingSalary) {
    sortDescendingSalary(descendingSalary);
    cout << "\nEmployees sorted by descending salary.\n";
}

int main() {
    const string fileName = "/Users/cherylkong/Desktop/CPP_CA1/employees.csv";
    vector<Employee> employees;
    Employee youngest, oldest;
    int choice;

    // Read file to load employee data
    readfile(fileName, employees);

    // Make a copy of the original data
    vector<Employee> descendingSalary = employees;

    do {
        menu();
        choice = getValidInt("\nEnter your choice: ", 1, 8);

        switch (choice) {
            case 1: displayEmployees(employees); break;
            case 2: handleSearchByID(employees); break;
            case 3: handleDepartmentHeadcount(employees); break;
            case 4: handleSearchByDepartment(employees); break;
            case 5: handleAgeStatistics(employees, youngest, oldest); break;
            case 6: handleSearchByName(employees); break;
            case 7: handleSortDescendingSalary(descendingSalary); break;
            case 8: cout << "\nExiting program..." << endl; break;
        }
    } while (choice != 8);

    return 0;
}
