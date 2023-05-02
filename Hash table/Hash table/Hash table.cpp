#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <fstream>
using namespace std;

string Names[5] = { "Андрей", "Даниил", "Кирилл", "Алексей", "Тимур" };
string Surnames[5] = { "Веснин", "Летов", "Бердышев", "Казаров", "Мальцев" };
string Patronymics[5] = { "Андреевич", "Даниилович", "Кириллович", "Алексеевич", "Тимурович" };
string Dates[5] = { "30.12.2003", "08.01.2004", "05.05.2004", "14.03.2002", "15.06.2003" };
string Passports[5] = { "57_17_683322", "45_23_344453", "12_34_344212", "78_45_346213", "56_16_657435" };

struct Human {
    string first_name = "NULL";
    string last_name = "NULL";
    string patronymic = "NULL";
    string date_of_birth = "NULL";
    string number_of_passport = "NULL";
    Human* next = nullptr;

    void SetHuman(string first_name, string last_name, string patronymic, string date_of_birth, string number_of_passport) {
        this->first_name = first_name;
        this->last_name = last_name;
        this->patronymic = patronymic;
        this->date_of_birth = date_of_birth;
        this->number_of_passport = number_of_passport;
    }
    void OutputHuman() {
        cout << "Name:\t" << this->last_name << ' ' << this->first_name << ' ' << this->patronymic << endl;
        cout << "Date_of_birth:\t" << this->date_of_birth << endl;
        cout << "Passport:\t" << this->number_of_passport << endl;
    }
    void CopyHuman(Human* copy) {
        this->first_name = copy->first_name;
        this->last_name = copy->last_name;
        this->patronymic = copy->patronymic;
        this->date_of_birth = copy->date_of_birth;
        this->number_of_passport = copy->number_of_passport;
        this->next = nullptr;
    }
};

struct List {
    int size = 0;
    Human* head = nullptr;
    Human* tail = nullptr;
};

bool ListIsEmpty(List* list);
void PushBack(List* list);
void PushFront(List* list);
List* CreateList(int size);
void ShowList(List* list);
void RemoveElement(List* list, string k);
void RemoveElement(List* list, int n);
void AddElement(List* list, int number);
void PrintInFile(string filename, List* list);
void PrintFromFile(string filename, List* list);


bool ListIsEmpty(List* list) {
    return list == nullptr || list->size == 0;
}

void PushBack(List* list) {
    Human* p = new Human;
    string name = Names[rand() % 5];
    string surname = Surnames[rand() % 5];
    string patr = Patronymics[rand() % 5];
    string date = Dates[rand() % 5];
    string passport = Passports[rand() % 5];
    p->SetHuman(name, surname, patr, date, passport);
    p->next = nullptr;
    if (ListIsEmpty(list)) {
        list->head = p;
        list->tail = p;
    }
    else if (list->size == 1) {
        list->tail->next = p;
        list->tail = p;
        list->head->next = list->tail;
    }
    else {
        list->tail->next = p;
        list->tail = p;
    }
    list->size++;
}

void PushFront(List* list) {
    Human* p = new Human;
    string name = Names[rand() % 5];
    string surname = Surnames[rand() % 5];
    string patr = Patronymics[rand() % 5];
    string date = Dates[rand() % 5];
    string passport = Passports[rand() % 5];
    p->SetHuman(name, surname, patr, date, passport);
    if (ListIsEmpty(list)) {
        list->head = p;
        list->tail = p;
    }
    else {
        p->next = list->head;
        list->head = p;
    }
    list->size++;
}

List* CreateList(int size) {
    List* list = new List;
    for (int i = 0; i < size; i++)
        PushBack(list);
    return list;
}

void ShowList(List* list) {
    if (ListIsEmpty(list)) cout << "Список пуст!\n";
    else {
        int i = 1;
        Human* temp = list->head;
        cout << "---------------------------\n";
        cout << "\tСписок\n";
        while (i <= list->size){
            temp->OutputHuman();
            temp = temp->next;
            ++i;
        }
        cout << "---------------------------\n";
    }
}

