// 618 Lamp Header File
#ifndef Chooser_H
#define Chooser_H

class Chooser
{

public:
    virtual int Choose(int max) = 0;
    virtual bool WillChoose() = 0;
};

#endif