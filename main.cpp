#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Employee {
    string surname;
    string name;
    int age;
};

Employee enterEmployeeData() {
    Employee emp;
    cout << "Enter surname: ";
    cin >> emp.surname;
    cout << "Enter name: ";
    cin >> emp.name;
    cout << "Enter age: ";
    cin >> emp.age;
    return emp;
}

void printEmployee(const Employee& emp) {
    cout << "Surname: " << emp.surname << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Age: " << emp.age << endl;
}

vector<Employee> findEmployeesByAge(const vector<Employee>& employees, int age) {
    vector<Employee> foundEmployees;
    for (const auto& emp : employees) {
        if (emp.age == age) {
            foundEmployees.push_back(emp);
        }
    }
    return foundEmployees;
}

vector<Employee> findEmployeesBySurname(const vector<Employee>& employees, const string& surname) {
    vector<Employee> foundEmployees;
    for (const auto& emp : employees) {
        if (emp.surname == surname) {
            foundEmployees.push_back(emp);
        }
    }
    return foundEmployees;
}

vector<Employee> findEmployeesByPartialSurname(const vector<Employee>& employees, const string& partialSurname) {
    vector<Employee> foundEmployees;
    for (const auto& emp : employees) {
        if (emp.surname.find(partialSurname) != string::npos) {
            foundEmployees.push_back(emp);
        }
    }
    return foundEmployees;
}

void saveEmployeesToFile(const vector<Employee>& employees, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& emp : employees) {
        outputFile << emp.surname << " " << emp.name << " " << emp.age << endl;
    }

    outputFile.close();
    cout << "Employee data saved to file." << endl;
}

vector<Employee> loadEmployeesFromFile(const string& filename) {
    vector<Employee> employees;
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file for reading." << endl;
        return employees;
    }

    Employee emp;
    while (inputFile >> emp.surname >> emp.name >> emp.age) {
        employees.push_back(emp);
    }

    inputFile.close();
    cout << "Employee data loaded from file." << endl;
    return employees;
}

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Enter new employee data" << endl;
    cout << "2. Save employees to file" << endl;
    cout << "3. Load employees from file" << endl;
    cout << "4. Find employees by age" << endl;
    cout << "5. Find employees by surname" << endl;
    cout << "6. Find employees by partial surname" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Employee> employees = loadEmployeesFromFile("employees.txt");

    int choice = 0;
    while (choice != 7) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            employees.push_back(enterEmployeeData());
            break;
        case 2:
            saveEmployeesToFile(employees, "employees.txt");
            break;
        case 3:
            employees = loadEmployeesFromFile("employees.txt");
            break;
        case 4:
            int searchAge;
            cout << "Enter age to search: ";
            cin >> searchAge;
            vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
            cout << "Employees aged " << searchAge << ":" << endl;
            for (const auto& emp : employeesByAge) {
                printEmployee(emp);
            }
            break;
        case 5:
            string searchSurname;
            cout << "Enter full surname to search: ";
            cin >> searchSurname;
            vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
            cout << "Employees with surname " << searchSurname << ":" << endl;
            for (const auto& emp : employeesBySurname) {
                printEmployee(emp);
            }
            break;
        case 6:
            string searchPartialSurname;
            cout << "Enter partial surname to search: ";
            cin >> searchPartialSurname;
            vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
            cout << "Employees with partial surname " << searchPartialSurname << ":" << endl;
            for (const auto& emp : employeesByPartialSurname) {
                printEmployee(emp);
            }
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
        }
    }

    return 0;
}
