#include <cassert>
#include <iostream>
#include "../GameData.h"

/**
 * @brief Teste de bază pentru clasa GameData.
 */
    int main() {
    // Test: InitializeBoard
    GameData::InitializeBoard();
    const auto& board = GameData::GetBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(board[i][j] == " ");
        }
    }
    std::cout << "Test InitializeBoard passed.\n";

    // Test: ValidateInput (poziție validă goală)
    assert(GameData::ValidateInput(1, 1) == true);
    std::cout << "Test ValidateInput valid position passed.\n";

    // Test: SetCell și apoi ValidateInput (poziție ocupată)
    GameData::SetCell(1, 1, "X");
    assert(GameData::ValidateInput(1, 1) == false);
    std::cout << "Test ValidateInput invalid position passed.\n";

    // Test: ClearBoard
    GameData::ClearBoard();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(GameData::GetBoard()[i][j] == " ");
        }
    }
    std::cout << "Test ClearBoard passed.\n";

    std::cout << "All tests passed!\n";
    return 0;
}
