#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair {
private:
	int first;
	double second;
public:
	Pair() {
		first = 0;
		second = 0;
	};
	Pair(int F, double S) {
		first = F;
		second = S;
	};
	Pair(const Pair& t) {
		first = t.first;
		second = t.second;
	};
	~Pair() {};
	int get_sirst() { return first; }
	double get_second() { return second; }
	void set_first(int F) { first = F; }
	void set_second(double S) { second = S; }
	Pair operator -(const Pair& p);
	Pair& operator +(const int X);
	Pair& operator +(const double X);
	Pair operator *(Pair&);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};

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
	return (out << t.first << " : " << t.second);
}

Pair Pair::operator*(Pair& p) {
	Pair temp;
	temp.first = (*this).first * p.first;
	temp.second = (*this).second * p.second;
	return temp;
}