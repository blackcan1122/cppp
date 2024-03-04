#include "Gamelogic.h"
#include "Player.h"
#include <random>
#include "MyFunctions.h"
#include <algorithm>
#include <conio.h>




int Gamelogic::winCond()
{


    std::string WonAscii = R"(
 /$$      /$$  /$$$$$$  /$$   /$$
| $$  /$ | $$ /$$__  $$| $$$ | $$
| $$ /$$$| $$| $$  \ $$| $$$$| $$
| $$/$$ $$ $$| $$  | $$| $$ $$ $$
| $$$$_  $$$$| $$  | $$| $$  $$$$
| $$$/ \  $$$| $$  | $$| $$\  $$$
| $$/   \  $$|  $$$$$$/| $$ \  $$
|__/     \__/ \______/ |__/  \__/)";

    std::string TIEAscii = R"(
 /$$$$$$$$ /$$$$$$ /$$$$$$$$
|__  $$__/|_  $$_/| $$_____/
   | $$     | $$  | $$      
   | $$     | $$  | $$$$$   
   | $$     | $$  | $$__/   
   | $$     | $$  | $$      
   | $$    /$$$$$$| $$$$$$$$
   |__/   |______/|________/)";


    std::vector<std::vector<std::string>> checkBoard = board1.getvPlayboard();
    std::string winMark = " ";

    bool fullboard = false;

    //
    // Check if the Playboard is full (Could be moved to board class?)
    //
    if (board1.getEmptyCells() == 0)
    {
        fullboard = true;
    }

    //
    // Check Horizontal Lines
    //
    for (int i = 1; i <= 3; i++) 
    {
        if (checkBoard[i][1] == checkBoard[i][2] && checkBoard[i][2] == checkBoard[i][3] && (checkBoard[i][1] == "[X]" || checkBoard[i][1] == "[O]")) {
            winMark = checkBoard[i][1];
            break;
        }
    }

    //
    // Check for Vertical Lines
    //
    for (int j = 1; j <= 3; j++) 
    {
        if (checkBoard[1][j] == checkBoard[2][j] && checkBoard[2][j] == checkBoard[3][j] && (checkBoard[1][j] == "[X]" || checkBoard[1][j] == "[O]")) {
            winMark = checkBoard[1][j];
            break;
        }
    }

    //
    //Check for Diagonal Lines (has to be changed for 5x5 or 7x7 Playboards)
    //
    if(checkBoard[1][1] == checkBoard[2][2] && checkBoard[2][2] == checkBoard[3][3] && (checkBoard[1][1] == "[X]" || checkBoard[1][1] == "[O]" ))
    {
        winMark = checkBoard[1][1];
    }
    if(checkBoard[1][3] == checkBoard[2][2] && checkBoard[2][2] == checkBoard[3][1]&& (checkBoard[1][3] == "[X]" || checkBoard[1][3] == "[O]" ))
    {
        winMark = checkBoard[1][3];
    }

    //
    // Win Return Values
    //
    if (winMark == "[X]")
    {
        player1.setScore(1);
        print ("X has");
        print (WonAscii);
        return -1;
    }   
    else if(winMark=="[O]")
    {
        player2.setScore(1);
        print ("O Has");
        print (WonAscii);
        return 1;
    }
    else if(fullboard == true)
    {
        print (TIEAscii);
        return 0;
    }
    else
    {
        return 2;   // Return 2 for continuing the game
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
                setIsRunning(winCond());  
            }
        }
        else 
        {
            if (player2.isPlayerOrHuman() == false)
            {
                //
                //PVAI
                //
                if (board1.saveCurrentPlayboard() == true)
                {
                    std::string nextMoveAI;
                    board1.saveCurrentPlayboard();  // Saves current Playboard and Current Taken List for Restoring
                    nextMoveAI = player2.calcMove(board1);  // Calc AI Moves with recursive function
                    system("cls");
                    board1.resetSavedPlayboard();   // Restores saved Playboard and Taken List
                    board1.updatePlayboard(nextMoveAI,false);
                    std::cout << "AI takes " << nextMoveAI << "\n";
                    board1.printBoard();
                    setIsRunning(winCond());
                    isPlayer1Turn = true;

                }
            }
            else
            {
                //
                // PVP
                //
                std::string currentMove;
                std::cout << "Please Enter your Move\n";
                std::cin >> currentMove;
                std::transform(currentMove.begin(), currentMove.end(), currentMove.begin(), ::toupper);
                if (validInput(currentMove))
                {
                    board1.updatePlayboard(currentMove,false);
                    system("cls");
                    board1.printBoard();
                    setIsRunning(winCond());
                    isPlayer1Turn = true;
                }
            }
        }
    }
}

//
// Returns the Instance of the Board Class used in this Gamelogic Instance
//
Board Gamelogic::getBoardInstance()
{
return board1;
}

//
// Checks if the Input made is valid (Could be moved to Board Class and adapted to work with the AI)
//
bool Gamelogic::validInput(std::string& input)
{
    std::vector<std::string> taken = board1.getIsTaken();
    bool isNotAlreadyTaken = std::find(taken.begin(), taken.end(), input) != taken.end();   // Check if the input Move E.g. "A0" is already in the "isTaken" memberVariable
    if (isNotAlreadyTaken == false)
    {
        if (input.length() == 2)
        {

        
            std::vector<char> validCols = board1.getValidCols();
            std::vector<char> validRows = board1.getValidRows();

            bool isValidCols = std::find(validCols.begin(), validCols.end(), input[0]) != validCols.end();  // Check if the input Letter is also a valid choice (dynamic calculated for 3x3,5x5 and 7x7 boards)
            bool isValidRows = std::find(validRows.begin(), validRows.end(), input[1]) != validRows.end();  // Check if the input Number is also a valid choice (dynamic calculated for 3x3,5x5 and 7x7 boards)

            bool isValid = isValidCols && isValidRows;
            if (isValid == false)
            {
                print("Wrong input please Ensure there are only 2 Inputs E.g. 'A0' ");
            }
            return isValid;

        }
        else // When its Longer than 2 Inputs
        {
            print("Wrong input please Ensure there are only 2 Inputs E.g. 'A0' ");
            return false;

        }
    }
    else // When Place is already Taken
    {
        print("Invalid Move, Place already Taken");
        return false;
    }

}

void Gamelogic::setIsRunning(const int&
 isWonReturn)
{
    if (isWonReturn == 0 || isWonReturn == 1 || isWonReturn == -1)
    {
        isRunning = false;
    }
    else
    {
        isRunning = true;
    }
}

bool Gamelogic::getIsRunning()
{
    return isRunning;
}