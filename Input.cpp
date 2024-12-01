#include "Input.h"
#include <algorithm>

Input::Input() : playerOrder(1) {
    GameData::InitializeBoard();
}

Input::~Input() {}

void Input::StartInput() {
    int xPos;
    int yPos;

    std::cout << "Enter X pos: ";
    std::cin >> xPos;
    std::cout << "Enter Y pos: ";
    std::cin >> yPos;

    if (!GameData::ValidateInput(xPos, yPos)) {
        std::cout << "Invalid input. Try again.\n";
        StartInput();
        return;
    }

    GameData::SetCell(xPos, yPos, (playerOrder == 1) ? "O" : "X");

    const auto& board = GameData::GetBoard();


    bool win = false;

 
    win = std::all_of(board[yPos].begin(), board[yPos].end(),
        [&](const std::string& cell) { return cell == board[yPos][xPos]; });


    if (!win) {
        win = std::all_of(board.begin(), board.end(),
            [&](const std::array<std::string, 3>& row) { return row[xPos] == board[yPos][xPos]; });
    }


    if (!win && xPos == yPos) {
        win = (board[0][0] == board[1][1] && board[1][1] == board[2][2]);
    }
    if (!win && xPos + yPos == 2) {
        win = (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
    }

 
    bool draw = std::all_of(board.begin(), board.end(), [](const auto& row) {
        return std::all_of(row.begin(), row.end(), [](const std::string& cell) { return cell != " "; });
        });

    if (win) {
        std::cout << "Player " << playerOrder << " wins!\n";
        return;
    }
    else if (draw) {
        std::cout << "It's a draw!\n";
        return;
    }

 
    playerOrder = (playerOrder == 1) ? 2 : 1;
    StartInput();
}
