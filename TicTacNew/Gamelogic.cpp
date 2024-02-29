#include "Gamelogic.h"
#include "Player.h"
#include <random>
#include "MyFunctions.h"
#include <algorithm>
#include <conio.h>




int Gamelogic::winCond()
{

std::vector<std::vector<std::string>> checkBoard = board1.getvPlayboard();
std::string winMark = " ";

board1.getIsTakenO();
board1.getIsTakenX();

// checkBoard.erase(checkBoard.begin()+1);

for (int i = 1; i < checkBoard.size(); i++)
{
    for (int j = 1; j < checkBoard[i].size();j++)
    {
        if(checkBoard[i][1] == checkBoard[i][2] && checkBoard[i][2]  == checkBoard[i][3] && (checkBoard[i][1] == "[X]" || checkBoard[i][1] == "[O]" ))
        {
            winMark = checkBoard[i][1];
        }
        if(checkBoard[1][j] == checkBoard[2][j] && checkBoard[2][j]  == checkBoard[3][j] && (checkBoard[1][j] == "[X]" || checkBoard[1][j] == "[O]" ))
        {
            winMark = checkBoard[1][j];
        }
    }
        if(checkBoard[1][1] == checkBoard[2][2] && checkBoard[2][2] == checkBoard[3][3] && (checkBoard[1][1] == "[X]" || checkBoard[1][1] == "[O]" ))
        {
            winMark = checkBoard[1][1];
        }
        if(checkBoard[1][3] == checkBoard[2][2] && checkBoard[2][2] == checkBoard[3][1]&& (checkBoard[1][3] == "[X]" || checkBoard[1][3] == "[O]" ))
        {
            winMark = checkBoard[1][3];
        }
}

if (winMark == "[X]")
{
    return -1;
}   
else if(winMark=="[O]")
{
    return 1;
}
else 
{
    return 0;
}




}

void Gamelogic::gameloop()
{
isRunning = true;
isPlayer1Turn = true;

while (isRunning == true) // Game Loop 
{
    if (isPlayer1Turn == true) // Player One Turn
    {
        std::string currentMove;
        std::cout << "Please Enter your Move\n";
        std::cin >> currentMove;
        std::transform(currentMove.begin(), currentMove.end(), currentMove.begin(), ::toupper);
        if (validInput(currentMove))
        {
            board1.updatePlayboard(currentMove,true);
            system("cls");
            board1.printBoard();
            isPlayer1Turn = false;
            isWon = winCond();
        }
        else 
        {
            std::cout << "Wrong input please Ensure there are only 2 Inputs\n";
        }

    }
    else 
    {
        if (player2.isPlayerOrHuman() == false)
        {
            //PVAI
            if (board1.saveCurrentPlayboard() == true)
            {
                std::string nextMoveAI;
                system("cls");
                board1.saveCurrentPlayboard();
                nextMoveAI = player2.calcMove(board1);
                board1.resetSavedPlayboard();
                board1.updatePlayboard(nextMoveAI,false);
                board1.saveCurrentPlayboard();
                board1.printBoard();
                isPlayer1Turn = true;
                isWon = winCond();

            }



        }
        else
        {
            // PVP
            std::string currentMove;
            std::cout << "Please Enter your Move\n";
            std::cin >> currentMove;
            std::transform(currentMove.begin(), currentMove.end(), currentMove.begin(), ::toupper);
            if (validInput(currentMove))
            {
                board1.updatePlayboard(currentMove,false);
                system("cls");
                board1.printBoard();
                isPlayer1Turn = true;
                winCond();
            }
        }


    }

}
}

Board Gamelogic::getBoardInstance()
{
return board1;
}

bool Gamelogic::validInput(std::string input)

{
std::vector<std::string> taken = board1.getIsTaken();
bool isNotAlreadyTaken = std::find(taken.begin(), taken.end(), input) != taken.end();
if (isNotAlreadyTaken == false)
{
    if (input.length() == 2)
    {

    
        std::vector<char> validCols = board1.getValidCols();
        std::vector<char> validRows = board1.getValidRows();

        bool isValidCols = std::find(validCols.begin(), validCols.end(), input[0]) != validCols.end();
        bool isValidRows = std::find(validRows.begin(), validRows.end(), input[1]) != validRows.end();

        bool isValid = isValidCols && isValidRows;
        return isValid;

    }
    else 
    {
        std::cout << "Wrong input please Ensure there are only 2 Inputs\n";
        return false;

    }
}
else 
{
    print("Invalid Move, Place already Taken");
    return false;
}

}