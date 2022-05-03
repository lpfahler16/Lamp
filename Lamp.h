// 618 Lamp Header File
#ifndef Lamp_H
#define Lamp_H

#include <FastLED.h>

const static unsigned int NUM_LEDS = 53;

class Lamp
{

private:
    struct CRGB strip0[NUM_LEDS];
    struct CRGB strip1[NUM_LEDS];
    struct CRGB strip2[NUM_LEDS];

public:
    const static unsigned int LENGTH = NUM_LEDS;

    Lamp(); // Will take in inputs at somepoint
    ~Lamp();

    // Sets the given ring on the lamp to the color. Does nothing if out of bounds
    void SetRing(int ring, struct CRGB color);

    // Sets the given ring range, non-inclusive, on the lamp to the color. Does nothing if out of bounds
    void SetRings(int from, int to, struct CRGB color);

    // Sets the lamp to the color. Does nothing if out of bounds
    void SetLamp(struct CRGB color);

    // Sets the given led on the lamp to the color. Does nothing if out of bounds
    void SetLED(int strip, int led, struct CRGB color);

    // Sets the given led range, non-inclusive, on the lamp to the color. Does nothing if out of bounds
    void SetLEDs(int strip, int from, int to, struct CRGB color);

    // Sets the given strip on the lamp to the color. Does nothing if out of bounds
    void SetStrip(int strip, struct CRGB color);

    // Shows the color changes on the lamp
    void Show();

    // Turns off all leds on the lamp
    void Clear();

    // Delays for mil miliseconds
    void Delay(int mil);

    // Gets the color at the given LED. Returns black if out of bounds
    struct CRGB GetLED(int strip, int led);
};

#endif