
#include <iostream>
#include "Board.h";
#include "Input.h";

int main()
{
    Board board1;
    cout << "Initial board1:" << endl;
    cout << board1;

    Board board2(3, 2);
    cout << "Initial board2 (created with parameters):" << endl;
    cout << board2;

    cout << "Enter the values for board2:" << endl;
    cin >> board2;
    cout << "Updated board2:" << endl;
    cout << board2;

   
    Board board3(board2);
    cout << "board3 (copy of board2):" << endl;
    cout << board3;

    board1 = board3;
    cout << "board1 (after assignment from board3):" << endl;
    cout << board1;

    if (board1 == board3) {
        cout << "board1 and board3 are equal!" << endl;
    }
    else {
        cout << "board1 and board3 are not equal!" << endl;
    }
}