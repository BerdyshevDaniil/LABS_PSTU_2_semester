#include "Vector.h"
#include "Dialog.h"
#include "Event.h"
#include "Magazin.h"
#include "Object.h"
#include "Print.h"
#include <Windows.h>

int main() {
	system("color F0");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	cout << "m: ������� ������\n";
	cout << "+: �������� �������\n";
	cout << "-: ������� �������\n";
	cout << "s: ���������� � ������ ������\n";
	cout << "z: ���������� � ��������� ��������� ������\n";
	cout << "q: ����� ������\n";
	Dialog D;
	D.Execute();
	return 0;
}