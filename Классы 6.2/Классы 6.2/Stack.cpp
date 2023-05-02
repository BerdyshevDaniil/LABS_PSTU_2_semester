#include "Stack.h"

//конструктор с параметрами
Stack::Stack(int s) {
	for (int i = 0; i < s; i++) {
		pushback(rand() % 10);
	}
	size = s;
}

Stack::Stack() {
	size = 0;
	head = nullptr;
}

//деструктор
Stack::~Stack() {
	Node* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}

bool Stack::empty() {
	return size == 0;
}

void Stack::pushback(int data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = head;
	head = new_node;
	size++;
}

void Stack::popback() {
	Node* temp = head;
	head = temp->next;
	size--;
	delete temp;
}

int& Stack::operator ()() {
	return size;
}

//операции для ввода-вывода
ostream& operator<<(ostream& out, const Stack& a) {
	Node* curr = a.head;
	while (curr != nullptr) {
		cout << curr->data << "\n";
		curr = curr->next;
	}
	cout << endl;
	return out;
}