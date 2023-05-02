#pragma once
#include <list>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
class List {
	priority_queue<T> pq;
	int size;
public:
	List(void);
	List(int n);
	void Print();
	~List(void);
	T srednee();
	void add_list(T el);
	void remove_elements(T rmin, T rmax);
	T max();
	T min();
	void increase_elements(T min, T max);
};

template <class T>
list<T> copy_pq_to_list(priority_queue<T> pq) {
	list<T> l;
	while (!pq.empty()) {
		l.push_back(pq.top());
		pq.pop();
	}
	return l;
}
template <class T>
priority_queue<T> copy_list_to_pq(list<T> l) {
	priority_queue<T> pq;
	for (auto it = l.cbegin();it != l.cend();++it)
		pq.push(*it);
	return pq;
}

template <class T>
List<T>::List() {
	size = 0;
}

template <class T>
List<T>::~List() {}

template <class T>
List<T>::List(int n) {
	T a;
	for (int i = 0;i < n;++i) {
		cin >> a;
		pq.push(a);
	}
	size = pq.size();
}

template <class T>
void List<T>::Print() {
	list<T> l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();++it)
		cout << *it;
	cout << endl;
}

template <class T>
T List<T>::srednee() {
	T s;
	list<T> l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();++it) s += *it;
	int n = l.size();
	s = s / n;
	return s;
}

template <class T>
void List<T>::add_list(T el) {
	pq.push(el);
}

template <class T>
void List<T>::remove_elements(T rmin, T rmax) {
	if (rmax < rmin) swap(rmin, rmax);
	list<T> l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();) {
		if (*it <= rmax && *it >= rmin)
			it = l.erase(it);
		else
			++it;
	}
	pq = copy_list_to_pq(l);
}

template <class T>
T List<T>::max() {
	list<T> l = copy_pq_to_list(pq);
	T max = *(l.begin());;
	for (auto it = l.begin();it != l.end();++it)
		if (*it > max)
			max = *it;
	return max;
}
template <class T>
T List<T>::min() {
	list<T> l = copy_pq_to_list(pq);
	T min = *(l.begin());;
	for (auto it = l.begin();it != l.end();++it)
		if (*it < min)
			min = *it;
	return min;
}

template <class T>
void List<T>::increase_elements(T min, T max) {
	list<T> l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();++it)
		*it = *it + min + max;
	pq = copy_list_to_pq(l);
}