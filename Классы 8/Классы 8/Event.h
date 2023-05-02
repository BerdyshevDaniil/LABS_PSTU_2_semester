#pragma once
const int evNothing = 0;  //пустое событие 
const int evMessage = 100;//непустое событие 
const int cmAdd = 1;      // + 
const int cmDel = 2;      // -
const int cmGet = 3;      // z 
const int cmShow = 4;     // s
const int cmMake = 6;     // m
const int cmQuit = 101;   // q

struct TEvent {
	int what;    //наличие события 
	int command; //тип комманды
};