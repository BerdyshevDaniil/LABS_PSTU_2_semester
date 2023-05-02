#include "Print.h"

Print::~Print(void){}

Print::Print(void) {
	name = "";
	author = "";
}

Print::Print(string N, string A) {
	name = N;
	author = A;
}

Print::Print(const Print& P) {
	name = P.name;
	author = P.author;
}


void Print::Show() {
	cout << "\nName: " << name;
	cout << "\nAuthor " << author << endl;
}

void Print::Input() {
	getline(cin, name);
	cout << "Enter name: "; getline(cin, name);
	cout << "Enter author: "; getline(cin, author);
}

Print& Print::operator=(const Print& p) {
	if (&p == this) return *this; 
	name = p.name; 
	author = p.author;
	return *this;
}