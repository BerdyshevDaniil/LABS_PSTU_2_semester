#include "List.h"
#include "Error.h"
#include <iostream>
#include <exception>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    system("color F0");
    try {
        List a(5);
        List b(6);
        cout << "a: " << a;
        cout << a[5];   // доступ к элементу с индексом, равным размеру списка
        cout << "b: " << b;
        List c = a * b; // произведение списков с различной длиной
        cout << b + 6 << endl;
        cout << b + 7;  // обращение к элементу с номером, большим чем, размер списка
    }
    catch (Error &e) {
        e.what();
    }
    catch (...) {
        cout << "Unknown exception occurred" << endl;
    }
    return 0;
}