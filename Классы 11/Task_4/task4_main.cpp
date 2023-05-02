#include <C:\Users\berdy\source\repos\Lessons C++\Классы 11\Task_2\Pair.h>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

typedef priority_queue<Pair> PQ;
typedef list<Pair> List;

PQ make_pq(int n) {
	PQ s; 
	Pair t;
	for (int i = 0;i < n;i++) {
		cin >> t; 
		s.push(t);
	}
	return s;
}

List copy_pq_to_list(PQ pq) {
	List l;
	while (!pq.empty()) {
		l.push_back(pq.top());
		pq.pop();
	}
	return l;
}

PQ copy_list_to_pq(List l) {
	PQ pq;
	for (auto it = l.cbegin();it != l.cend();++it)
		pq.push(*it);
	return pq;
}

void print_pq(PQ pq) {
	List l = copy_pq_to_list(pq);
	for (auto it = l.cbegin();it != l.cend();++it)
		cout << *it;
	cout << endl;
}

Pair srednee(PQ pq) {
	Pair s;
	List l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();++it) s += *it;
	int n = l.size();
	s = s / n;
	return s;
}

void add_pq(PQ& pq, Pair el) {
	pq.push(el);
}

void remove_elements(PQ& pq, Pair rmin, Pair rmax) {
	if (rmax < rmin) swap(rmin, rmax);
	List l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();) {
		if (*it <= rmax && *it >= rmin)
			it = l.erase(it);
		else
			++it;
	}
	pq = copy_list_to_pq(l);
}

Pair max(PQ pq) {
	Pair max(INT_MIN, INT_MIN);
	List l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();++it)
		if (*it > max)
			max = *it;
	return max;
}

Pair min(PQ pq) {
	Pair min(INT_MAX, INT_MAX);
	List l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();++it)
		if (*it < min)
			min = *it;
	return min;
}

void increase_elements(PQ& pq, Pair min, Pair max) {
	List l = copy_pq_to_list(pq);
	for (auto it = l.begin();it != l.end();++it)
		*it = *it + min + max;
	pq = copy_list_to_pq(l);
}

int main() {
	system("color F0");
	Pair range_min, range_max, min_el, max_el;
	PQ pq;
	int n;
	cout << "n = "; cin >> n;
	pq = make_pq(n);
	print_pq(pq);
	Pair el = srednee(pq);
	add_pq(pq, el);
	cout << "Adding the arithmetic mean to the end of the list\n";
	print_pq(pq);
	cout << "Set a range to remove elements:\nfrom:\n"; cin >> range_min;
	cout << "to:\n"; cin >> range_max;
	cout << "Remove elements:\n";
	remove_elements(pq, range_min, range_max);
	print_pq(pq);
	min_el = min(pq);
	max_el = max(pq);
	cout << "Increase elements:\n";
	increase_elements(pq, min_el, max_el);
	print_pq(pq);
	return 0;
}