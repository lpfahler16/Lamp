#include "ButtonLamp.h"
#include <FastLED.h>

ButtonLamp::ButtonLamp()
    : Lamp()
{
    // Initialize potentiometer and button
    dial = new Dial(4, 3, 2, false);
    dial->Setup();
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

int ButtonLamp::Choose(int max)
{
    if (WillChoose())
    {
        dial->ResetButton();
        return Menu(max);
    }
    return -1;
}

bool ButtonLamp::WillChoose()
{
    dial->Update();
    return dial->button == UP;
}

int ButtonLamp::Menu(int max)
{
    int selected_program = 0;
    int prevEncode = 0;
    float section_size = float(LENGTH) / max;

    while (dial->button != UP)
    {

        int encoderVal = dial->pos; // Read encoder

        if (prevEncode > encoderVal && selected_program > 0)
        {
            selected_program--;
        }
        if (prevEncode < encoderVal && selected_program < max - 1)
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
    return selected_program;
}