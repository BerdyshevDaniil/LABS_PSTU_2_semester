#include "Student.h"

void f1(Person& c) {
	c.set_age(18);
	cout << c;
}

Person f2() {
	Student s("�������", 18, "����������", 4);
	return s;
}


int main() {
	system("color F0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person a;
	cin >> a;
	cout << a;

	Person b("������", 5);
	cout << b;
	a = b;
	cout << a;

	Student c;
	cin >> c;
	cout << c;

	f1(c);
	a = f2();
	cout << a;
	return 0;
}