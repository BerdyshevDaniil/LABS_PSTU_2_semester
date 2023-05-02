#pragma once
#include <list>
#include <iostream>
using namespace std;

template <class T>
class List {
	list <T> l;
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
		l.push_back(a);
	}
	size = l.size();
}

template <class T>
void List<T>::Print() {
	for (auto it = l.begin();it != l.end();++it)
		cout << *it;
	cout << endl;
}

template <class T>
T List<T>::srednee() {
	T s;
	for (auto it = l.begin();it != l.end();++it) s += *it;
	int n = l.size();
	s = s / n;
	return s;
}

template <class T>
void List<T>::add_list(T el) {
	l.insert(l.end(), el);
}

template <class T>
void List<T>::remove_elements(T rmin, T rmax) {
	if (rmax < rmin) swap(rmin, rmax);
	for (auto it = l.begin();it != l.end();) {
		if (*it <= rmax && *it >= rmin)
			it = l.erase(it);
		else
			++it;
	}
}

template <class T>
T List<T>::max() {
	T max = *(l.begin());
	for (auto it = l.begin();it != l.end();++it)
		if (*it > max)
			max = *it;
	return max;
}
template <class T>
T List<T>::min() {
	T min = *(l.begin());
	for (auto it = l.begin();it != l.end();++it)
		if (*it < min)
			min = *it;
	return min;
}

template <class T>
void List<T>::increase_elements(T min, T max) {
	for (auto it = l.begin();it != l.end();++it)
		*it = *it + min + max;
}