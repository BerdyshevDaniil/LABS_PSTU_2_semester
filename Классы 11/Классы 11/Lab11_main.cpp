#include <iostream>
#include <list> 
#include <cstdlib> 
using namespace std;

typedef list<double>List;
List make_list(int n) {
	List l;
	for (int i = 0;i < n;++i) {
		double a = (rand() % 100 + 100);
		a /= 100;
		l.push_back(a);
	}
	return l;
}

void print_list(List& l) {
	for (auto it = l.begin();it != l.end();++it)
		cout << *it << " ";
	cout << endl;
}

double srednee(List& l){
	double s = 0;
	for (auto it = l.begin();it != l.end();++it) s += *it;
	int n = l.size();
	return s/n;
}
void add_list(List& l, double el) { 
	l.insert(l.end(), el);
}

void remove_elements(List& l, double rmin, double rmax) {
	if (rmin > rmax) swap(rmin, rmax);
	for (auto it = l.begin();it != l.end();) {
		if (*it <= rmax && *it >= rmin)
			it = l.erase(it);
		else
			++it;
	}
}

double max(List& l) {
	double max = INT_MIN;
	for (auto it = l.begin();it != l.end();++it)
		if (*it > max)
			max = *it;
	return max;
}

double min(List& l) {
	double min = INT_MAX;
	for (auto it = l.begin();it != l.end();++it)
		if (*it < min)
			min = *it;
	return min;
}

void increase_elements(List& l, double min, double max) {
	for (auto it = l.begin();it != l.end();++it)
		*it = *it + min + max;
}

int main() {
	system("color F0");
	try {
		list<double> l;
		int n;
		double range_min, range_max, min_el, max_el;
		cout << "n = "; cin >> n;
		l = make_list(n);
		print_list(l);
		double el = srednee(l);
		add_list(l, el);
		cout << "Adding the arithmetic mean to the end of the list\n";
		print_list(l);
		cout << "Set a range to remove elements:\nfrom: "; cin >> range_min;
		cout << "to: "; cin >> range_max;
		cout << "Remove elements:\n";
		remove_elements(l, range_min, range_max);
		print_list(l);
		min_el = min(l);
		max_el = max(l);
		cout << "Increase elements:\n";
		increase_elements(l, min_el, max_el);
		print_list(l);
	}
	catch (int) {
		cout << "error!";
	}
	return 0;
}