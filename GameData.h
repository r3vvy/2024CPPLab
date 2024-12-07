#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <array>
#include <string>

/**
 * @file GameData.h
 * @brief Definiția clasei GameData.
 *
 * Proiect: Tic-Tac-Toe
 * Autor: Moghildea Valeria
 * An: 2024
 */

 /**
  * @class GameData
  * @brief Clasă statică care gestionează starea internă a tablei de joc.
  *
  * Clasa GameData reține tabla de joc, oferă validări pentru mutări,
  * și permite setarea/stergerea valorilor pe tablă.
  */
class GameData {
public:
    /**
     * @brief Inițializează tabla de joc cu spații goale.
     */
    static void InitializeBoard();

    /**
     * @brief Validează dacă o mutare la coordonatele (x, y) este permisă.
     *
     * @param x Coordonata pe axa X (0-2).
     * @param y Coordonata pe axa Y (0-2).
     * @return true dacă mutarea este validă, false altfel.
     */
    static bool ValidateInput(int x, int y);

    /**
     * @brief Setează valoarea unui câmp al tablei.
     *
     * @param x Coordonata X a câmpului.
     * @param y Coordonata Y a câmpului.
     * @param value Simbolul de setat ("X", "O", sau " ").
     */
    static void SetCell(int x, int y, const std::string& value);

    /**
     * @brief Returnează o referință constantă la tabla de joc.
     *
     * @return Referință constantă la un array bidimensional 3x3 de string-uri.
     */
    static const std::array<std::array<std::string, 3>, 3>& GetBoard();

    /**
     * @brief Resetează complet tabla de joc, astfel încât toate valorile să fie goale.
     */
    static void ClearBoard();

private:
    /**
     * @brief Tabloul intern 3x3 ce reprezintă starea jocului.
     */
    static std::array<std::array<std::string, 3>, 3> board;
};

#endif
