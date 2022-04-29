#include "ButtonLamp.h"
#include <FastLED.h>

ButtonLamp::ButtonLamp()
    : ProgramLamp()
{
    // Initialize potentiometer and button
    dial = new Dial(4, 3, 2, false);
    dial->Setup();
}

void ButtonLamp::Run()
{

    ProgramLamp::Run();

    // Update button and check if menu should be run
    dial->Update();
    if (dial->button == UP)
    {
        dial->ResetButton();
        Menu();
    }
}

void ButtonLamp::Delay(int mil)
{
    int interval = 20;
    int m = mil;
    while (m > interval)
    {
        dial->Update();
        delay(interval);
        m -= interval;
    }
    dial->Update();
    delay(m);
}

void ButtonLamp::Menu()
{
    int selected_program = 0;
    int prevEncode = 0;
    int section_size = LENGTH / num_programs;

    while (dial->button != UP)
    {

        int encoderVal = dial->pos; // Read encoder

        if (prevEncode > encoderVal && selected_program > 0)
        {
            selected_program--;
        }
        if (prevEncode < encoderVal && selected_program < num_programs - 1)
        {
            selected_program++;
        }
        prevEncode = encoderVal;

        SetLamp(CRGB(0, 0, 0));
        SetRings(selected_program * section_size, (selected_program + 1) * section_size, CRGB(255, 255, 255));
        Show();

        dial->Update();
    }
    dial->Setup();
    Clear();
    ChooseProgram(selected_program);
}