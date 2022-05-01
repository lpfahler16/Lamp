// 618 Lamp Header File
#ifndef Dial_H
#define Dial_H

#include "Arduino.h"

enum ButtonState
{
    DOWN,
    UP,
    IDLE
};

class Dial
{

private:
    int PIN_A;
    int PIN_B;
    int BUTTON_PIN;
    bool rollover;
    int ROLLOVER_VALUE = 20;

    int last_a = LOW;
    int a = LOW;

    void UpdateButton();
    void UpdateEncoder();

public:
    Dial(int P_A, int P_B, int B_PIN, bool roll);

    int pos = 0;
    enum ButtonState button = IDLE;
    void Setup();
    void Update();
    void ResetButton();
};

#endif