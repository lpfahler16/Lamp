// 618 Lamp Header File
#ifndef ButtonLamp_H
#define ButtonLamp_H

#include "Lamp.h"
#include "Dial/Dial.h"
#include "Chooser/Chooser.h"

class ButtonLamp : public Lamp, public Chooser
{

private:
    int Menu(int num_programs);
    Dial *dial;

public:
    ButtonLamp();

    int Choose(int max);
    void Delay(int mil);
};

#endif