#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Person {
public:
	Person(void) { name = ""; age = 0; };
	Person(string N, int A) { name = N; age = A; }
	Person(const Person& t) { name = t.name; age = t.age; }
	virtual ~Person(void) {};
	string get_name() { return name; }
	int get_age() { return age; }
	void set_name(string N) { name = N; }
	void set_age(int A) { age = A; }
	Person& operator = (const Person& t);
	friend istream& operator>>(istream& in, Person& t);
	friend ostream& operator<<(ostream& out, const Person& t);
protected:
	string name;
	int age;
};