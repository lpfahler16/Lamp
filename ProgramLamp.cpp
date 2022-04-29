#include "ProgramLamp.h"

ProgramLamp::ProgramLamp()
    : Lamp()
{
    // Create start program object
    StartProgram *p = new StartProgram(this);
    program = p;

    // Create first program node with start program
    ProgramNode *new_node = new ProgramNode();
    programs = new_node;
    programs->program = p;
    programs->next = NULL;
}

void ProgramLamp::Run()
{

    // Run setup if necessary
    if (!set_up)
    {
        program->setup();
        set_up = true;
    }

    // Run the program loop
    program->loop();
}

void ProgramLamp::AddProgram(Program *p)
{
    // Find the last program in the list
    ProgramNode *last_program = programs;
    while (last_program->next != NULL)
    {
        last_program = last_program->next;
    }

    // Create a new node for the program and add it
    ProgramNode *new_node = new ProgramNode();
    new_node->program = p;
    new_node->next = NULL;
    last_program->next = new_node;
    num_programs++;
}

int ProgramLamp::ChooseProgram(int num)
{
    // Find the given number program (indexing at 0)
    ProgramNode *curr_program = programs;
    while (num > 0)
    {
        if (curr_program->next != NULL)
        {
            curr_program = curr_program->next;
            num--;
        }
        else
        {
            return -1;
        }
    }

    // Set the running program to the program
    program = curr_program->program;
    set_up = false;
    return 0;
}