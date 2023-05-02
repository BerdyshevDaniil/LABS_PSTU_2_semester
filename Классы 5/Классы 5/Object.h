#pragma once
class Object {
public: 
	Object(void) {};
	~Object(void) {};
	virtual void show() = 0; //чисто виртуальная функция
};