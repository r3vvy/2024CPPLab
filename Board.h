#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <conio.h> 

using namespace std;
class Board {
public:
    Board();  
    ~Board(); 

    void PaintBoard();  
    bool GetInput(int x,int y,int playerOrder);
    void Clear();
    bool ValidateInput(int x, int y);
private:
    int x, y; 
    char board[3][3]; 
    bool CheckWin(int lastX,int lastY,int playerOrder);
};
#endif