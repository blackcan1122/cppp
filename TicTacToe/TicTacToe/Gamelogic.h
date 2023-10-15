#pragma once
#include "Board.h"
#include "Player.h"

class Gamelogic
{
private:
    // Member Attribute
    Player player1;
    Player player2;
    Board board1;
    bool isPlayer1Turn;
    bool isRunning;



public:

    // Constructor
    Gamelogic() : player1(true), player2(false), board1(), isPlayer1Turn(true)
    {

    }

    // Ruft die funktion des bretts ab

    void callBoardUpdate(std::string input);
    void callDrawBoard();


    // Ruft Funktionen der Player Klasse

    bool callPlayerHumanState(Player& playerController);

    void gameloop();

    bool winCond();
    
};

