#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <conio.h> 

using namespace std;

class Board {
public:
    Board();  
    Board(const Board& other); 
    Board(int width, int height);  
    ~Board();  

    Board& operator=(const Board& other);  
    bool operator==(const Board& other) const;  
    friend istream& operator>>(istream& is, Board& board);  
    friend ostream& operator<<(ostream& os, const Board& board); 

    void PaintBoard();
    bool GetInput(int x, int y, int playerOrder);
    void Clear();
    bool ValidateInput(int x, int y);

private:
    int x, y; 
    char board[3][3];  

    bool CheckWin(int lastX, int lastY, int playerOrder);
};

#endif
