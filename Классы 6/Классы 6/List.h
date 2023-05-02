#pragma once
#include <iostream>
using namespace std;

struct Node {
	Node* prev = nullptr, * next = nullptr;
	int data = 0;
};

class Iterator {
	friend class List;//дружественный класс
	Node* elem;
public:
	Iterator() { elem = nullptr; }//конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	//перегруженные операции сравнения
	Iterator& operator=(const Iterator& a) {
		elem = a.elem;
		return *this;
	}
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	//перегруженная операция инкремент
	Iterator& operator++() {
		elem = elem->next;
		return *this;
	};
	//перегруженная операция декремент
	Iterator& operator--() {
		elem = elem->prev;
		return *this;
	}
	Iterator& operator+(const int& a) {
		for (int i = 0; i < a; i++) elem = elem->next;
		return *this;
	}
	Iterator& operator-(const int& a) {
		for (int i = 0; i < a; i++) elem = elem->prev;
		return *this;
	}
	//перегруженная операция разыменования
	int& operator *() const { return elem->data; }
};

class List {
private:
	int size;
	Node* head = nullptr, * tail = nullptr;
	Iterator beg, end;
public:
	List();
	List(int s, int k = 0);
	List(const List&);
	~List();
	int front();
	int back();
	void pushback(int data);
	void pushfront(int data);
	void popback();
	void popfront();
	bool empty();
	List& operator=(const List&);
	int& operator[](int index);
	int& operator()();
	List operator*(List&);
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream&, const List&);
	Iterator first() { return beg; }
	Iterator last() { return end; }
};