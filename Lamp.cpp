#include "Lamp.h"
#include <FastLED.h>

Lamp::Lamp()
{
    FastLED.addLeds<WS2812, 7, GRB>(strip1, LENGTH);
    FastLED.addLeds<WS2812, 8, GRB>(strip2, LENGTH);
    FastLED.addLeds<WS2812, 9, GRB>(strip3, LENGTH);
    FastLED.clear();
}

Lamp::~Lamp() {}

void Lamp::SetLED(int strip, int led, struct CRGB color)
{
    if (led < 0 || led >= LENGTH)
    {
        return;
    }

    switch (strip)
    {
    case 0:
        strip0[led] = color;
        break;
    case 1:
        strip1[led] = color;
        break;
    case 2:
        strip2[led] = color;
        break;
    default:
        return;
    }
}

struct CRGB Lamp::GetLED(int strip, int led)
{
    if (led < 0 || led >= LENGTH)
    {
        return CRGB(0, 0, 0);
    }

    switch (strip)
    {
    case 1:
        return strip1[led];
        break;
    case 2:
        return strip2[led];
        break;
    case 3:
        return strip3[led];
        break;
    default:
        return CRGB(0, 0, 0);
    }
}

void Lamp::SetLEDs(int strip, int from, int to, struct CRGB color)
{
    for (int i = from; i < to; i++)
    {
        SetLED(strip, i, color);
    }
}

void Lamp::SetStrip(int strip, struct CRGB color)
{
    SetLEDs(strip, 0, LENGTH, color);
}

void Lamp::SetRing(int ring, struct CRGB color)
{
    SetLED(0, ring, color);
    SetLED(1, ring, color);
    SetLED(2, ring, color);
}

void Lamp::SetRings(int from, int to, struct CRGB color)
{
    for (int i = from; i < to; i++)
    {
        SetRing(i, color);
    }
}

void Lamp::SetLamp(struct CRGB color)
{
    SetRings(0, LENGTH, color);
}

void Lamp::Show()
{
    FastLED.show();
}

void Lamp::Clear()
{
    FastLED.clear();
}

void Lamp::Delay(int mil)
{
    delay(mil);
}