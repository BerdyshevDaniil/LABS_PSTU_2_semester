#pragma once
#include "Magazin.h"
#include "Object.h"

class Vector {
public:
	Vector();
	Vector(int);
	~Vector(void);

	void Add();
	void Del();
	void Show();
	void Get_Name();
	int operator()();
protected:
	Object** beg;
	int size;
	int cur;
};