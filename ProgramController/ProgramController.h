// 618 Lamp Header File
#ifndef ProgramController_H
#define ProgramController_H

#include "Program/Program.h"
#include "Chooser/Chooser.h"

class ProgramController
{

private:
    bool set_up = false;
    ProgramNode *programs;
    Program *program;
    Chooser *chooser;

    int ChooseProgram(int num); // Returns -1 if unsuccessful

protected:
    int num_programs = 1;

public:
    ProgramController(Chooser *choose_object, ButtonLamp *lamp);

    void Run();
    void AddProgram(Program *p);
};

#endif