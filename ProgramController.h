// 618 Lamp Header File
#ifndef ProgramController_H
#define ProgramController_H

#include "Program.h"
#include "Chooser.h"

class ProgramController
{

private:
    bool set_up = false;
    ProgramNode *programs = NULL;
    Program *program = NULL;
    Chooser *chooser;

    int ChooseProgram(int num); // Returns -1 if unsuccessful

protected:
    int num_programs = 0;

public:
    ProgramController(Chooser *choose_object);

    void Run();
    void AddProgram(Program *p);
};

#endif