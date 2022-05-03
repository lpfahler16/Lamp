// 618 Lamp Header File
#ifndef Chooser_H
#define Chooser_H

class Chooser
{

public:
    // Picks a number from 0 to max - 1. Returns -1 if not ready to choose.
    virtual int Choose(int max) = 0;

    // Indicates whether ready to choose
    virtual bool WillChoose() = 0;
};

#endif