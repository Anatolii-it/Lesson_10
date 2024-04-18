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
    cout << "Введіть призвіще: ";
    cin >> emp.surname;
    cout << "Введіть ім'я: ";
    cin >> emp.name;
    cout << "Повних років: ";
    cin >> emp.age;
    return emp;
}

void printEmployee(const Employee& emp) {
    cout << "Призвище: " << emp.surname << endl;
    cout << "Ім'я: " << emp.name << endl;
    cout << "Років: " << emp.age << endl;
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
    cout << "Employee data loaded from file." << endl;
}

int x = -1;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Employee> employees;

    while (x != 0) {
        system("cls");
        cout << "#---------------------------------------------#" << endl;
        cout << "#                    Меню                     #" << endl;
        cout << "#                Зчитати з файлу     - 1      #" << endl;
        cout << "#          Занести нового працівника - 2      #" << endl;
        cout << "#               Збереження у файл    - 3      #" << endl;
        cout << "#                Пошук за датой      - 4      #" << endl;
        cout << "#              Пошук за Прізвищем    - 5      #" << endl;
        cout << "#           Пошук за часткою Прізвища- 6      #" << endl;
        cout << "#                    Вихід           - 0      #" << endl;
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
            cout << "Введіть скільки років для пошуку: ";
            cin >> searchAge;
            vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
            cout << "Вік " << searchAge << ":" << endl;
            for (const auto& emp : employeesByAge) {
                printEmployee(emp);
            }
        }
        if (x == 5) {
            string searchSurname;
            cout << "Введить повне призвище для пошуку: ";
            cin >> searchSurname;
            vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
            cout << "Призвище " << searchSurname << ":" << endl;
            for (const auto& emp : employeesBySurname) {
                printEmployee(emp);
            }
        }
        if (x == 6) {
            string searchPartialSurname;
            cout << "Введіть частку призвища для пошуку: ";
            cin >> searchPartialSurname;
            vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
            cout << "Призвище " << searchPartialSurname << ":" << endl;
            for (const auto& emp : employeesByPartialSurname) {
                printEmployee(emp);
            }
        }

        if (x == 0) {
            cout << "До побачення." << endl;
            return 0;
        }
        system("pause");
    }
    

    return 0;
}