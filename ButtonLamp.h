// 618 Lamp Header File
#ifndef ButtonLamp_H
#define ButtonLamp_H

#include "Lamp.h"
#include "Dial.h"
#include "Chooser.h"

class ButtonLamp : public Lamp, public Chooser
{

private:
    int Menu(int num_programs);
    Dial *dial;

public:
    ButtonLamp();

    // Picks a number from 0 to max - 1. Returns -1 if dial button not pressed yet.
    int Choose(int max);

    // Indicates whether Lamp is ready to go into chooser mode
    bool WillChoose();

    // Delays mil miliseconds and checks for button presses
    void Delay(int mil);
};

#endif