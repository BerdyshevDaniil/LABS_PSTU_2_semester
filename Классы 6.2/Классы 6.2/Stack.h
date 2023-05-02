#pragma once
#include <iostream>
using namespace std;

struct Node {
	Node* next = nullptr;
	int data = 0;
};

class Stack {
private:
	int size;
	Node* head = nullptr;
public:
	Stack();
	Stack(int s);
	~Stack();
	void pushback(int data);
	void popback();
	bool empty();
	int& operator()();
	friend ostream& operator <<(ostream&, const Stack&);
};