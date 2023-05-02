#include "Pair.h"

Pair& Pair::operator +(const int X) {
	first += X;
	return *this;
}

Pair& Pair::operator +(const double X) {
	second += X;
	return *this;
}

Pair Pair::operator -(const Pair& p) {
	Pair temp;
	temp.first = this->first - p.first;
	temp.second = this->second - p.second;
	return temp;
}

istream& operator >>(istream& in, Pair& t) {
	cout << "int first = "; in >> t.first;
	cout << "double second = "; in >> t.second;
	return in;
}

ostream& operator <<(ostream& out, const Pair& t) {
	return (out << t.first << " : " << t.second << endl);
}