#include "ProgramController.h"

ProgramController::ProgramController(Chooser *choose_object)
{
    chooser = choose_object;
}

void ProgramController::Run()
{
    if (program == NULL)
        return;

    // Run setup if necessary
    if (!set_up)
    {
        program->setup();
        set_up = true;
    }

    // Run the program loop
    program->loop();

    // Choose a new program if appropriate
    if (chooser->WillChoose())
    {
        int p = chooser->Choose(num_programs);
        if (p != -1)
            ChooseProgram(p);
    }
}

void ProgramController::AddProgram(Program *p)
{
    if (programs == NULL)
    {
        ProgramNode *new_node = new ProgramNode();
        programs = new_node;
        programs->program = p;
        programs->next = NULL;
        program = p;
        num_programs = 1;
        return;
    }

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

int ProgramController::ChooseProgram(int num)
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