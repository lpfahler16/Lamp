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

    int Choose(int max);
    bool WillChoose();
    void Delay(int mil);
};

#endif