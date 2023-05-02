#include "Vector.h"

Vector::Vector() {
	beg = nullptr;
	size = 0;
	cur = 0;
}

Vector::~Vector(void) {
	if (beg != 0) delete[] beg;
	beg = 0;
}

Vector::Vector(int n) {
	beg = new Object* [n]; 
	cur = 0;
	size = n;
}

void Vector::Get_Name() {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		cout << (*p)->Get_name() << endl;
		p++;
	}
}

void Vector::Add() {
	Object* p;
	//выбор из объектов двух возможных классов 
	cout << "1.Print" << endl;
	cout << "2.Magazin" << endl;
	int y;
	cin >> y;
	if (y == 1) { //добавление объекта класса Print
		Print* a = new (Print);
		a->Input();//ввод значений атрибутов 
		p = a;
		if (cur < size) {
			beg[cur] = p;//добавление в вектор 
			cur++;
		}
	}
	else if (y == 2) { //добавление объекта класса Magazin 
		Magazin* b = new Magazin;
		b->Input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

void Vector::Show() {
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;    //указатель на указатель типа Object 
	for (int i = 0;i < cur;i++) {
		(*p)->Show();   //вызов метода Show() (позднее связывание) 
		p++;  //передвигаем указатель на следующий объект
	}
}

int Vector::operator ()() {
	return cur;
}

void Vector::Del() {
	if (cur == 0) return; //пустой 
	cur--;
}