#include "Pair.h"
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc); //открыть для записи 
	if (!stream) return -1; //ошибка открытия файла
	int n;
	Pair p;
	cout << "Количество пар? ";
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> p; //ввод атрибутов объекта из стандартного потока 
		stream << p << '\n'; //запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n; //вернуть количество записанных объектов 
}

int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)return -1;//ошибка открытия файла
	Pair p;
	int i = 0;
	while (stream >> p) {
		cout << p; 
		i++;
	}
	stream.close(); 
	return i;
}

int del_file(const char* f_name, Pair t) {
	fstream temp("temp", ios::out); //открыть для записи 
	fstream stream(f_name, ios::in); //открыть для чтения 
	if (!stream)return -1; //ошибка открытия файла
	int i = 0;
	Pair p;
	while (stream >> p) { //пока нет конца файла выполняем чтение объекта 
		//если прочитан признак конца файла,то выход из цикла 
		if (stream.eof()) break;
		i++;
		//если номер объекта не равен k, то записываем его во вспомогательый файл 
		if (t < p) temp << p;
	}
	//закрыть файлы
	stream.close();
	temp.close();
	remove(f_name); //удалить старый файл 
	rename("temp", f_name); //переименовать temp 
	return i; //количество прочитанных
}

int add_file(const char* f_name, int k, int count) {
	fstream temp("temp", ios::out); //открыть для записи 
	fstream stream(f_name,ios::in); //открыть для чтения 
	if (!stream) return -1; //ошибка открытия файла
	Pair p; int i = 0, l = 0; 
	while (stream >> p) {
		if (stream.eof())break; 
		i++;
		temp << p;
		if (i == k) {
			for (int j = 0; j < count; j++) {
				Pair new_Pair;
				cin >> new_Pair;
				temp << new_Pair;//записать в temp новую запись 
				l++;
			}
		} 
	}
	stream.close(); 
	temp.close(); 
	remove(f_name); 
	rename("temp", f_name);
	return l; //количество добавленных 
}

int add_end(const char* f_name, int count) {
	fstream stream(f_name, ios::app);//открыть для добавления 
	if(!stream) return -1;//ошибка открытия файла
	for (int i = 0; i < count;i++) {
		Pair new_Pair;
		cin >> new_Pair;
		stream << new_Pair; //записать новую запись
	}
	return 1;
}

int change_file(const char* f_name, double k) {
	fstream temp("temp", ios::out); //открыть для записи 
	fstream stream(f_name, ios::in); //открыть для чтения 
	if (!stream) return -1;//ошибка открытия файла
	Pair p; int l = 0;
	while (stream >> p) {
		if (stream.eof()) break; 
		if (k == (int)k)
			p + (int)k;
		else
			p + k;
		temp << p;
	}
	stream.close(); 
	temp.close(); 
	remove(f_name); 
	rename("temp", f_name);
	return l; //количество измененных элементов 
}