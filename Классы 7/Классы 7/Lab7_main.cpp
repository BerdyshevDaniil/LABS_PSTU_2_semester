#include "List.h"
#include "Pair.h"
#include <Windows.h>

int main() {
	system("color F0");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	Pair p1(2, 2.5);
	List<Pair> a(3, p1);
	cout << a << endl;
	cout << "������ �������: " << a.front() << endl;
	cin >> a;
	cout << a << endl;
	List<Pair> b(a); 
	cout << "������ ��� ����������\n";
	cout << b << endl;
	List<Pair> c = a * b;
	cout << "a * b\n" << c << endl;
	Pair num;
	cout << "������� ����� ��������:\n"; cin >> num;
	b.pushback(num);
	b.popfront();
	for (Iterator<Pair> iter = b.first(); iter != b.last(); ++iter)
		cout << *iter << '\n';
	return 0;
}