#ifndef BOARD_H
#define BOARD_H

#include "GameData.h"
#include <SFML/Graphics.hpp>
#include <string>

class Board {
public:
    Board();
    void PaintBoard(sf::RenderWindow& window);
    bool GetInput(int x, int y, int playerOrder);

private:
    bool CheckWin(int lastX, int lastY, int playerOrder);
};

#endif
