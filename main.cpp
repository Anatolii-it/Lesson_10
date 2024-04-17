#include "Lib.h";


int x = 0;

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Employee> employees;
    while (x != 0)
    {
        cout << "#------------------------------------#" << endl;
        cout << "#------------- ���� -----------------#" << endl;
        cout << "#------- ������ ���������� ----1-----#" << endl;
        cout << "#-------- ������ �� ���� -----2-----#" << endl;
        cout << "#----- ������ �� ��������� ----3-----#" << endl;
        cout << "#-- ������ �� ������� �������--4-----#" << endl;
        cout << "#------------- �����-----------0-----#" << endl;
        cout << "#------------------------------------#" << endl;
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
        cout << " ������ " << searchSurname << ":" << endl;
        for (const auto& emp : employeesBySurname) {
            printEmployee(emp);
        }


        string searchPartialSurname;
        cout << "������ ������ �������� ��� ������: ";
        cin >> searchPartialSurname;
        vector<Employee> employeesByPartialSurname = findEmployeesByPartialSurname(employees, searchPartialSurname);
        cout << " ������ " << searchPartialSurname << ":" << endl;
        for (const auto& emp : employeesByPartialSurname) {
            printEmployee(emp);
        }
    }

    

    return 0;
}