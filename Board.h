#ifndef BOARD_H
#define BOARD_H

#include "GameData.h"
#include <SFML/Graphics.hpp>
#include <string>

/**
 * @file Board.h
 * @brief Definiția clasei Board.
 *
 * Proiect: Tic-Tac-Toe
 * Autor: Moghildea Valeria
 * An: 2024
 */

 /**
  * @class Board
  * @brief Clasă responsabilă cu afișarea tablei de joc și gestionarea desenării elementelor.
  *
  * Această clasă utilizează SFML pentru a desena liniile și simbolurile jucătorilor pe o fereastră.
  */
class Board {
public:
    /**
     * @brief Constructorul clasei Board, inițializează tabla cu valori implicite.
     */
    Board();

    /**
     * @brief Desenează tabla de joc în fereastra SFML.
     *
     * @param window Referință la fereastra SFML în care se desenează.
     */
    void PaintBoard(sf::RenderWindow& window);

    /**
     * @brief Înregistrează intrarea unui jucător (mutarea pe tablă).
     *
     * @param x Coordonata x a mutării (0-2).
     * @param y Coordonata y a mutării (0-2).
     * @param playerOrder Numărul jucătorului (1 sau 2).
     * @return true dacă mutarea a dus la încheierea jocului (victorie sau remiză), false altfel.
     */
    bool GetInput(int x, int y, int playerOrder);

private:
    /**
     * @brief Verifică dacă mutarea curentă a unui jucător a generat o situație de câștig.
     *
     * @param lastX Coordonata x a ultimei mutări.
     * @param lastY Coordonata y a ultimei mutări.
     * @param playerOrder Numărul jucătorului care a făcut mutarea.
     * @return true dacă jucătorul a câștigat sau este remiză, false altfel.
     */
    bool CheckWin(int lastX, int lastY, int playerOrder);
};

#endif
