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
	~Pair(){};
	int get_sirst() {return first;}
	double get_second() {return second;}
	void set_first(int F) {first = F;}
	void set_second(double S) {second = S;}
	Pair operator -(const Pair& p);
	Pair& operator +(const int X);
	Pair& operator +(const double X);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};