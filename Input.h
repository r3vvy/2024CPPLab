#ifndef INPUT_H
#define INPUT_H

#include "GameData.h"
#include <iostream>

/**
 * @file Input.h
 * @brief Definiția clasei Input.
 *
 * Proiect: Tic-Tac-Toe
 * Autor: Moghildea Valeria
 * An: 2024
 */

 /**
  * @class Input
  * @brief Clasă ce gestionează intrările utilizatorului (versiunea consolă).
  *
  * Clasa `Input` cere utilizatorului să introducă coordonatele mutării și le validează folosind `GameData`.
  */
class Input
{
public:
    /**
     * @brief Constructorul clasei Input, initializează ordinea jucătorului.
     */
    Input();

    /**
     * @brief Destructorul clasei Input.
     */
    ~Input();

    /**
     * @brief Pornește interacțiunea cu utilizatorul pentru a adăuga mutări.
     */
    void StartInput();

private:
    /**
     * @brief Stochează ordinea curentă a jucătorului (1 sau 2).
     */
    int playerOrder;
};

#endif
