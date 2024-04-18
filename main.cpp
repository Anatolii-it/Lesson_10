#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

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
    cout << "#---------------------------------#" << endl;
    cout << "     ��������: " << emp.surname << endl;
    cout << "         ��'�: " << emp.name << endl;
    cout << "        ����: " << emp.age << endl;
   
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
        cerr << "��������� ��������." << endl;
        return;
    }

    for (const auto& emp : employees) {
        outputFile << emp.surname << " " << emp.name << " " << emp.age << endl;
    }

    outputFile.close();
    cout << "#---------------------------------#" << endl;
    cout << " ��������� � ���� employees.txt " << endl;
}

void loadEmployeesFromFile(vector<Employee>& employees, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "#---------------------------------#" << endl;
        cerr << "Error opening file for reading." << endl;
        return;
    }

    employees.clear();

    Employee emp;
    while (inputFile >> emp.surname >> emp.name >> emp.age) {
        employees.push_back(emp);
    }

    inputFile.close();
    cout << "#---------------------------------#" << endl;
    cout << " ������ ������� � employees.txt" << endl;
}

void editEmployee(vector<Employee>& employees, const string& surname) {
    for (auto& emp : employees) {
        if (emp.surname == surname) {
            cout << "������ ��� ��� ��� ���������� '" << surname << "':" << endl;
            emp = enterEmployeeData();
            cout << "��� ��� ���������� ��������." << endl;
            return;
        }
    }
    cout << "���������� � �������� '" << surname << "' �� ��������." << endl;
}

//��������� ����������
void deleteEmployee(vector<Employee>& employees, const string& surname) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->surname == surname) {
            employees.erase(it);
            cout << "���������� � �������� '" << surname << "' ��������." << endl;
            return;
        }
    }
    cout << "���������� � �������� '" << surname << "' �� ��������." << endl;
}

int x = -1;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Employee> employees;

    while (x != 0) {
        system("cls");
        cout << "#---------------------------------------------#" << endl;
        cout << "#                    ����                     #" << endl;
        cout << "#                \033[1;31m������� � �����     - 1\033[0m      #" << endl;
        cout << "#          ������� ������ ���������� - 2      #" << endl;
        cout << "#                \033[1;32m���������� � ����   - 3\033[0m      #" <<endl;
        cout << "#                \033[1;33m����� �� ����      - 4 \033[0m     #" <<endl;
        cout << "#              ����� �� ��������    - 5      #" << endl;
        cout << "#           \033[1;36m����� �� ������� �������- 6\033[0m      #" <<endl;
        cout << "#           ����������� �� �������� - 7      #" << endl;
        cout << "#           ��������� �� ��������   - 8      #" << endl;
        cout << "#                    �����           - 0      #" << endl;
        cout << "#---------------------------------------------#" << endl;
        cout << "                           �� ���� - ";
        if (!(cin >> x)) {
            cout << "�������: ������� �� �����!" << endl;
            cin.clear();
            
        }

        if (x == 1) {
            loadEmployeesFromFile(employees, "employees.txt");
        }
        if (x == 2) {
            employees.push_back(enterEmployeeData());
        }
        if (x == 3) {
            saveEmployeesToFile(employees, "employees.txt");
        }
        if (x == 4) {
            int searchAge;
            cout << "������ ��: ";
            cin >> searchAge;
            system("cls");
            vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
            for (const auto& emp : employeesByAge) {
                printEmployee(emp);
            }
        }
        if (x == 5) {
            string searchSurname;
            cout << "������� �������� ��� ������: ";
            cin >> searchSurname;
            system("cls");
            vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
            for (const auto& emp : employeesBySurname) {
                printEmployee(emp);
            }
        }
        if (x == 6) {
            string searchPartialSurname;
            cout << "������ ������ �������� ��� ������: ";
            cin >> searchPartialSurname;
            system("cls");
            vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
            cout << endl;
            for (const auto& emp : employeesByPartialSurname) {
                printEmployee(emp);
            }
        }
        if (x == 7) { //��� ����������� ����������
            string editSurname;
            cout << "������ ������� ���������� ��� �����������: ";
            cin >> editSurname;
            system("cls");
            editEmployee(employees, editSurname);
        }
        if (x == 8) { //  ��������� ����������
            string deleteSurname;
            cout << "������ ������� ���������� ��� ���������: ";
            cin >> deleteSurname;
            system("cls");
            deleteEmployee(employees, deleteSurname);
        }

        if (x == 0) {
            cout << "�� ���������." << endl;
            saveEmployeesToFile(employees, "employees.txt");
            return 0;
        }
        if (x > 8) {
            cout << "������ ������ ���� �� ����"<< endl;
        }
        cout << "#---------------------------------#" << endl;
        cout << "�������� ����-��� ������ ��� �����������..." << endl;
        
        _getch();
    }
    

    return 0;
}