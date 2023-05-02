#include "paycheck.h"
#include <Windows.h>

paycheck make_paycheck() {
    string name; int bonus; double salary;
    cout << "Введите имя: "; 
    getline(cin, name);
    cout << "Введите оклад: ";
    cin >> salary;
    cout << "Введите премию (в процентах): "; 
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
    //конструктор без параметров 
    paycheck p1;
    cout << "\tPaycheck 1\n";
    p1.show();
    //коструктор с параметрами 
    paycheck p2("Бердышев Даниил Игоревич", 15430.0, 10); 
    cout << "\tPaycheck 2\n";
    p2.show();
    //конструктор копирования 
    paycheck p3=p2;
    cout << "\tPaycheck 3\n";
    p3.show();
    p3.set_full_name("Веснин Кирилл Андреевич"); 
    p3.set_bonus(5); 
    p3.set_salary(20000.0);
    print_paycheck(p3);

    p1 = make_paycheck();
    cout << "\tPaycheck 1\n";
    p1.show();
}