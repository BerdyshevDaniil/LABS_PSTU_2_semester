#include "paycheck.h"
#include <Windows.h>

paycheck make_paycheck() {
    string name; int bonus; double salary;
    cout << "������� ���: "; 
    getline(cin, name);
    cout << "������� �����: ";
    cin >> salary;
    cout << "������� ������ (� ���������): "; 
    cin >> bonus;
    paycheck p(name, salary, bonus); 
    return p;
}

void print_paycheck(paycheck p){
    p.show();
}

void main() {
    system("color F0");
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    //����������� ��� ���������� 
    paycheck p1;
    cout << "\tPaycheck 1\n";
    p1.show();
    //���������� � ����������� 
    paycheck p2("�������� ������ ��������", 15430.0, 10); 
    cout << "\tPaycheck 2\n";
    p2.show();
    //����������� ����������� 
    paycheck p3=p2;
    cout << "\tPaycheck 3\n";
    p3.show();
    p3.set_full_name("������ ������ ���������"); 
    p3.set_bonus(5); 
    p3.set_salary(20000.0);
    print_paycheck(p3);

    p1 = make_paycheck();
    cout << "\tPaycheck 1\n";
    p1.show();
}