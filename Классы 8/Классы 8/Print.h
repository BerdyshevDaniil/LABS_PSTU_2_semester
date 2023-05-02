#pragma once
#include "Object.h"
class Print :
    public Object
{
public:
    Print(void);
    Print(string, string);
    Print(const Print&);
    virtual ~Print(void);

    void Show();
    void Input();

    string Get_name() { return name; }
    string Get_author() { return author; }
    void Set_name(string N) { name = N; }
    void Set_author(string A) { author = A; }
    
    Print& operator=(const Print& p);

protected:
    string name;
    string author;
};

