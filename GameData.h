#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <array>
#include <string>

class GameData {
public:
    static void InitializeBoard();
    static bool ValidateInput(int x, int y);
    static void SetCell(int x, int y, const std::string& value);
    static const std::array<std::array<std::string, 3>, 3>& GetBoard();
    static void ClearBoard();

private:
    static std::array<std::array<std::string, 3>, 3> board; 
};

#endif