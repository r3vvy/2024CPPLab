#ifndef INPUT_H
#define INPUT_H
#include "Board.h"
class Input
{
public:
	Input(Board& _board);
	~Input();
	void StartInput();
private:
    Board& board;
	int playerOrder;
};
#endif