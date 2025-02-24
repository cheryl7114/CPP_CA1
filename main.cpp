#include <iostream>
#include <fstream>
using namespace std;

void readfile(const string &filePath) {
    ifstream fin(filePath);

    if (fin) {
        while (!fin.eof()) {
            string line;
            getline(fin, line);
            cout << line << endl;
        }
        fin.close();
    } else {
        cout << "File could not be opened" << endl;
    }
}

int main () {
    const string fileName = "employees.csv";
    readfile(fileName);
    cout << "Hello World!" << endl;
}