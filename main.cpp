#include "Lib.h";


int x = 0;

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Employee> employees;
    while (x != 0)
    {
        cout << "#------------------------------------#" << endl;
        cout << "#------------- Меню -----------------#" << endl;
        cout << "#------- Ввести сотрудника ----1-----#" << endl;
        cout << "#-------- Знайти за віком -----2-----#" << endl;
        cout << "#----- Знайти за Призвищем ----3-----#" << endl;
        cout << "#-- Знайти за часткою Призвищ--4-----#" << endl;
        cout << "#------------- Вихід-----------0-----#" << endl;
        cout << "#------------------------------------#" << endl;
        employees.push_back(enterEmployeeData());

        saveEmployeesToFile(employees, "employees.txt");

        int searchAge;
        cout << "Введіть скільки років для пошуку: ";
        cin >> searchAge;
        vector<Employee> employeesByAge = findEmployeesByAge(employees, searchAge);
        cout << "Вік " << searchAge << ":" << endl;
        for (const auto& emp : employeesByAge) {
            printEmployee(emp);
        }


        string searchSurname;
        cout << "Введить повне призвище для пошуку: ";
        cin >> searchSurname;
        vector<Employee> employeesBySurname = findEmployeesBySurname(employees, searchSurname);
        cout << " Шукали " << searchSurname << ":" << endl;
        for (const auto& emp : employeesBySurname) {
            printEmployee(emp);
        }


        string searchPartialSurname;
        cout << "Введіть частку призвища для пошуку: ";
        cin >> searchPartialSurname;
        vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
        cout << " Шукали " << searchPartialSurname << ":" << endl;
        for (const auto& emp : employeesByPartialSurname) {
            printEmployee(emp);
        }
    }

    

    return 0;
}