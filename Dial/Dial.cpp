#include "Dial.h"

Dial::Dial(int P_A, int P_B, int B_PIN, bool roll)
{
    PIN_A = P_A;
    PIN_B = P_B;
    BUTTON_PIN = B_PIN;
    rollover = roll;
}

void Dial::Setup()
{
    pos = 0;
    pinMode(PIN_A, INPUT);
    digitalWrite(PIN_A, HIGH);
    pinMode(PIN_B, INPUT);
    digitalWrite(PIN_B, HIGH);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    ResetButton();
}

void Dial::Update()
{
    UpdateButton();
    UpdateEncoder();
}

void Dial::UpdateButton()
{
    int button_value = digitalRead(BUTTON_PIN); // Read button here
    switch (button)
    {
    case DOWN:
        if (button_value == HIGH)
        {
            button = UP;
        }
        break;
    case IDLE:
        if (button_value == LOW)
        {
            button = DOWN;
        }
        break;
    default:
        break;
    }
}

void Dial::UpdateEncoder()
{
    a = digitalRead(PIN_A);
    if ((last_a == LOW) && (a == HIGH))
    {
        if (digitalRead(PIN_B) == LOW)
            pos--;
        else
            pos++;

        if (rollover)
            if (pos < 0)
                pos = ROLLOVER_VALUE - 1;
        pos %= ROLLOVER_VALUE;
    }
    last_a = a;
}

void Dial::ResetButton()
{
    button = IDLE;
}