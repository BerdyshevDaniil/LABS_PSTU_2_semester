#include "Person.h"

Person& Person::operator =(const Person& t) {
	name = t.name;
	age = t.age;
	return *this;
}

ostream& operator<<(ostream& out, const Person& t) {
	return (out << "name: " << t.name << "\nage: " << t.age << endl);
}

istream& operator>>(istream& in, Person& t) {
	cout << "set name: "; in >> t.name;
	cout << "set age: "; in >> t.age;
	return in;
}