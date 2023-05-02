#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	system("color F0");
	Vector v(5); // вектор из 5 элементов 
	Person a; // объект класса Person
	cin >> a;
	Student b; //объект класса Student 
	cin >> b;
	Object* p = &a; // ставим указатель на объект класса Person 
	v.Add(p); // добавляем объект в вектор
	p = &b; // ставим указатель на объект класса Student 
	v.Add(p); // добавляем объект в вектор 
	cout << v; // вывод вектора

	return 0;
}