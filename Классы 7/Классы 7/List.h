#pragma once
#include <iostream>
using namespace std;
#ifndef LIST_H 
#define LIST_H 

template <class T>
class List;

template <class T>
struct Node {
	Node<T>* prev = nullptr, * next = nullptr;
	T data;
};

template <class T>
class Iterator {
	template <class T>
	friend class List;
	Node<T>* elem;
public:
	Iterator() { elem = nullptr; }
	Iterator(const Iterator<T>& it) { elem = it.elem; }
	//перегруженные операции сравнени€
	Iterator<T>& operator=(const Iterator<T>& a) {
		elem = a.elem;
		return *this;
	}
	bool operator==(const Iterator<T>& it) { return elem == it.elem; }
	bool operator!=(const Iterator<T>& it) { return elem != it.elem; };
	//перегруженна€ операци€ инкремент
	Iterator<T>& operator++() {
		elem = elem->next;
		return *this;
	}
	//перегруженна€ операци€ декремент
	Iterator<T>& operator--() {
		elem = elem->prev;
		return *this;
	}
	Iterator<T>& operator+(const int& a) {
		for (int i = 0; i < a; i++) elem = elem->next;
		return *this;
	}
	Iterator<T>& operator-(const int& a) {
		for (int i = 0; i < a; i++) elem = elem->prev;
		return *this;
	}
	//перегруженна€ операци€ разыменовани€
	T& operator *() const { return elem->data; }
};

template <class T>
class List {
public:
	T front();
	T back();
	void pushback(T data);
	void pushfront(T data);
	void popback();
	void popfront();
	bool empty();
	List<T>& operator=(const List<T>& a);
	T& operator[](int index);
	int& operator()();
	List<T> operator*(List<T>&);
	friend ostream& operator<< <T>(ostream&, const List<T>&);
	friend istream& operator>> <T>(istream&, const List<T>&);
	Iterator<T> first() { return beg; }
	Iterator<T> last() { return end; }
	List();
	List(int s, T k);
	List(const List<T>&);
	~List();
protected:
	int size;
	Node<T>* head = nullptr, * tail = nullptr;
	Iterator<T> beg, end;
};

template <class T>
List<T>::List(int s, T k) {
	size = s;
	Node<T>* node = new Node<T>;
	node->data = k;
	head = node;
	tail = node;
	for (int i = 0; i < size - 1; i++) {
		Node<T>* node = new Node<T>;
		node->data = k;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = nullptr;
	beg.elem = head;
	end.elem = tail->next;
}

template <class T>
List<T>::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
List<T>::List(const List<T>& a) {
	Node<T>* node = a.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	beg = a.beg;
	end = a.end;
}

template <class T>
List<T>::~List() {
	Node<T>* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}

template <class T>
void List<T>::pushback(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
		end.elem = tail->next;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
		end.elem = tail->next;
	}
}

template <class T>
void List<T>::pushfront(T data) {
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
		beg.elem = head;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		size++;
		beg.elem = head;
	}
}

template <class T>
T List<T>::front() { return head->data; }
template <class T>
T List<T>::back() { return tail->data; }

template <class T>
void List<T>::popback() {
	if (head != nullptr) {
		Node<T>* curr = tail;
		tail = curr->prev;
		delete curr;
		tail->next = nullptr;
		size--;
		end.elem = tail->next;
	}
}

template <class T>
void List<T>::popfront() {
	if (head != nullptr) {
		Node<T>* curr = head;
		head = curr->next;
		delete curr;
		head->prev = nullptr;
		size--;
		beg.elem = head;
	}
}

template <class T>
bool List<T>::empty() { return size == 0; }

template <class T>
List<T>& List<T>::operator=(const List<T>& a) {
	if (this == &a) return *this;
	Node<T>* node = head;
	while (node != nullptr) {
		head = node->next;
		delete node;
		node = head;
		size--;
	}
	Node<T>* curr = a.head;
	while (curr != nullptr) {
		pushback(curr->data);
		curr = curr->next;
	}
	beg = a.beg;
	end = a.end;
	return *this;
}

template <class T>
T& List<T>::operator[](int index) {
	if (index < size && index >= 0) {
		Node<T>* curr = head;
		for (int i = 0; i < index; i++) curr = curr->next;
		return curr->data;
	}
	else {
		cout << "Wrond index!" << endl;
		exit(222);
	}
}

template <class T>
int& List<T>::operator ()() {
	return size;
}

template <class T>
List<T> List<T>::operator*(List<T>& a) {
	int tempsize;
	if (size > a.size) tempsize = a.size;
	else tempsize = size;
	List<T> templist(tempsize, a[0]);
	for (int i = 0; i < tempsize; i++) 
		templist[i] = (*this)[i] * a[i];
	return templist;
}

template <class T>
ostream& operator<< (ostream& out, const List<T>& a) {
	Node<T>* curr = a.head;
	out << "—писок\n";
	while (curr != nullptr) {
		out << curr->data << '\n';
		curr = curr->next;
	}
	return out;
}

template <class T>
istream& operator>>(istream& in, const List<T>& a) {
	Node<T>* curr = a.head;
	int i = 1;
	cout << "\t¬ведите новые значени€ дл€ списка:\n";
	while (curr != nullptr) {
		cout << "«начение " << i++ << ":\n";
		in >> curr->data;
		curr = curr->next;
	}
	return in;
}
#endif