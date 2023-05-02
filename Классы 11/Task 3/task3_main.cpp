#include <C:\Users\berdy\source\repos\Lessons C++\Классы 11\Task_2\Pair.h>
#include "List.h"
#include <iostream>
using namespace std;

int main() {
	system("color F0");
	List<Pair> l(3);
	l.Print();
	int n;
	Pair range_min, range_max, min_el, max_el;
	Pair el = l.srednee();
	l.add_list(el);
	cout << "Adding the arithmetic mean to the end of the list\n";
	l.Print();
	cout << "Set a range to remove elements:\nfrom:\n"; cin >> range_min;
	cout << "to:\n"; cin >> range_max;
	cout << "Remove elements:\n";
	l.remove_elements(range_min, range_max);
	l.Print();
	min_el = l.min();
	max_el = l.max();
	cout << "Increase elements:\n";
	l.increase_elements(min_el, max_el);
	l.Print();
	return 0;
}