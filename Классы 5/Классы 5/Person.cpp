#include "Person.h"

Person& Person::operator =(const Person& t) {
	name = t.name;
	age = t.age;
	return *this;
}

ostream& operator<<(ostream& out, const Person& t) {
	out << "\nNAME:\t" << t.name;
	out << "\nAGE:\t" << t.age << endl;
	return out;
}

istream& operator>>(istream& in, Person& t) {
	cout << "set name: "; in >> t.name;
	cout << "set age: "; in >> t.age;
	return in;
}

void Person::show() {
	cout << "\nNAME:\t" << name; 
	cout << "\nAGE:\t" << age;  
	cout << "\n";
}