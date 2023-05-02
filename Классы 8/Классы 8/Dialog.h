#pragma once
#include "Event.h"
#include "Vector.h"

class Dialog : 
	public Vector
{
public:
	Dialog(void);
	~Dialog(void);//деструктор
	void GetEvent(TEvent& event);//получить событие 
	void Execute();//главный цикл обработки событий 
	void HandleEvent (TEvent& event); //обработчик 
	void ClearEvent (TEvent& event);//очистить событие 
	bool Valid();//проверка атрибута EndState
	void EndExec();//обработка события «конец работы» 
protected:
	int EndState;
};