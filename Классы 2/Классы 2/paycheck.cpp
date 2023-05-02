#include "paycheck.h"

paycheck::paycheck() {
	full_name = "";
	salary = 0; 
	bonus = 0;
    cout << "Конструктор по умолчанию для объекта " << this->full_name << endl;
}

paycheck::paycheck(string name, double S, int B) {
    full_name = name;
    salary = S;
    bonus = B;
    cout << "Конструктор с параметрами для объекта " << this->full_name << endl;
}

paycheck::paycheck(const paycheck& p) {
    full_name = p.full_name;
    salary = p.salary;
    bonus = p.bonus;
    cout << "Конструктор копирования для объекта " << this->full_name << endl;
}

paycheck::~paycheck() {
    cout << "Деструктор для объекта " << this->full_name << endl;
}

void paycheck::set_full_name(string name) {
    full_name = name;
}

string paycheck::get_full_name() {
    return full_name;
}

void paycheck::set_salary(double S) {
    salary = S;
}

double paycheck::get_salary() {
    return salary;
}

void paycheck::set_bonus(int B) {
    bonus = B;
}

int paycheck::get_bonus() {
    return bonus;
}

void paycheck::show() {
    cout << "ФИО: " << full_name << endl;
    cout << "Оклад: " << salary << endl;
    cout << "Премия в процентах от зарплаты: " << bonus << endl;
}