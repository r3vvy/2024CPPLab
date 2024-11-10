
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <conio.h> 
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <memory> 
using namespace std;
class Board {
public:
    Board();
    Board(int width, int height);
    Board(const Board& other);
    ~Board() = default;

    Board& operator=(const Board& other);
    bool operator==(const Board& other) const;
    friend std::istream& operator>>(std::istream& is, Board& board);
    friend std::ostream& operator<<(std::ostream& os, const Board& board);

    void PaintBoard();
    bool GetInput(int x, int y, int playerOrder);
    void Clear();
    bool ValidateInput(int x, int y);

private:
    int x, y;
    std::array<std::array<std::string, 3>, 3> board; 

    bool CheckWin(int lastX, int lastY, int playerOrder);
};
#endif