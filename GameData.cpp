#include "GameData.h"
#include <algorithm>
#include <iostream>

// Definim tabla de joc
std::array<std::array<std::string, 3>, 3> GameData::board;

void GameData::InitializeBoard() {
    for (auto& row : board) {
        row.fill(" ");
    }
}

bool GameData::ValidateInput(int x, int y) {
    bool result = (x >= 0 && x < 3 && y >= 0 && y < 3 && board[y][x] == " ");
    if (!result) {
        std::cout << "Invalid Position\n";
    }
    return result;
}

void GameData::SetCell(int x, int y, const std::string& value) {
    board[y][x] = value;
}

const std::array<std::array<std::string, 3>, 3>& GameData::GetBoard() {
    return board;
}

void GameData::ClearBoard() {
    InitializeBoard();
}
