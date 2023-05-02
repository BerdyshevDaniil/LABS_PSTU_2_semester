#include "fraction.h"

fraction make_fruction(double F, int S) {
	fraction new_fraction;
	new_fraction.Init(F, S);
	return new_fraction;
}

int main() {
	system("color F0");
	int second, j; double first;
	cout << "Enter double \"First\": "; cin >> first;
	cout << "Enter integer \"Second\": "; cin >> second;
	fraction p = make_fruction(first, second);
	cout << "Enter a number of sequence: "; cin >> j;
	cout << "Element " << j << " = " << p.element(j);
	return 0;
}