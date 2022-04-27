// 618 Lamp Header File
#ifndef ButtonLamp_H
#define ButtonLamp_H

#include <FastLED.h>

#include "Lamp.h"

enum ButtonState
{
    DOWN,
    UP,
    IDLE
};

class ButtonLamp : public Lamp
{

private:
    enum ButtonState dial_button = IDLE;

    void CheckButton();
    void Run(void (*program)(ButtonLamp));
    void Menu();

public:
    void Start();

    void Delay(int mil);
};

#endif