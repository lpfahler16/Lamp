// 618 Lamp Header File
#ifndef ButtonLamp_H
#define ButtonLamp_H

#include <FastLED.h>

#include "ProgramLamp.h"
#include "Program.h"
#include "Dial.h"

class ButtonLamp : public ProgramLamp
{

private:
public:
    ButtonLamp();

    Dial *dial;
    void Run();
    void Menu();
    void Delay(int mil);
};

#endif