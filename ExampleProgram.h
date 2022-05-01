// 618 Lamp Header File
#ifndef ExampleProgram_H
#define ExampleProgram_H

#include "Program.h"

class StartProgram : public ButtonProgram
{
public:
    StartProgram(ButtonLamp *l) : ButtonProgram(l) {}

    void setup()
    {
        for (int i = 0; i < 256; i++)
        {
            lamp->SetLamp(CRGB(i, i, i));
            lamp->Show();
            lamp->Delay(20);
        }
    }

    void loop() {}
};

class ColorProgram : public ButtonProgram
{
private:
    int i = 0;
    CRGB color;

public:
    ColorProgram(ButtonLamp *l, CRGB c) : ButtonProgram(l)
    {
        color = c;
    }

    void setup()
    {
        lamp->SetLamp(color);
        lamp->Show();
    }

    void loop() {}
};

class RainbowProgram : public ButtonProgram
{
private:
    int i = 0;

public:
    RainbowProgram(ButtonLamp *l) : ButtonProgram(l) {}

    void setup() {}

    void loop()
    {
        for (int j = 0; j < 255; j++)
        {
            int pos = 3 * (j + i) % (255 * 3);
            lamp->SetRings(pos, pos + 2, CHSV(j, 255, 255));
        }
        lamp->Show();
        lamp->Delay(100);
        i++;
        i %= 255;
    }
};

#endif