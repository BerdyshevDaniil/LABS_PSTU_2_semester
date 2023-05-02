#include "fraction.h"

void fraction::Init(double F, int S) {
	first = F;
	second = S;
}
void fraction::Show() {
	cout << "First = " << first << endl;
	cout << "Second = " << second << endl;
}
void fraction::Read() {
	cout << "Enter integer \"First\": "; cin >> first;
	cout << "Enter double \"Second\": "; cin >> second;
}
double fraction::element(int j) {
	return first * pow(second, j);
}