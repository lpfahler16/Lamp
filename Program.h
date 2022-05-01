// 618 Lamp Header File
#ifndef Program_H
#define Program_H

#include "ButtonLamp.h"

class Program
{

public:
    // pure virtual function
    virtual void setup() = 0;
    virtual void loop() = 0;
};

class ButtonProgram : public Program
{
protected:
    ButtonLamp *lamp;

public:
    ButtonProgram(ButtonLamp *l);
};

class ProgramNode
{
public:
    Program *program;
    ProgramNode *next;
};

#endif