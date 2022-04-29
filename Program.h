// 618 Lamp Header File
#ifndef Program_H
#define Program_H

#include "Lamp.h"

class Program
{

protected:
    Lamp *lamp;

public:
    Program(Lamp *l)
    {
        lamp = l;
    }

    // pure virtual function
    virtual void setup() = 0;
    virtual void loop() = 0;
};

class StartProgram : public Program
{
public:
    StartProgram(Lamp *l) : Program(l) {}

    void setup()
    {
        for (int i = 0; i < 256; i++)
        {
            lamp->SetLamp(CRGB(i, i, i));
            lamp->Show();
            lamp->Delay(20);
        }
    }

    void loop() {}
};

class ProgramNode
{
public:
    Program *program;
    ProgramNode *next;
};

#endif