// 618 Lamp Header File
#ifndef ExampleProgram_H
#define ExampleProgram_H

#include "Program.h"

/*
 * StartProgram
 * AUTHOR: Logan Pfahler
 * DATE: 5/1/2022
 *
 * PARAMS
 * ButtonLamp *l    -> lamp pointer
 *
 * DESCRIPTION
 * Fades in from off to white. A good program to be the first in a program controller.
 */
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

/*
 * ColorProgram
 * AUTHOR: Logan Pfahler
 * DATE: 5/1/2022
 *
 * PARAMS
 * ButtonLamp *l    -> lamp pointer
 * CRGB c           -> color to display on the lamp
 *
 * DESCRIPTION
 * Sets the lamp to a solid color c.
 */
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

/*
 * RainbowProgram
 * AUTHOR: Logan Pfahler
 * DATE: 5/1/2022
 *
 * PARAMS
 * ButtonLamp *l    -> lamp pointer
 *
 * DESCRIPTION
 * Moves a gradient of colors up the lamp, giving a fading up effect.
 */
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

/*
 * BouncingBallProgram
 * AUTHOR: Logan Pfahler
 * DATE: 5/1/2022
 *
 * PARAMS
 * ButtonLamp *l    -> lamp pointer
 *
 * DESCRIPTION
 * Bounces a ball at a random starting veloctiy. Repeats once the ball gets below a certain velocity
 */
class BouncingBallProgram : public ButtonProgram
{

public:
    BouncingBallProgram(ButtonLamp *l) : ButtonProgram(l) {}

    float GAP = 0.015;
    float pos = 0;

    float velocity;
    float gravity;
    float del;
    float cons_energy;
    float vmin;
    float vmax;

    void setup()
    {
        vmin = 2;
        vmax = 7;
        gravity = 9.81;
        del = 10;
        cons_energy = 0.8;
    }

    void loop()
    {
        if (pos == 0 && abs(velocity) < 0.75)
            velocity = randomVelocity();

        lamp->SetLamp(CRGB(100, 100, 100));
        draw();
        bounce();
        lamp->Delay(del);
    }

    // Updates the positon and velocity of the ball for a change of del seconds
    void bounce()
    {
        pos += (velocity * del / 1000) / GAP;
        velocity -= gravity * del / 1000;

        if (pos < 0)
        {
            velocity = -1 * velocity * cons_energy;
            pos = 0;
        }
    }

    // Displays the ball on the lamp
    void draw()
    {
        float p_d = pos - floor(pos);
        lamp->SetRing(pos - 1, CRGB(255 * (1 - p_d), 0, 0));
        lamp->SetRings(pos, pos + 2, CRGB(255, 0, 0));
        lamp->SetRing(pos + 2, CRGB(255 * (p_d), 0, 0));
        lamp->Show();
    }

    // Picks a random velocity from vmin to vmax
    float randomVelocity()
    {
        float v = (rand() % int((vmax - vmin) * 10) + (vmin * 10)) / 10.0;
        return v;
    }
};

#endif