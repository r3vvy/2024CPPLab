#include "Input.h";

void Input::StartInput()
{
	int xPos;
	int yPos;
	cout << "Enter X pos:";
	cin >> xPos;
	cout << "Enter Y pos:";
	cin >> yPos;
	if (!board.ValidateInput(xPos, yPos))
		StartInput();
	if (board.GetInput(xPos, yPos, playerOrder))
	{
        board.PaintBoard();
		return;
	}
	board.PaintBoard();
	playerOrder = (playerOrder == 1) ? 2 : 1;
	StartInput();
}
Input::Input(Board& _board) :board(_board), playerOrder(1){}

Input::~Input()
{
}