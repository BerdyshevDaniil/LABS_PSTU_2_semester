#include <iostream>
#include <math.h>
using namespace std;

class fraction {
private:
	double first;
	int second;
public:
	void Init(double, int);
	void Show();
	void Read();
	double element(int j);
};