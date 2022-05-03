# LED Lamp

An Arduino library made to control an LED lamp. The library is built off of the FastLED library, using its functionality to turn lights on and off. This library provides simplified functionality for controlling rings, strips, and individual LEDs within the lamp.

### Dependencies
- FastLED

## Lamp Class

Create a lamp object to control the lights in a lamp. LEDs within the lamp can be set to a CRGB, CHSV, or HEX color. You can also get the current color of an LED. Available methods can be found in [Lamp.h](/Lamp.h).

### Example .INO
```c++
#include <Lamp.h>

Lamp *lamp = new Lamp();
int i;

void setup() {
  i = 0;
}

void loop() {
  for(int j = 0; j < 255; j++) {
    int pos = 3*(j+i) % (255*3);
    lamp->SetRings(pos, pos + 2, CHSV(j, 255, 255));
  }
  lamp->Show();
  lamp->Delay(100);
  i++;
  i %= 255;
}
```
## ButtonProgram Class

ButtonProgram is an abstract class that represents a program with a ButtonLamp. This class can be extended and the setup() and loop() methods can be implemented to represent a specific program. Available methods can be found in [Program.h](/Program.h).

### Example
```c++
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
```

## Program Controller

A program controller can be used to switch between programs on the arduino. The controller takes in a Chooser and checks with the Chooser whether to switch to a new program (Note: ButtonLamp implements the Chooser interface). The controller can be run in the loop. Available methods can be found in [ProgramController.h](/ProgramController.h).

### Example .INO
```c++
ButtonLamp *lamp = new ButtonLamp();
ProgramController *controller = new ProgramController(lamp);

void setup() {
  StartProgram *p = new StartProgram(lamp);
  RainbowProgram *p2 = new RainbowProgram(lamp);
  BouncingBallProgram *p3 = new BouncingBallProgram(lamp);
  controller->AddProgram(p);
  controller->AddProgram(p2);
  controller->AddProgram(p3);
}

void loop() {
  controller->Run();
}
```

## UML Diagram

![UML Diagram](/UML_Diagram.png)
