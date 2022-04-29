// 618 Lamp Header File
#ifndef ProgramLamp_H
#define ProgramLamp_H

#include <FastLED.h>

#include "Lamp.h"
#include "Program.h"

class ProgramLamp : public Lamp
{

private:
    bool set_up = false;
    ProgramNode *programs;
    Program *program;

protected:
    int num_programs = 1;

public:
    ProgramLamp();

    void Run();
    void AddProgram(Program *p);
    int ChooseProgram(int num); // Returns -1 if unsuccessful
};

#endif