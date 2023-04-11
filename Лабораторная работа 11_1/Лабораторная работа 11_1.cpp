#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Point {
    string key;
    Point* next = nullptr;
};

struct List {
    int size = 0;
    Point* head = nullptr;
    Point* tail = nullptr;
};

bool ListIsEmpty(List* list);
void PushBack(List* list, string str);
void PushFront(List* list, string str);
List* CreateList(int size);
void ShowList(List* list);
void RemoveElement(List* list, string k);
void RemoveElement(List* list, int n);
void AddElements(List* list, int count, int number);
void PrintInFile(string filename, List* list);
void PrintFromFile(string filename, List* list, const int size);

void ShowMenu() {
    cout << "\t\tМеню\n";
    cout << "Введите 0 для заверщения работы программы.\n";
    cout << "Введите 1 для создания списка.\n";
    cout << "Введите 2 для показа списка.\n";
    cout << "Введите 3 для добавления элемента в начало списка.\n";
    cout << "Введите 4 для добавления элемента в конец списка.\n";
    cout << "Введите 5 для удаления элемента с заданым ключём.\n";
    cout << "Введите 6 для добавления нескольких элементов перед элементом с заданым номером.\n";
    cout << "Введите 7, чтобы удалить список.\n";
    cout << "Введите 8, чтобы записать данные в файл.\n";
    cout << "Введите 9, чтобы записать данные из файла в список.\n";
}

void menu() {
    int switch_n, size_list, number, count;
    string key, file = "MyFile.txt";
    List* list = new List;
    do {
        system("pause");
        system("cls");
        ShowMenu();
        cin >> switch_n;
        switch (switch_n) {
        case 0:
            cout << "Работа завершена!";
            break;
        case 1:
            cout << "Введите размер списка: ";
            cin >> size_list;
            while (size_list < 1) {
                cout << "Размер списка должен быть от одного и более элементов! Введите размер: ";
                cin >> size_list;
            }
            list = CreateList(size_list);
            break;
        case 2:
            ShowList(list);
            break;
        case 3:
            cout << "Введите новую строку:\n";
            getline(cin, key); getline(cin, key);
            PushFront(list, key);
            break;
        case 4:
            cout << "Введите новую строку:\n";
            getline(cin, key); getline(cin, key);
            PushBack(list, key);
            break;
        case 5:
            cout << "Введите ключ: ";
            getline(cin, key); getline(cin, key);
            RemoveElement(list, key);
            break;
        case 6:
            cout << "Введите номер заданного элемента: ";
            cin >> number;
            while (number <= 0 || number > list->size) {
                cout << "Номер должен быть больше нуля и меньше " << list->size + 1 << "!Введите номер : ";
                cin >> number;
            }
            cout << "Введите кол-во вводимых элементов: ";
            cin >> count;
            while (count < 1) {
                cout << "Кол-во должно быть больше нуля! Введите кол-во элементов: ";
                cin >> count;
            }
            AddElements(list, count, number);
            break;
        case 7:
            while (!ListIsEmpty(list)) {
                RemoveElement(list, 1);
            }
            cout << "Список удалён!\n";
            break;
        case 8:
            if (!ListIsEmpty(list)) {
                size_list = list->size;
                PrintInFile(file, list);
                cout << "Массив записан!\n";
            }
            else
                cout << "Список не создан!";
            break;
        case 9:
            PrintFromFile(file, list, size_list);
            cout << "Данные из файла записаны!\n";
            break;
        }
    } while (switch_n != 0);
}

bool ListIsEmpty(List* list) {
    return list == nullptr || list->size == 0;
}

void PushBack(List* list, string str) {
    Point* new_point = new Point;
    new_point->key = str;
    new_point->next = nullptr;
    if (ListIsEmpty(list)) {
        list->head = new_point;
        list->tail = new_point;
    }
    else if (list->size == 1) {
        list->tail->next = new_point;
        list->tail = new_point;
        list->head->next = list->tail;
    }
    else {
        list->tail->next = new_point;
        list->tail = new_point;
    }
    list->size++;
}

void PushFront(List* list, string str) {
    Point* new_point = new Point;
    new_point->key = str;
    if (ListIsEmpty(list)) {
        list->head = new_point;
        list->tail = new_point;
    }
    else {
        new_point->next = list->head;
        list->head = new_point;
    }
    list->size++;
}

List* CreateList(int size) {
    List* list = new List;
    string str;
    cout << "Введите ключи элементов:\n"; getline(cin, str);
    for (int i = 0; i < size; i++) {
        cout << i + 1 << '\t'; getline(cin, str);
        PushBack(list, str);
    }
    return list;
}

void ShowList(List* list) {
    if (ListIsEmpty(list)) cout << "Список пуст!\n";
    else {
        int i = 1;
        Point* temp = list->head;
        cout << "---------------------------\n";
        cout << "\tСписок\n";
        do {
            cout << i++ << '\t' << temp->key << endl;
            temp = temp->next;
        } while (i <= list->size);
        cout << "---------------------------\n";
    }
}

void RemoveElement(List* list, string k) {
    Point* temp = list->head;
    if (temp->key == k) {
        list->head = temp->next;
        delete temp;
        list->size--;
        cout << "Элемент удалён!\n";
        return;
    }
    while (temp->next->key != k) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Point* r = temp->next;
        temp->next = r->next;
        delete r;
        list->size--;
        r = temp->next;
        cout << "Элемент удалён!\n";
        return;
    }
    else {
        cout << "Элемент не найден!\n";
    }
}

void RemoveElement(List* list, int n) {
    Point* temp = list->head;
    int i = 1;
    if (i == n) {
        list->head = temp->next;
        delete temp;
        list->size--;
        return;
    }
    while (i + 1 != n) {
        i++;
    }
    temp->next = temp->next->next;
    delete temp->next;
    list->size--;
    return;
}

void AddElements(List* list, int count, int number) {
    int i = 1;
    string key;
    Point* temp = list->head;
    if (i == number) {
        getline(cin, key);
        for (int j = 1; j <= count; j++) {
            cout << "Введите новый ключ " << j << ": ";
            getline(cin, key);
            if (j == 1) {
                PushFront(list, key);
                temp = list->head;
            }
            else {
                Point* new_point = new Point;
                new_point->next = temp->next;
                temp->next = new_point;
                new_point->key = key;
                temp = new_point;
                list->size++;
            }
        }
    }
    else {
        while (i + 1 != number) {
            temp = temp->next;
            i++;
        }
        getline(cin, key);
        for (int j = 1; j <= count; j++) {
            cout << "Введите новый ключ " << j << ": ";
            getline(cin, key);
            Point* new_point = new Point;
            new_point->next = temp->next;
            temp->next = new_point;
            new_point->key = key;
            temp = new_point;
            list->size++;
        }
    }
}

void PrintInFile(string filename, List* list) {
    ofstream fout;
    Point* temp = list->head;
    fout.open(filename);
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        while (!ListIsEmpty(list)) {
            temp = list->head;
            fout << temp->key;
            fout << '\n';
            RemoveElement(list, 1);
        }
    }
    fout.close();
}

void PrintFromFile(string filename, List* list, const int size) {
    ifstream fin;
    fin.open(filename);
    string key;
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        for (int i = 1; i <= size; i++) {
            fin >> key;
            PushBack(list, key);
        }
    }
    fin.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}