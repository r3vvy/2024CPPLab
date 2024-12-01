#ifndef INPUT_H
#define INPUT_H

#include "GameData.h"
#include <iostream>

class Input
{
public:
    Input();
    ~Input();
    void StartInput();

private:
    int playerOrder;
};

#endif
