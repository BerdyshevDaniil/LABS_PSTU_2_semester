#include "Student.h"

Student::Student(void) :Person() {
	subject = "";
	mark = 0;
}
Student::~Student(void) {}

Student::Student(string N, int A, string S, int M) :Person(N, A) {
	subject = S;
	mark = M;
}

Student::Student(const Student& S) {
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
}

Student& Student::operator =(const Student& S) {
	if (&S == this) return *this;
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
	return *this;
}

ostream& operator<<(ostream& out, const Student& S) {
	out << "\nNAME:\t" << S.name;
	out << "\nAGE:\t" << S.age;
	out << "\nSUBJ:\t" << S.subject;
	out << "\nMARK:\t" << S.mark;
	out << "\n";
	return out;
}

istream& operator>>(istream& in, Student& S) {
	cout << "set name: "; in >> S.name;
	cout << "set age: "; in >> S.age;
	cout << "set subject: "; in >> S.subject;
	cout << "set mark: "; in >> S.mark;
	return in;
}

void Student::is_bad_mark() {
	if (mark == 0) cout << "Оценка не выставлена.\n";
	else if (mark <= 2) cout << "Неудовлетворительная оценка!\n";
	else if (mark == 3) cout << "Оценка: удовлетворительно.\n";
	else if (mark == 4) cout << "Оценка: хорошо.\n";
	else if (mark == 5) cout << "Оценка: отлично.\n";
}

void Student::show() {
	cout << "\nNAME:\t" << name;
	cout << "\nAGE:\t" << age;
	cout << "\nSUBJ:\t" << subject;
	cout << "\nMARK:\t" << mark;
	cout << "\n";
}