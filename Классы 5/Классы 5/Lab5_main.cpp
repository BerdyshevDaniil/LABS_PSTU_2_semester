#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	system("color F0");
	Vector v(5); // ������ �� 5 ��������� 
	Person a; // ������ ������ Person
	cin >> a;
	Student b; //������ ������ Student 
	cin >> b;
	Object* p = &a; // ������ ��������� �� ������ ������ Person 
	v.Add(p); // ��������� ������ � ������
	p = &b; // ������ ��������� �� ������ ������ Student 
	v.Add(p); // ��������� ������ � ������ 
	cout << v; // ����� �������

	return 0;
}