
#include <iostream>
#include "Board.h"
#include "Input.h"
#include <memory>    
int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Tic-Tac-Toe");
    Board board;
    GameData gameData;
    int currentPlayer = 1;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                int x = (event.mouseButton.x - 50) / 100;
                int y = (event.mouseButton.y - 50) / 100;

                if (gameData.ValidateInput(x, y)) {
                    if (board.GetInput(x, y, currentPlayer)) {
                        window.close();  
                    }
                    currentPlayer = 3 - currentPlayer;  
                }
            }
        }

        board.PaintBoard(window);
    }

    return 0;
}


