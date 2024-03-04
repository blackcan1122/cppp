#pragma once
#include "Board.h"
#include "Player.h"
#include "MyFunctions.h"

class Gamelogic
{
private:
    // Member Attribute
    Player player1;
    Player player2;
    Board board1;
    bool isPlayer1Turn;
    bool isRunning;
    int isWon = 0;
    int whoWon = 0;




public:

    // Constructor
    Gamelogic(bool AIorNot) : player1(true), player2(AIorNot), board1(), isPlayer1Turn(true)
    {
        gameloop();
    }
    // Deconstructor
    ~Gamelogic()
    {
        print("Game1 Was Terminated");
    }

    // Ruft die funktion des bretts ab

    bool validInput(std::string& input);


    // Ruft Funktionen der Player Klasse

    void gameloop();

    int winCond();

    Board getBoardInstance();

    void setIsRunning(const int& isWonReturn);

    bool getIsRunning();
    
};