void RemoveElement(List* list, string k) {
    Human* temp = list->head;
    if (temp->date_of_birth == k) {
        list->head = temp->next;
        delete temp;
        list->size--;
        cout << "Элемент удалён!\n";
        return;
    }
    while (temp->next->date_of_birth != k) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        cout << "Элемент удалён!\n";
        Human* r = temp->next; //встать на удаляемый элемент
        temp->next = r->next; //изменить ссылку
        delete r;
        list->size--;
        r = temp->next; //встать на следующий
        return;
    }
    else {
        cout << "Элемент не найден!\n";
    }
}

void RemoveElement(List* list, int n) {
    Human* temp = list->head;
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

void PrintInFile(string filename, List* list) {
    ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        cout << "Информация записана в файл!" << endl;
        Human* p = list->head;
        for (int i = 0; i < list->size; i++) {
            fout << p->first_name << "\n";
            fout << p->last_name << "\n";
            fout << p->patronymic << "\n";
            fout << p->date_of_birth << "\n";
            fout << p->number_of_passport << "\n";
            p = p->next;
        }
    }
    fout.close();
}

void PrintFromFile(string filename, List* list) {
    ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        cout << "Не удалось открыть файл!\n";
    }
    else {
        cout << "Информация скопирована из файла!" << endl;
        string word1, word2, word3, word4, word5;
        Human* p, * r;
        p = new (Human);
        fin >> word1 >> word2 >> word3 >> word4 >> word5;
        p->SetHuman(word1, word2, word3, word4, word5);
        p->next = nullptr;
        list->head = p;
        list->size++;
        while (!fin.eof()) { 
            word1 = ""; word2 = ""; word3 = ""; word4 = ""; word5 = "";
            fin >> word1 >> word2 >> word3 >> word4 >> word5;
            r = new(Human);
            r->SetHuman(word1, word2, word3, word4, word5);
            if (word5 != "") {
                p->next = r;
                r->next = nullptr;
                p = r;
                list->size++;
            }
        }
    }
    fin.close();
}

void AddElement(List* list, int number) {
    int i = 1;
    string key;
    Human* temp = list->head;
    if (i == number) {
        PushFront(list);
        temp = list->head;
    }
    else {
        while (i + 1 != number) {
            temp = temp->next;
            i++;
        }
        Human* p = new Human;
        p->next = temp->next;
        temp->next = p;
        string name = Names[rand() % 5];
        string surname = Surnames[rand() % 5];
        string patr = Patronymics[rand() % 5];
        string date = Dates[rand() % 5];
        string passport = Passports[rand() % 5];
        p->SetHuman(name, surname, patr, date, passport);
        temp = p;
        list->size++;
    }
}

int hash_func(string pep, int size) {
    float num;
    num = stoi(pep.substr(0, 2)) + stoi(pep.substr(3, 2)) + stoi(pep.substr(6, 4));
    num *= 0.414141;
    num -= (int)num;
    num *= size;
    return (int)num;
}

Human** open_address_method(List* l) {
    int size = l->size, pos, collisions_count = 0;
    Human** table = new Human * [size];
    for (int i = 0; i < size; i++) {
        table[i] = new Human;
    }
    Human* pep = l->head;
    for (int i = 0; i < size; i++) {
        pos = hash_func(pep->date_of_birth, size);
        if (table[pos]->date_of_birth == "NULL") {
            table[pos] = pep;
            pep = pep->next;
        }
        else {
            while (table[pos]->date_of_birth != "NULL") {
                pos++;
                collisions_count++;
                if (pos >= size) pos = pos - size;
            }
            table[pos] = pep;
            pep = pep->next;
        }
    }
    cout << "Кол-во коллизий = " << collisions_count << endl;
    return table;
}

Human** chain_method(List* l) {
    int size = l->size, pos, collisions_count = 0;
    Human** table = new Human * [size];
    for (int i = 0; i < size; i++) table[i] = new Human;
    Human* curr = l->head;
    Human* pep = new Human, * r;
    pep->CopyHuman(curr);
    for (int i = 0; i < size; i++) {
        pos = hash_func(curr->date_of_birth, size);
        if (table[pos]->date_of_birth == "NULL") {
            table[pos] = pep;
        }
        else {
            collisions_count++;
            r = table[pos];
            pep->next = r;
            table[pos] = pep;
        }
        pep = new Human;
        if (curr->next != nullptr) {
            curr = curr->next;
            pep->CopyHuman(curr);
        }
    }
    cout << "Кол-во коллизий = " << collisions_count << endl;
    return table;
}

