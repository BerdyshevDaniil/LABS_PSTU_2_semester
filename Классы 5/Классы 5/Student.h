#pragma once
#include "Person.h"
class Student :
    public Person {
protected:
	string subject;
	int mark;
public:
	Student(void);
	Student(string, int, string, int);
	Student(const Student&);
	~Student(void);
	void set_subject(string S) { subject = S; }
	void set_mark(int M) { mark = M; }
	string get_subject() { return subject; }
	int get_mark() { return mark; }
	void show();
	Student& operator=(const Student&);
	friend istream& operator>>(istream& in, Student&);
	friend ostream& operator<<(ostream& out, const Student&);
	void is_bad_mark();
};

