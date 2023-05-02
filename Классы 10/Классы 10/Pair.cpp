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

Pair Pair::operator =(const Pair& p) {
	if (&p == this) return *this; 
	first = p.first;
	second = p.second;
	return*this;
}

fstream& operator>>(fstream& fin, Pair& p) {
	fin >> p.first;
	fin >> p.second;
	return fin;
}

fstream& operator<<(fstream& fout, const Pair& p) {
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}

bool Pair::operator <(const Pair& p) {
	double temp = p.first + p.second;
	double t = (*this).first + (*this).second;
	if (t < temp) return true;
	return false;
}