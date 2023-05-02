#include "Pair.h"
#include "file_work.h" 
#include <iostream> 
#include <fstream>
#include <string> 
#include <Windows.h>
using namespace std; 

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	system("color F0");
	Pair p, temp; int k, c, num, count; double plus; char file_name[30];
	do{	//����
		system("pause"); system("cls");
		cout << "1. ������� ������"; 
		cout << "\n2. ������� ����";
		cout << "\n3. ������� ����, ������� �������� ����";
		cout << "\n4. �������� ��������� ��� ����� ���� � �������� �������";
		cout<<"\n0. �����\n";
		cin >> c; 
		switch (c) {
		case 1:
			cout << "��� �����: "; cin >> file_name;//������ ��� ����� 
			k = make_file(file_name);//����� ������� ��� ������ � ���� 
			if (k < 0) cout << "���������� ������� ����\n";//����� ��������� �� ������ 
			break;
		case 2:
			cout << "��� �����: "; cin >> file_name; //������ ��� ����� 
			k = print_file(file_name); //����� ������� ��� ������ ����� 
			if (k == 0) cout << "������ ����\n"; //���� ���� ������ 
			if (k < 0) cout << "Can't read file\n"; //���� ���� ������ ������� 
			break;
		case 3:
			cout << "��� �����: "; cin >> file_name;
			cin >> temp;
			k = del_file(file_name, temp);
			if (k < 0)cout << "���������� ������� ����\n";
			break;
		case 4:
			cout << "��� �����: "; cin >> file_name;
			cout << "����� ������ ������: "; cin >> num;
			cout << "�������: "; cin >> count;
			k = add_file(file_name, num, count);
			if (k < 0) cout << "���������� ������� ����\n";
			if (k == 0) k = add_end(file_name, count);
			break;
		case 5:
			cout << "��� �����: "; cin >> file_name;
			cout << "������� �����, ������� ������ ��������: ";
			cin >> plus;
			k = change_file(file_name, plus);
			if (k < 0) cout << "���������� ������� ����\n";
			break;
		}
	} while (c != 0);
	return 0;
}