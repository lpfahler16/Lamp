// 618 Lamp Header File
#ifndef Lamp_H
#define Lamp_H

#include <FastLED.h>

const static unsigned int NUM_LEDS = 53;

class Lamp
{

private:
    struct CRGB strip1[NUM_LEDS];
    struct CRGB strip2[NUM_LEDS];
    struct CRGB strip3[NUM_LEDS];

public:
    const static unsigned int LENGTH = NUM_LEDS;

    Lamp(); // Will take in inputs at somepoint
    ~Lamp();

    void SetRing(int ring, struct CRGB color);
    // void SetRing(int ring, CHSV color);
    void SetRings(int from, int to, struct CRGB color);
    // void SetRings(int from, int to, CHSV color);
    void SetLamp(struct CRGB color);
    // void SetLamp(CHSV color);
    void SetLED(int strip, int led, struct CRGB color);
    // void SetLED(int strip, int led, CHSV color);
    void SetLEDs(int strip, int from, int to, struct CRGB color);
    // void SetLEDs(int strip, int from, int to, CHSV color);
    void SetStrip(int strip, struct CRGB color);
    // void SetStrip(int strip, CHSV color);
    void Show();
    void Clear();

    void Delay(int mil);

    struct CRGB GetLED(int strip, int led);
};

#endif