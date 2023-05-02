#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Node {
    string key;
    Node* next = nullptr;
};

struct Queue {
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
};

bool QueueIsEmpty(Queue* Queue);
void Push(Queue* Queue, string str);
void Pop(Queue* queue);
Queue* CreateQueue(int size);
void ShowQueue(Queue* Queue);
void RemoveElement(Queue* Queue, string k);
void AddElements(Queue* Queue, int count, int number);
void PrintInFile(string filename, Queue* Queue);
void PrintFromFile(string filename, Queue* Queue, const int size);

void ShowMenu() {
    cout << "\t\tМеню\n";
    cout << "Введите 0 для заверщения работы программы.\n";
    cout << "Введите 1 для создания очереди.\n";
    cout << "Введите 2 для показа очереди.\n";
    cout << "Введите 3 для добавления элемента в начало очереди.\n";
    cout << "Введите 4 для добавления элемента в конец очереди.\n";
    cout << "Введите 5 для удаления элемента с заданым ключём.\n";
    cout << "Введите 6 для добавления нескольких элементов перед элементом с заданым номером.\n";
    cout << "Введите 7, чтобы удалить очередь.\n";
    cout << "Введите 8, чтобы записать данные в файл.\n";
    cout << "Введите 9, чтобы записать данные из файла в очередь.\n";
}

void menu() {
    int switch_n, size_queue, number, count;
    string key, file = "MyFile.txt";
    Queue* queue = new Queue;
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
            cout << "Введите размер очереди: ";
            cin >> size_queue;
            while (size_queue < 1){
                cout << "Размер списка должен быть от одного и более элементов! Введите размер: ";
                cin >> size_queue;
            }
            queue = CreateQueue(size_queue);
            break;
        case 2:
            ShowQueue(queue);
            break;
        case 3:
            AddElements(queue, 1, 1);
            break;
        case 4:
            cout << "Введите новую строку:\n";
            getline(cin, key); getline(cin, key);
            Push(queue, key);
            break;
        case 5:
            cout << "Введите ключ: ";
            getline(cin, key); getline(cin, key);
            RemoveElement(queue, key);
            break;
        case 6:
            cout << "Введите номер заданного элемента: ";
            cin >> number;
            while (number < 1 || number > queue->size) {
                cout << "Номер должен быть больше нуля и меньше " << queue->size + 1 << "!Введите номер : ";
                cin >> number;
            }
            cout << "Введите кол-во вводимых элементов: ";
            cin >> count;
            while (count < 1) {
                cout << "Кол-во должно быть больше нуля! Введите кол-во элементов: ";
                cin >> count;
            }
            AddElements(queue, count, number);
            break;
        case 7:
            while (!QueueIsEmpty(queue)) Pop(queue);
            cout << "Очередь удалёна!\n";
            break;
        case 8:
            if (!QueueIsEmpty(queue)) {
                size_queue = queue->size;
                PrintInFile(file, queue);
                cout << "Массив записан!\n";
            }
            else
                cout << "Очередь не создана!\n";
            break;
        case 9:
            if (size_queue != 0) {
                PrintFromFile(file, queue, size_queue);
                cout << "Данные из файла записаны!\n";
            }
            break;
        }
    } while (switch_n >= 0 && switch_n <= 9);
}

bool QueueIsEmpty(Queue* queue) {
    return queue == nullptr || queue->size == 0;
}

void Push(Queue* queue, string str) {
    if (!QueueIsEmpty(queue)) {
        Node* new_node = new Node;
        queue->size++;
        new_node->key = str;
        new_node->next = nullptr;
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    else {
        Node* new_node = new Node;
        queue->size = 1;
        new_node->key = str;
        queue->head = new_node;
        queue->tail = new_node;
    }
}

void Pop(Queue* queue) {
    Node* temp = queue->head;
    queue->head = temp->next;
    queue->size--;
    delete temp;
}

Queue* CreateQueue(int size) {
    Queue* queue = new Queue;
    string str;
    cout << "Введите ключи элементов:\n"; getline(cin, str);
    for (int i = 0; i < size; i++) {
        cout << i + 1 << '\t'; getline(cin, str);
        Push(queue, str);
    }
    return queue;
}

void ShowQueue(Queue* queue) {
    if (QueueIsEmpty(queue)) cout << "Очередь пуста!\n";
    else {
        Node* temp = queue->head;
        cout << "---------------------------\n";
        cout << "Начало -> ";
        while (temp != nullptr) {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "конец\n---------------------------\n";
    }
}

void RemoveElement(Queue* queue, string k) {
    if (QueueIsEmpty(queue)) {
        cout << "Очередь пуста!\n";
        return;
    }
    int i = 1;
    while (i <= queue->size) {
        if (queue->head->key != k) {
            Push(queue, queue->head->key);
            Pop(queue);
            i++;
        }
        else 
            Pop(queue);
    }
}

void AddElements(Queue* queue, int count, int number) {
    int i = 1;
    while (i < number) {
        Push(queue, queue->head->key);
        Pop(queue);
        i++;
    }
    string key;
    getline(cin, key);
    for (int j = 1; j <= count; j++) {
        cout << "Введите новый ключ: ";
        getline(cin, key);
        Push(queue, key);
    }
    for (i; i <= queue->size - count; i++) {
        Push(queue, queue->head->key);
        Pop(queue);
    }
}

void PrintInFile(string filename, Queue* queue) {
    ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        while (!QueueIsEmpty(queue)) {
            fout << queue->head->key;
            fout << '\n';
            Pop(queue);
        }
    }
    fout.close();
}

void PrintFromFile(string filename, Queue* queue, const int size) {
    ifstream fin;
    fin.open(filename);
    string key;
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        for (int i = 1; i <= size; i++) {
            fin >> key;
            Push(queue, key);
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