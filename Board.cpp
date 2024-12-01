#include "Board.h"
#include <iostream>

Board::Board() {
    GameData::InitializeBoard();
}

void Board::PaintBoard(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    const float cellSize = 100.f;
    const float offsetX = 50.f;
    const float offsetY = 50.f;

    sf::RectangleShape line(sf::Vector2f(300.f, 5.f));
    line.setFillColor(sf::Color::Black);

    for (int i = 1; i < 3; ++i) {
        line.setPosition(offsetX, offsetY + i * cellSize);
        window.draw(line);
    }

    line.setSize(sf::Vector2f(5.f, 300.f));
    for (int i = 1; i < 3; ++i) {
        line.setPosition(offsetX + i * cellSize, offsetY);
        window.draw(line);
    }

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Failed to load font\n";
        return;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Black);

    const auto& board = GameData::GetBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != " ") {
                text.setString(board[i][j]);
                text.setPosition(offsetX + j * cellSize + 25, offsetY + i * cellSize + 10);
                window.draw(text);
            }
        }
    }

    window.display();
}

bool Board::GetInput(int x, int y, int playerOrder) {
    if (!GameData::ValidateInput(x, y)) {
        return false;
    }

    GameData::SetCell(x, y, (playerOrder == 2) ? "X" : "O");
    return CheckWin(x, y, playerOrder);
}

bool Board::CheckWin(int lastX, int lastY, int playerOrder) {
    const std::string& playerSymbol = (playerOrder == 2) ? "X" : "O";
    const auto& board = GameData::GetBoard();

    bool winRow = std::all_of(board[lastY].begin(), board[lastY].end(), [&](const std::string& cell) { return cell == playerSymbol; });
    bool winCol = std::all_of(board.begin(), board.end(), [&](const std::array<std::string, 3>& row) { return row[lastX] == playerSymbol; });
    bool winDiag1 = (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol);
    bool winDiag2 = (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol);

    if (winRow || winCol || winDiag1 || winDiag2) {
        std::cout << "Player " << playerOrder << " wins!\n";
        return true;
    }

    bool draw = std::all_of(board.begin(), board.end(), [](const auto& row) {
        return std::all_of(row.begin(), row.end(), [](const std::string& cell) { return cell != " "; });
        });

    if (draw) {
        std::cout << "It's a draw!\n";
        return true;
    }

    return false;
}
