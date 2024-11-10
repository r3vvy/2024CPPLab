#include "Board.h"

Board::Board() : x(3), y(3), board{ {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}} } {}


Board::Board(int width, int height) : x(width), y(height) {
    std::for_each(board.begin(), board.end(), [](auto& row) { row.fill(" "); });
}


Board::Board(const Board& other) : x(other.x), y(other.y), board(other.board) {}


Board& Board::operator=(const Board& other) {
    if (this == &other) return *this;
    x = other.x;
    y = other.y;
    board = other.board;
    return *this;
}


bool Board::operator==(const Board& other) const {
    return x == other.x && y == other.y && board == other.board;
}


std::istream& operator>>(std::istream& is, Board& board) {
    for (auto& row : board.board) {
        for (auto& cell : row) {
            is >> cell;
        }
    }
    return is;
}


std::ostream& operator<<(std::ostream& os, const Board& board) {
    for (const auto& row : board.board) {
        for (size_t j = 0; j < board.x; ++j) {
            os << row[j];
            if (j < board.x - 1) os << " | ";
        }
        os << '\n';
        if (&row != &board.board.back()) os << "---------\n";
    }
    return os;
}


void Board::PaintBoard() {
    std::cout << *this;
}


void Board::Clear() {
    system("cls");
}


bool Board::ValidateInput(int x, int y) {
    bool result = (x >= 0 && x < 3 && y >= 0 && y < 3 && board[y][x] == " ");
    if (!result) {
        std::cout << "Invalid Position\n";
    }
    return result;
}


bool Board::CheckWin(int lastX, int lastY, int playerOrder) {
    std::string playerSymbol = (playerOrder == 2) ? "X" : "O";

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

bool Board::GetInput(int x, int y, int playerOrder) {
    board[y][x] = (playerOrder == 2) ? "X" : "O";
    return CheckWin(x, y, playerOrder);
}
