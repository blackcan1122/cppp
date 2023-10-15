#include "Gamelogic.h"
#include <random>
#include "MyFunctions.h"


void Gamelogic::callBoardUpdate(std::string input)
{

    board1.updatePlayboard(input);

}

void Gamelogic::callDrawBoard()
{
    board1.printBoard();
}

bool Gamelogic::callPlayerHumanState(Player& playerController)
{
    return playerController.isPlayerOrHuman(playerController);

}

bool Gamelogic::winCond()
{
    std::vector<std::vector<std::string>> checkBoard = board1.getvPlayboard();

    //checkBoard[0].clear();
    checkBoard.resize

    //checkBoard[0][0].clear();
    //checkBoard[1][0].clear();
    //checkBoard[2][0].clear();



    for (const auto& row : checkBoard)
    {
        for (const std::string& cell : row) {
            std::cout << cell;
        }
        std::cout << '\n'; // Move to the next line for the next row
    }

    return true;
}

void Gamelogic::gameloop()
{
    isRunning = true;
    isPlayer1Turn = true;

    if (callPlayerHumanState(player2) == true)
        // Hier Beginnt PvP
    {
        while (isRunning)
        {

            callDrawBoard();






            isRunning = exitCond();
        }
    }
    else
        // Hier beginnt PvAI
    {
        while (isRunning)
        {

            callDrawBoard();






            isRunning = exitCond();
        }

    }

}
