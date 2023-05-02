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
	out << "\nNAME : " << S.name;
	out << "\nAGE : " << S.age;
	out << "\nSUBJECT : " << S.subject;
	out << "\nMARK : " << S.mark;
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
	if (mark == 0) cout << "������ �� ����������.\n";
	else if (mark <= 2) cout << "�������������������� ������!\n";
	else if (mark == 3) cout << "������: �����������������.\n";
	else if (mark == 4) cout << "������: ������.\n";
	else if (mark == 5) cout << "������: �������.\n";
}