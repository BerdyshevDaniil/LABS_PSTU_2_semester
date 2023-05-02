#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include "Pair.h"
using namespace std;

ostream& operator<<(ostream& out, list<Pair>& l) {
	for_each(l.begin(), l.end(), [](Pair& p) {cout << p; });
	return out;
}

bool EQUAL(Pair a, Pair t) {
	if (a == t) return true;
	return false;
}

void menu(const int c, list<Pair>& l) {
	switch (c) {
		//sort
	case 1: {
		cout << l << endl;
		cout << "Enter < for ascending sort\nEnter > for descending sort\n";
		char op;
		cin >> op;
		if (op == '<') l.sort(mem_fun_ref(&Pair::operator<));
		else if (op == '>') l.sort(mem_fun_ref(&Pair::operator>));
		else cout << "wrong character\n";
		cout << l << endl;
		break;
	}
		  //find element 
	case 2: {
		cout << l << "\n\n";
		cout << "Input value:\n";
		Pair value;
		cin >> value;
		auto it = find_if(l.begin(), l.end(), bind2nd(ptr_fun(EQUAL), value));
		if (it == l.end()) {
			cout << "no such element!" << endl;
			break;
		}
		for (list<Pair>::iterator i = l.begin(); i != l.end(); ++i) {
			if (i == it) {
				cout << "the element is " << *i << endl;
			}
		}
		break;
	}
		  //arithmetical mean
	case 3: {
		cout << l << endl << endl;
		Pair sum;
		for_each(l.begin(), l.end(), [&sum](Pair& p) {sum += p; });
		sum.set_first(sum.get_first() / l.size());
		sum.set_second(sum.get_second() / l.size());
		l.push_back(sum);
		cout << l << endl;
		break;
	}
		  //delete from range
	case 4: {
		cout << l << endl;
		Pair one, two;
		cout << "Summary of each elment: " << endl;
		for_each(l.begin(), l.end(), [](Pair& p) {cout << p.sum() << ' '; });

		cout << "\nInput first border:\n"; cin >> one;
		cout << "\nInput second border:\n"; cin >> two;
		if (one > two) swap(one, two);

		auto s = remove_if(l.begin(), l.end(), [one, two](Pair& p) {return p >= one && p <= two; });
		l.erase(s, l.end());

		cout << "Elements of collectiont: " << endl;
		for_each(l.begin(), l.end(), [](Pair& p) {cout << p; });
		break;
	}
		  //minmax
	case 5: {
		cout << l << endl << endl;
		auto mini = min_element(l.begin(), l.end());
		auto maxi = max_element(l.begin(), l.end());
		cout << "min: " << *mini;
		cout << "max: " << *maxi;
		Pair sum;
		sum = *mini + *maxi;
		cout << "summary = " << sum << endl;
		for_each(l.begin(), l.end(), [&sum](Pair& p) {p += sum;});
		cout << endl << l << endl;
		break;
	}
		  //print
	case 6: {
		cout << l << endl;
		break;
	}
		  //exit
	default: {
		cout << "\nExiting from menu" << endl;
		exit(777);
	}
	}
}


int main() {
	system("color F0");
	srand(time(NULL));
	int n;
	cout << "Size of list: ";
	cin >> n;
	list<Pair> l(n);
	generate(l.begin(), l.end(), []() {Pair p; p.set_random(); return p; });
	cout << l << endl;

	while (true) {
		system("pause");
		system("cls");
		cout << "1. Sort container\n";
		cout << "2. Find a pair\n";
		cout << "3. Put arithmetical mean in the end\n";
		cout << "4. Delete elements from range\n";
		cout << "5. Add summary of min and max to every pair\n";
		cout << "6. Print container\n";
		int c;
		cin >> c;
		system("cls");
		menu(c, l);
	}
	return 0;
}