void print_hash(Human** table, int size, int type) {
    if (type == 1) for (int i = 0; i < size; i++) {
        table[i]->OutputHuman();
        cout << "-----------" << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << i << ":\n";
            Human* pep = table[i];
            do {
                pep->OutputHuman();
                pep = pep->next;
                cout << endl;
            } while (pep != nullptr);
            cout << "-----------" << endl;
        }
    }
}

void ShowMenu() {
    cout << "\t\tМеню\n";
    cout << "Введите 0 для заверщения работы программы.\n";
    cout << "Введите 1 для создания списка.\n";
    cout << "Введите 2 для показа списка.\n";
    cout << "Введите 3 для добавления элемента в начало списка.\n";
    cout << "Введите 4 для добавления элемента в конец списка.\n";
    cout << "Введите 5 для удаления элемента с заданым ключём.\n";
    cout << "Введите 6 для удаления элемента с заданым номером.\n";
    cout << "Введите 7 для добавления элемента с заданым номером.\n";
    cout << "Введите 8, чтобы удалить список.\n";
    cout << "Введите 9, чтобы записать данные в файл.\n";
    cout << "Введите 10, чтобы записать данные из файла в список.\n";
    cout << "Введите 11 для метода открытой адрессации.\n";
    cout << "Введите 12 для метода цепочек.\n";
}

void menu() {
    int switch_n, size_list, number, count;
    string key, file = "MyFile.txt";
    List* list = new List;
    Human** table;
    Human* pep;
    string date; int pos, counter = 0;
    bool flag;
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
            PushFront(list);
            break;
        case 4:
            PushBack(list);
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
            RemoveElement(list, number);
            break;
        case 7:
            cout << "Введите номер заданного элемента: ";
            cin >> number;
            while (number <= 0 || number > list->size) {
                cout << "Номер должен быть больше нуля и меньше " << list->size + 1 << "!Введите номер : ";
                cin >> number;
            }
            AddElement(list, number);
            break;
        case 8:
            while (!ListIsEmpty(list)) {
                RemoveElement(list, 1);
            }
            cout << "Список удалён!\n";
            break;
        case 9:
            if (!ListIsEmpty(list)) 
                PrintInFile(file, list);
            else
                cout << "Список не создан!\n";
            break;
        case 10:
            PrintFromFile(file, list);
            break;
        case 11:
            counter = 0;
            table = open_address_method(list);
            print_hash(table, list->size, 1);
            cout << "Введите дату рождения: ";
            getline(cin, date); getline(cin, date);
            while (date.length() != 10) {
                cout << "Введите дату рождения: ";
                getline(cin, date);
            }
            pos = hash_func(date, list->size);
            if (table[pos]->date_of_birth == date) {
                table[pos]->OutputHuman();
            }
            else {
                while (table[pos]->date_of_birth != date && counter < list->size) {
                    pos++; counter++;
                    if (pos >= list->size) pos = pos - list->size;
                }
                if (counter < list->size) table[pos]->OutputHuman();
                else cout << "Not found" << endl;
            }
            break;
        case 12:
            flag = false;
            table = chain_method(list);
            print_hash(table, list->size, 2);
            cout << "Введите дату рождения: ";
            getline(cin, date); getline(cin, date);
            while (date.length() != 10) {
                cout << "Введите дату рождения: ";
                getline(cin, date);
            }
            pos = hash_func(date, list->size);
            pep = table[pos];
            while (!flag && pep != nullptr) {
                if (pep->date_of_birth == date) flag = true;
                else pep = pep->next;
            }
            if (flag) pep->OutputHuman();
            else cout << "Not found" << endl;
            break;
        }
    } while (switch_n != 0);
}


int main(){
    system("color F0");
    srand(time(NULL));
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    menu();
    return 0;
}