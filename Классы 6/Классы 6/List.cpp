#include "List.h"
#include <iostream>
using namespace std;

//конструктор с параметрами
List::List(int s, int k) {
	size = s;
	Node* node = new Node;
	node->data = k;
	head = node;
	tail = node;
	for (int i = 0; i < size - 1; i++) {
		Node* node = new Node;
		node->data = rand() % 10;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = nullptr;
	beg.elem = head;
	end.elem = tail->next;
}

List::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}
//конструктор копирования
List::List(const List& a) {
	Node* node = a.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	beg = a.beg;
	end = a.end;
}

//деструктор
List::~List() {
	Node* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}

void List::pushback(int data) {
	Node* newNode = new Node;
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

void List::pushfront(int data) {
	Node* newNode = new Node;
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

int List::front() { return head->data; }
int List::back() { return tail->data; }

void List::popback() {
	if (head != nullptr) {
		Node* curr = tail;
		tail = curr->prev;
		delete curr;
		tail->next = nullptr;
		size--;
		end.elem = tail->next;
	}
}

void List::popfront() {
	if (head != nullptr) {
		Node* curr = head;
		head = curr->next;
		delete curr;
		head->prev = nullptr;
		size--;
		beg.elem = head;
	}
}

bool List::empty() { return size == 0; }

//операция присваивания
List& List::operator=(const List& a) {
	if (this == &a) return *this;
	Node* node = head;
	while (node != nullptr) {
		head = node->next;
		delete node;
		node = head;
		size--;
	}
	Node* curr = a.head;
	while (curr != nullptr) {
		pushback(curr->data);
		curr = curr->next;
	}
	beg = a.beg;
	end = a.end;
	return *this;
}
//операция доступа по индексу
int& List::operator[](int index) {
	if (index < size && index >= 0) {
		Node* curr = head;
		for (int i = 0; i < index; i++) curr = curr->next;
		return curr->data;
	}
	else {
		cout << "Wrond index!" << endl;
		exit(222);
	}
}

int& List::operator ()() {
	return size;
}
List List::operator*(List& a) {
	int tempsize;
	if (size > a.size) tempsize = a.size;
	else tempsize = size;
	List templist(tempsize);
	for (int i = 0; i < tempsize; i++) templist[i] = (*this)[i] * a[i];
	return templist;

}

//операции для ввода-вывода
ostream& operator<<(ostream& out, const List& a) {
	Node* curr = a.head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
	return out;
}
istream& operator>>(istream& in, const List& a) {
	Node* curr = a.head;
	while (curr != nullptr) {
		in >> curr->data;
		curr = curr->next;
	}
	return in;
}