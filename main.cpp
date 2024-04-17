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
    cout << "������ �������: ";
    cin >> emp.surname;
    cout << "������ ��'�: ";
    cin >> emp.name;
    cout << "������ ����: ";
    cin >> emp.age;
    return emp;
}

void printEmployee(const Employee& emp) {
    cout << "��������: " << emp.surname << endl;
    cout << "��'�: " << emp.name << endl;
    cout << "����: " << emp.age << endl;
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

int main() {
    //system("chcp 1251>nul");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Employee> employees;

    
    employees.push_back(enterEmployeeData());

    saveEmployeesToFile(employees, "employees.txt");

    int searchAge;
    cout << "������ ������ ���� ��� ������: ";
    cin >> searchAge;
    vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
    cout << "³� " << searchAge << ":" << endl;
    for (const auto& emp : employeesByAge) {
        printEmployee(emp);
    }

    
    string searchSurname;
    cout << "������� ����� �������� ��� ������: ";
    cin >> searchSurname;
    vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
    cout << "�������� " << searchSurname << ":" << endl;
    for (const auto& emp : employeesBySurname) {
        printEmployee(emp);
    }

    
    string searchPartialSurname;
    cout << "������ ������ �������� ��� ������: ";
    cin >> searchPartialSurname;
    vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
    cout << "�������� " << searchPartialSurname << ":" << endl;
    for (const auto& emp : employeesByPartialSurname) {
        printEmployee(emp);
    }

    return 0;
}