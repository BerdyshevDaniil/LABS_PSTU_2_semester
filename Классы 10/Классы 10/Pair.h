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
	bool operator <(const Pair&);
	Pair operator -(const Pair& p);
	Pair& operator +(const int X);
	Pair& operator +(const double X);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend fstream& operator>>(fstream& fin, Pair& p);
	friend fstream& operator<<(fstream& fout, const Pair& p);
};