
#include <iostream>
#include "Board.h"
#include "Input.h"
#include <memory>    
int main()
{
    auto board1 = std::make_shared<Board>();
    cout << "Initial board1:" << endl;
    cout << *board1; 

    auto board2 = std::make_shared<Board>(3, 2);
    cout << "Initial board2 (created with parameters):" << endl;
    cout << *board2;

    cout << "Enter the values for board2:" << endl;
    cin >> *board2; 
    cout << "Updated board2:" << endl;
    cout << *board2;

   
    auto board3 = std::make_shared<Board>(*board2);
    cout << "board3 (copy of board2):" << endl;
    cout << *board3;

   
    *board1 = *board3;
    cout << "board1 (after assignment from board3):" << endl;
    cout << *board1;

 
    if (*board1 == *board3) {
        cout << "board1 and board3 are equal!" << endl;
    }
    else {
        cout << "board1 and board3 are not equal!" << endl;
    }
}


