#include <iostream> 
#include <string> 
using namespace std;
class paycheck {
	//атрибуты
private:
	string full_name;
	int bonus;
	double salary;
public:
	paycheck();//конструктор без параметров
	paycheck(string, double, int);
	paycheck(const paycheck&);
    ~paycheck();

	void set_full_name(string name);
	string get_full_name();
	void set_salary(double S);
	double get_salary();
	void set_bonus(int B);
	int get_bonus();
	void show();
};