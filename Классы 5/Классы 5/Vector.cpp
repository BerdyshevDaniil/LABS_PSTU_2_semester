#include "Vector.h"

Vector::Vector(void) {
beg = 0; size = 0; cur = 0;
} //конструктор без параметров 

Vector::~Vector(void) {
	if (beg != 0)delete[] beg; beg = 0;
} //деструктор

Vector::Vector(int n){
	beg = new Object * [n]; cur = 0;
	size = n; 
} //конструктор с параметрами 

void Vector::Add(Object *p) {
	if (cur < size)
		beg[cur] = p; cur++;
} //добавление объекта, на который указывает указатель p в вектор 

ostream& operator<<(ostream& out, const Vector& v) {
	if (v.size == 0) out << "Empty" << endl;
	Object** p = v.beg;//указатель на указатель типа Object 
	for (int i = 0;i < v.cur;i++) {
		(*p)->show();  //вызов метода show() (позднее связывание) 
		p++; //передвигаем указатель на следующий объект
	}
	return out;
} //операция вывода
