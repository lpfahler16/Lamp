// 618 Lamp Header File
#ifndef Dial_H
#define Dial_H

#include "Arduino.h"

// Indicates the state of the button
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
    // Creates button with pin values and whether or not there should be rollover of encoder values
    Dial(int P_A, int P_B, int B_PIN, bool roll);

    // Current position of the encoder
    int pos = 0;

    // Current state of the button
    enum ButtonState button = IDLE;

    // Sets up Arduino pins and resets button / position
    void Setup();

    // Read encoder and button values and update values
    void Update();

    // Resets button to idle
    void ResetButton();
};

#endif