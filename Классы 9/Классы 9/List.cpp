#include "List.h"
#include "Error.h"
#include <iostream>
using namespace std;

List::List(int s) {
	size = s;
	Node* node = new Node;
	node->data = rand() % 10;
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
}

List::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

List::List(const List& a) {
	Node* node = a.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
}

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
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
	}
}

void List::pushfront(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		size++;
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
	}
}

void List::popfront() {
	if (head != nullptr) {
		Node* curr = head;
		head = curr->next;
		delete curr;
		head->prev = nullptr;
		size--;
	}
}

bool List::empty() { return size == 0; }

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
	return *this;
}

int& List::operator ()() {
	return size;
}
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

//-----------------------------------------------------------------//
//операция доступа по индексу
int& List::operator[](int index) {
	if (index < size && index >= 0) {
		Node* curr = head;
		for (int i = 0; i < index; i++) curr = curr->next;
		return curr->data;
	}
	else throw IndexError();
}
// произведение списков
List List::operator*(List& a) {
	if (size != a.size) throw SizeError();
	else {
		List templist(size);
		for (int i = 0; i < size; i++) templist[i] = (*this)[i] * a[i];
		return templist;
	}
}
// операция переходу к узлу с номером n
int& List::operator +(int n) {
	if (n > size || n < 1) throw NumberError();
	else {
		Node* curr = head;
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				return curr->data;
			}
			curr = curr->next;
		}
	}
}