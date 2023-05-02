#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include "Pair.h"
using namespace std;

ostream& operator<<(ostream& out, priority_queue<Pair>& q) {
	vector<Pair> COPY;
	Pair elem;
	int num = q.size();
	for (size_t i = 0; i < num; ++i) {
		elem = q.top();
		cout << elem;
		COPY.push_back(elem);
		q.pop();
	}
	int k = 0;
	for (int i = 0; i < COPY.size(); ++i) {
		q.push(COPY[k++]);
	}
	COPY.clear();
	return out;
}

bool EQUAL(Pair a, Pair t) {
	if (a == t) return true;
	return false;
}

void menu(const int c, priority_queue<Pair>& q) {
	switch (c) {
		//sort
	case 1: {
		char op;
		cout << "Enter < for ascending sort\nEnter > for descending sort\n";
		cin >> op;
		if (op == '>') cout << q << endl;
		else if (op == '<') {
			vector<Pair> COPY;
			Pair elem;
			int num = q.size();
			for (int i = 0; i < num; ++i) {
				elem = q.top();
				COPY.push_back(elem);
				q.pop();
			}
			sort(COPY.begin(), COPY.end(), mem_fun_ref(&Pair::operator<));
			for_each(COPY.begin(), COPY.end(), [](Pair& p) {cout << p; });
			while (!COPY.empty()) {
				q.push(COPY[COPY.size() - 1]);
				COPY.pop_back();
			}
		}
		else cout << "wrong character!\n";
		break;
	}
		  //find element 
	case 2: {
		cout << q << "\n\n";
		cout << "Input value:\n";
		Pair value;
		cin >> value;
		auto f = [value](priority_queue<Pair>& q) {
			vector<Pair> COPY;
			Pair elem;
			bool flag = false;
			int num = q.size();
			for (int i = 0; i < num && !flag; ++i) {
				elem = q.top();
				if (EQUAL(elem, value)) {
					flag = true;
					cout << "the element is " << elem << endl;
				}
				COPY.emplace_back(elem);
				q.pop();
			}
			if (!flag) cout << "no such element!\n";
			while (!COPY.empty()) {
				q.push(COPY[COPY.size() - 1]);
				COPY.pop_back();
			}
		};
		f(q);
		break;
	}
		  //arithmetical mean
	case 3: {
		cout << q << endl;
		vector<Pair> COPY;
		Pair elem;
		while (!q.empty()) {
			elem = q.top();
			COPY.push_back(elem);
			q.pop();
		}
		Pair sum;
		for_each(COPY.begin(), COPY.end(), [&sum](Pair& p) {sum += p; });
		sum.set_first(round(sum.get_first() / COPY.size() * 100) / 100);
		sum.set_second(round(sum.get_second() / COPY.size() * 100) / 100);
		cout << "arithmetical mean is " << sum << "\n\n";
		q.push(sum);
		while (!COPY.empty()) {
			q.push(COPY[COPY.size() - 1]);
			COPY.pop_back();
		}
		cout << q << endl;
		break;
	}
		  //delete from range
	case 4: {
		cout << q << endl;
		Pair elem;
		vector<Pair> COPY;
		while (!q.empty()) {
			elem = q.top();
			COPY.push_back(elem);
			q.pop();
		}
		Pair one, two;
		cout << "Summary of each element: " << endl;
		for_each(COPY.begin(), COPY.end(), [](Pair& p) {cout << p.sum() << " "; });

		cout << "\nInput first border:\n"; cin >> one;
		cout << "\nInput second border:\n"; cin >> two;
		if (one > two) swap(one, two);

		auto s = remove_if(COPY.begin(), COPY.end(), [one, two](Pair& p) {return p >= one && p <= two; });
		COPY.erase(s, COPY.end());

		while (!COPY.empty()) {
			q.push(COPY[COPY.size() - 1]);
			COPY.pop_back();
		}
		cout << endl << q << endl;
		break;
	}
		  //minmax
	case 5: {
		cout << q << endl << endl;
		Pair elem;
		vector<Pair> COPY;
		while (!q.empty()) {
			elem = q.top();
			COPY.push_back(elem);
			q.pop();
		}
		auto mini = COPY[COPY.size() - 1];
		auto maxi = COPY[0];
		cout << "min: " << mini;
		cout << "max: " << maxi;
		Pair sum;
		sum = mini + maxi;
		cout << "summary = " << sum << endl;
		for_each(COPY.begin(), COPY.end(), [&sum](Pair& p) {p += sum; });
		while (!COPY.empty()) {
			q.push(COPY[COPY.size() - 1]);
			COPY.pop_back();
		}
		cout << endl << q << endl;
		break;
	}
		  //print
	case 6: {
		cout << q << endl;
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
	srand(time(NULL));
	system("color F0");
	int n;
	cout << "Input the size of queue: ";
	cin >> n;
	priority_queue<Pair> q;
	Pair p;
	for (int i = 0; i < n; ++i) {
		p.set_random();
		q.push(p);
	}

	cout << q << endl;
	while (true) {
		system("pause");
		system("cls");
		cout << "1. Sort container" << endl;
		cout << "2. Find a pair" << endl;
		cout << "3. Put arithmetical mean in the end" << endl;
		cout << "4. Delete elements from range" << endl;
		cout << "5. Add summary of min and max to every pair" << endl;
		cout << "6. Print container" << endl;
		cout << "Choose your option: ";
		int c;
		cin >> c;
		system("cls");
		menu(c, q);
	}
	return 0;
}