#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object {
public:
	Object(void) {}
	~Object(void) {}
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual string Get_name() = 0;
};