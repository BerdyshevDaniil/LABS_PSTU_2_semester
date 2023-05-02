#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pair {
private:
	int first;
	double second;
public:
	Pair() { first = 0;	second = 0; };
	Pair(int F, double S) { first = F; second = S; };
	Pair(const Pair& t) { first = t.first;second = t.second; };
	~Pair() {};
	Pair operator =(const Pair&);
	bool operator <(const Pair&) const;
	bool operator >(const Pair&) const;
	bool operator <=(const Pair&) const;
	bool operator >=(const Pair&) const;
	Pair& operator -(const Pair& p);
	Pair& operator +(const Pair& p);
	Pair& operator +=(const Pair& p);
	Pair& operator +(const int X);
	Pair& operator +(const double X);
	Pair& operator /(const int X);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend fstream& operator>>(fstream& fin, Pair& p);
	friend fstream& operator<<(fstream& fout, const Pair& p);
};

Pair& Pair::operator +(const int X) {
	first += X;
	return *this;
}

Pair& Pair::operator +(const double X) {
	second += X;
	return *this;
}

Pair& Pair::operator /(const int X) {
	first = first / X;
	second = second / X;
	return *this;
}

Pair& Pair::operator -(const Pair& p) {
	this->first -= p.first;
	this->second -= p.second;
	return *this;
}

Pair& Pair::operator +(const Pair& p) {
	this->first += p.first;
	this->second += p.second;
	return *this;
}

Pair& Pair::operator +=(const Pair& p) {
	this->first += p.first;
	this->second += p.second;
	return *this;
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

bool Pair::operator <(const Pair& p) const {
	double sthis = this->first + this->second;
	double sother = p.first + p.second;
	if (sthis < sother) return true;
	return false;
}

bool Pair::operator >(const Pair& p) const {
	double sthis = this->first + this->second;
	double sother = p.first + p.second;
	if (sthis > sother) return true;
	return false;
}

bool Pair::operator <=(const Pair& p) const {
	double sthis = this->first + this->second;
	double sother = p.first + p.second;
	if (sthis <= sother) return true;
	return false;
}

bool Pair::operator >=(const Pair& p) const {
	double sthis = this->first + this->second;
	double sother = p.first + p.second;
	if (sthis >= sother) return true;
	return false;
}