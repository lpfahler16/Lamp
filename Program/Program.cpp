#include "Program.h"

ButtonProgram::ButtonProgram(ButtonLamp *l)
{
    lamp = l;
}

StartProgram::StartProgram(ButtonLamp *l) : ButtonProgram(l) {}

void StartProgram::setup()
{
    for (int i = 0; i < 256; i++)
    {
        lamp->SetLamp(CRGB(i, i, i));
        lamp->Show();
        lamp->Delay(20);
    }
}

void StartProgram::loop() {}