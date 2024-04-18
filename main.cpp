#include "Lib.h"

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
    cout << "#    ��������: " << emp.surname << endl;
    cout << "#        ��'�: " << emp.name << endl;
    cout << "#       ����: " << emp.age << endl;
    cout << "#---------------------------------#" << endl;
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
    cout << " ��������� � ���� employees.txt " << endl;
}

void loadEmployeesFromFile(vector<Employee>& employees, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    employees.clear();

    Employee emp;
    while (inputFile >> emp.surname >> emp.name >> emp.age) {
        employees.push_back(emp);
    }

    inputFile.close();
    cout << " ������ ������� � employees.txt" << endl;
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
        cout << "#                ������� � �����     - 1      #" << endl;
        cout << "#          ������� ������ ���������� - 2      #" << endl;
        cout << "#               ���������� � ����    - 3      #" << endl;
        cout << "#                ����� �� ����      - 4      #" << endl;
        cout << "#              ����� �� ��������    - 5      #" << endl;
        cout << "#           ����� �� ������� �������- 6      #" << endl;
        cout << "#                    �����           - 0      #" << endl;
        cout << "#---------------------------------------------#" << endl;
        cin >> x;
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
            vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
            for (const auto& emp : employeesByAge) {
                printEmployee(emp);
            }
        }
        if (x == 5) {
            string searchSurname;
            cout << "������� �������� ��� ������: ";
            cin >> searchSurname;
            vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
            for (const auto& emp : employeesBySurname) {
                printEmployee(emp);
            }
        }
        if (x == 6) {
            string searchPartialSurname;
            cout << "������ ������ �������� ��� ������: ";
            cin >> searchPartialSurname;
            vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
            cout << "�������� " << searchPartialSurname << ":" << endl;
            for (const auto& emp : employeesByPartialSurname) {
                printEmployee(emp);
            }
        }

        if (x == 0) {
            cout << "�� ���������." << endl;
            return 0;
        }
        cout << "�������� ����-��� ������ ��� �����������..." << endl;
        system("pause");
    }


    return 0;
}