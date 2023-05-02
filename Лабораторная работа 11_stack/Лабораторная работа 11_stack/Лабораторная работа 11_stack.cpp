#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node {
    string key;
    Node* next = nullptr;
};

struct Stack {
    int size = 0;
    Node* head = nullptr;
};

bool StackIsEmpty(Stack* st);
void Push(Stack* st, string str);
void Pop(Stack* st);
Stack* CreateStack(int size);
void ShowStack(Stack* st);
void RemoveElement(Stack* st, string k);
void AddElements(Stack* st, int count, int number);
void PrintInFile(string filename, Stack* st);
void PrintFromFile(string filename, Stack* st, const int size);

void ShowMenu() {
    cout << "\t\tМеню\n";
    cout << "Введите 0 для заверщения работы.\n";
    cout << "Введите 1 для создания стека.\n";
    cout << "Введите 2 для показа стека.\n";
    cout << "Введите 3 для добавления элемента на дно стека.\n";
    cout << "Введите 4 для добавления элемента на верхушку стека.\n";
    cout << "Введите 5 для удаления элемента с заданым ключём.\n";
    cout << "Введите 6 для добавления нескольких элементов перед элементом с заданым номером.\n";
    cout << "Введите 7, чтобы удалить стек.\n";
    cout << "Введите 8, чтобы записать данные в файл.\n";
    cout << "Введите 9, чтобы записать данные из файла в стек.\n";
}

void menu() {
    int switch_n, size_stack, number, count;
    string key, file = "MyFile.txt";
    Stack* st = new Stack;
    do {
        system("pause");
        system("cls");
        ShowMenu();
        cin >> switch_n;
        switch (switch_n) {
        case 0:
            cout << "Вы категорически правы!";
            break;
        case 1:
            cout << "Введите размер стека: ";
            cin >> size_stack;
            while (size_stack < 1) {
                cout << "Размер стека должен быть от одного и более элементов! Введите размер: ";
                cin >> size_stack;
            }
            st = CreateStack(size_stack);
            break;
        case 2:
            ShowStack(st);
            break;
        case 3:
            AddElements(st, 1, 1);
            break;
        case 4:
            cout << "Введите новую строку:\n";
            getline(cin, key); getline(cin, key);
            Push(st, key);
            break;
        case 5:
            cout << "Введите ключ: ";
            getline(cin, key); getline(cin, key);
            RemoveElement(st, key);
            break;
        case 6:
            cout << "Введите номер заданного элемента: ";
            cin >> number;
            while (number < 1 || number > st->size) {
                cout << "Номер должен быть больше нуля и меньше " << st->size + 1 << "!Введите номер : ";
                cin >> number;
            }
            cout << "Введите кол-во вводимых элементов: ";
            cin >> count;
            while (count < 1) {
                cout << "Кол-во должно быть больше нуля! Введите кол-во элементов: ";
                cin >> count;
            }
            AddElements(st, count, number);
            break;
        case 7:
            while (!StackIsEmpty(st)) 
                Pop(st);
            delete st;
            cout << "Стек удалён!\n";
            break;
        case 8:
            if (!StackIsEmpty(st)) {
                size_stack = st->size;
                PrintInFile(file, st);
                cout << "Массив записан!\n";
            }
            else
                cout << "Стек не создан!\n";
            break;
        case 9:
            if (size_stack != 0) {
                PrintFromFile(file, st, size_stack);
                cout << "Данные из файла записаны!\n";
            }
            break;
        }
    } while (switch_n > 0 && switch_n <= 9);
}

bool StackIsEmpty(Stack* st) {
    return st == nullptr || st->size == 0;
}

void Push(Stack* st, string str) {
    Node* new_node = new Node;
    new_node->key = str;
    new_node->next = st->head;
    st->head = new_node;
    st->size++;
}

void Pop(Stack* st) {
    Node* temp = st->head;
    st->head = temp->next;
    st->size--;
    delete temp;
}

Stack* CreateStack(int size) {
    Stack* st = new Stack;
    string str;
    cout << "Введите ключи элементов:\n"; getline(cin, str);
    for (int i = 0; i < size; i++) {
        cout << i + 1 << '\t'; 
        getline(cin, str);
        Push(st, str);
    }
    return st;
}

void ShowStack(Stack* st) {
    if (StackIsEmpty(st)) cout << "Стек пуст!\n";
    else {
        Node* temp = st->head;
        int i = st->size;
        cout << "---------------------------\nСтек:\n";
        while (temp != nullptr) {
            cout << i << '\t' << temp->key << '\n';
            temp = temp->next;
            i--;
        }
        cout << "---------------------------\n";
    }
}

void RemoveElement(Stack* st, string k) {
    if (StackIsEmpty(st)) {
        cout << "Стек пуст!\n";
        return;
    }
    Stack* new_stack = new Stack;
    while (!StackIsEmpty(st)) {
        if (st->head->key != k) {
            Push(new_stack, st->head->key);
            Pop(st);
        }
        else 
            Pop(st);
    }
    while (!StackIsEmpty(new_stack)) {
        Push(st, new_stack->head->key);
        Pop(new_stack);
    }
    delete new_stack;
}

void AddElements(Stack* st, int count, int number) {
    if (number > st->size) return;
    int i = st->size;
    Stack* new_stack = new Stack;
    while (i >= number) {
        Push(new_stack, st->head->key);
        Pop(st);
        i--;
    }
    string key;
    getline(cin, key);
    for (int j = 1; j <= count; j++) {
        cout << "Введите новый ключ: ";
        getline(cin, key);
        Push(st, key);
    }
    while (!StackIsEmpty(new_stack)) {
        Push(st, new_stack->head->key);
        Pop(new_stack);
    }
    delete new_stack;
}

void PrintInFile(string filename, Stack* st) {
    ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        while (!StackIsEmpty(st)) {
            fout << st->head->key << '\n';
            Pop(st);
        }
    }
    fout.close();
}

void PrintFromFile(string filename, Stack* st, const int size) {
    ifstream fin;
    fin.open(filename);
    string key;
    Stack* new_stack = new Stack;
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        for (int i = 1; i <= size; i++) {
            fin >> key;
            Push(new_stack, key);
        }
        while (!StackIsEmpty(new_stack)) {
            Push(st, new_stack->head->key);
            Pop(new_stack);
        }
        delete new_stack;
    }
    fin.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}