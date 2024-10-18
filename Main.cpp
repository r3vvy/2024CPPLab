
#include <iostream>
#include "Board.h";
#include "Input.h";

int main()
{
    Board board;
    board.PaintBoard();
    Input input(board);
    input.StartInput();
}