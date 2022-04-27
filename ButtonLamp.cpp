#include "ButtonLamp.h"
#include <FastLED.h>

// void ButtonLamp::Start()
// {
//     while (true)
//     {
//         try
//         {
//             CheckButton();
//         }
//         catch (const char *msg)
//         {
//             Menu();
//             Run();
//         }
//         delay(20);
//     }
// }

void ButtonLamp::Delay(int mil)
{
    int interval = 20;
    int m = mil;
    while (m >= interval)
    {
        CheckButton();
        delay(interval);
        m -= interval;
    }
    CheckButton();
    delay(m);
}

void ButtonLamp::CheckButton()
{
    int button_value = 0; // Read button here
    switch (dial_button)
    {
    case UP:
        dial_button = IDLE;
        // Throw error
        break;
    case DOWN:
        if (button_value == 0)
        {
            dial_button = UP;
        }
        break;
    case IDLE:
        if (button_value == 1)
        {
            dial_button = DOWN;
        }
        break;
    default:
        break;
    }
}