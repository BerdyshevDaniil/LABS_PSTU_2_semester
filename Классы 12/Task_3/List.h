#pragma once
#include <set>
#include <iostream>
using namespace std;

template <class T>
class List {
	multiset <T> ms;
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
		ms.insert(a);
	}
	size = ms.size();
}

template <class T>
void List<T>::Print() {
	int k = 1;
	for (auto i = ms.begin(); i != ms.end(); i++) 
		cout << k++ << ") " << *i;
}

template <class T>
T List<T>::srednee() {
	T s;
	for (auto it = ms.begin();it != ms.end();++it) s += *it;
	int n = ms.size();
	s = s / n;
	return s;
}

template <class T>
void List<T>::add_list(T el) {
	ms.insert(el);
}

template <class T>
void List<T>::remove_elements(T rmin, T rmax) {
	if (rmax < rmin) swap(rmin, rmax);
	for (auto it = ms.begin();it != ms.end();) {
		if (*it <= rmax && *it >= rmin)
			it = ms.erase(it);
		else
			++it;
	}
}

template <class T>
T List<T>::max() {
	auto i = ms.end();
	--i;
	T max = *(ms.begin());
	return max;
}
template <class T>
T List<T>::min() {
	T min = *(ms.begin());
	return min;
}

template <class T>
void List<T>::increase_elements(T min, T max) {
	multiset<T> m1;
	for (auto i = ms.begin(); i != ms.end(); ++i) {
		T temp = min + max + *i;
		m1.insert(temp);
	}
	ms = m1;
}