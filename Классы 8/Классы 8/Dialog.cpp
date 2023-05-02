#include "Dialog.h"

//конструктор
Dialog::Dialog(void) :Vector() {
	EndState = 0;
}
//деструктор 
Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
	string OpInt = "m+-szq"; //строка содержит коды операций 
	string s;
	char code;
	cout << '>';
	cin >> s; code = s[0];//первый символ команды 
	if (OpInt.find(code) >= 0) { //является ли символ кодом операции
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake; break;//создать группу
		case '+': event.command = cmAdd; break;//добавить объект в группу 
		case '-': event.command = cmDel; break;//удалить объект из группы 
		case 's': event.command = cmShow; break;//просмотр группы 
		case 'z': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break; //конец работы
		}
	}
	else event.what = evNothing;//пустое событие 
}

void Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //получить событие 
		HandleEvent(event); //обработать событие
	} while (Valid()); 
}

bool Dialog::Valid() {
	return EndState == 0;
}

void Dialog::ClearEvent(TEvent & event) {
	event.what = evNothing;//пустое событие 
}

void Dialog::EndExec() {
	EndState = 1;
}
//обработчик событий
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake://создание группы 
			cout << "Enter size: ";
			cin >> size;
			beg = new Object * [size];//выделяем память под массив указателей 
			cur = 0; //текущая позиция
			ClearEvent(event);//очищаем событие 
			break;
		case cmAdd://добавление 
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Del(); //удаление 
			ClearEvent(event);
			break;
		case cmShow:
			Show(); //просмотр 
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec(); //выход 
			ClearEvent(event);
			break;
		case cmGet:
			Get_Name();
			ClearEvent(event);
			break;
		};
	};
}

