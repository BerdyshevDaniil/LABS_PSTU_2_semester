#include "Pair.h"
#include <Windows.h>

int main() {
	system("color F0");
	Pair a1;
	Pair a2;
	Pair a3;
	cin >> a1;
	cin >> a2;
	a3 = a1 - a2;
	cout << a3;
	cout << a1;

	a1 + 3;
	a1 + 0.555;
	cout << a1;

	return 0;
}