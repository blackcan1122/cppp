#include "Player.h"
#include <iostream>
#include "Board.h"
#include "Gamelogic.h"
#include <algorithm>
#include <map>
#include <utility>


bool Player::isPlayerOrHuman()
{
    return isPlayer;
        

}

//
//Check if Input is Valid based on string
//
bool Player::validInputAI(std::string input, Board& currentboard)
{
    // String to 2D Vector Conversion
    char charcordA = toupper(input[0]);
    char charcordB = input[1];


    int cordA = charcordA - 'A'+1;
    int cordB = charcordB - '0'+1;

    // When its Taken
    if (currentboard.getvPlayboard()[cordB][cordA] == "[X]" || currentboard.getvPlayboard()[cordB][cordA] == "[O]")
    {
        return false;
    }

    // When its Empty
    else if (currentboard.getvPlayboard()[cordB][cordA] == "[ ]")
    {
        return true;
    }
    // shouldn't be happening, but in case something went wrong
    {
        return false;
        std::cout << "OOPS Something went really wrong\n";
        std::cout << "ValidInputAI Wrong Return\n";
    }

}

//
// Function to calculate the move for the AI and also calling the minimax Algorithm
//
std::string Player::calcMove(Board& currentBoard)
{
    //loopCount = 0;  // Debug for Counting iterations

    int bestScore = INT_MIN;
    int currentScore; 

    std::string bestMove;
    std::string currentMove;

    std::vector<std::string> strVRows = currentBoard.validRowsStr();    // Dynamic getting all valid Rows (A,B,C...) instead of hardcoding it for a bigger sized playboard
    std::vector<std::string> strVCols =currentBoard.validColStr();  // Dynamic getting all valid Rows (A,B,C...) instead of hardcoding it for a bigger sized playboard

    // Variables for the Alpha - Beta Pruning optimization
    int alpha = INT_MIN;
    int beta = INT_MAX;

    // Iterating through the 2D Vector (Playboard)
    for (int i = 0; i < strVRows.size(); i++)
    {
        for (int j = 0; j < strVCols.size(); j++)
        {
            loopCount++;
            currentMove = strVCols[j]+strVRows[i];           

            //Validation if the field is already occupied
            if (validInputAI(currentMove, currentBoard) == true)
            {
                currentBoard.updatePlayboardForSimulation(currentMove,false);   // Calling a own Function for Updating the Playboard without taking items to the Taken List
                currentScore = minimax(currentBoard, 0, alpha, beta, false);    // Minimax Algorithm with alpha beta Pruning
                currentBoard.resetPlayboardForRecursion(currentMove);           // Reset the Playboard in a way to function with the recursive behavior

                if (currentScore > bestScore)
                {
                    bestScore = currentScore;
                    bestMove = currentMove;
                }

            }
        }
        
    }
    //std::cout << "Amount of Loops: " << loopCount << "\n";
    return  bestMove;


}

int Player::minimax(Board& currentBoard, int depth, int alpha, int beta, bool isMaximizing)
{
    loopCount++;
    std::vector<std::string> strVRows = currentBoard.validRowsStr();
    std::vector<std::string> strVCols = currentBoard.validColStr();

    // Win Condition
    std::map<std::string, int> score{{"X",-1},{"O",1},{"Tie",0}};
    int result = winCond(currentBoard);
    if (result == score["X"] || result == score["O"] )
    {
        return result;
        
    }
    else if (result == 0)
    {
        return result;
    }

    //
    // Maximizing Player
    //
    else if (isMaximizing)
    {
        int bestScore = -2;
        int currentScore;
        std::string currentMove;

        // Iterating through the 2D Vector (Playboard)
        for (int i = 0; i < strVRows.size(); i++)
        {
            for (int j = 0; j < strVCols.size(); j++)
            {
                currentMove = strVCols[j]+strVRows[i];           

                //Validation if the field is already occupied
                if (validInputAI(currentMove, currentBoard) == true)
                {
                    currentBoard.updatePlayboardForSimulation(currentMove,false);
                    currentScore = minimax(currentBoard, depth+1, alpha, beta, false);
                    currentBoard.resetPlayboardForRecursion(currentMove);

                    bestScore = std::max(currentScore, bestScore);
                    alpha = std::max(alpha, bestScore);
                    if (beta <= alpha)
                        break; // Beta cutoff
                }
            }
        }
        return bestScore;
    }

    //
    // Minimizing Player
    //
    else 
    {
        int bestScore = 2;
        int currentScore;
        std::string currentMove;

         // Iterating through the 2D Vector (Playboard)
        for (int i = 0; i < strVRows.size(); i++)
        {
            for (int j = 0; j < strVCols.size(); j++)
            {
                currentMove = strVCols[j]+strVRows[i];           

                //Validation if the field is already occupied
                if (validInputAI(currentMove, currentBoard) == true)
                {
                    currentBoard.updatePlayboardForSimulation(currentMove,true);
                    currentScore = minimax(currentBoard, depth+1, alpha, beta, true);
                    currentBoard.resetPlayboardForRecursion(currentMove);

                    bestScore = std::min(currentScore, bestScore);
                    beta = std::min(beta, bestScore);
                    if (beta <= alpha)
                        break; // Alpha cutoff
                }
            }
        }
        return bestScore;
    }
}


int Player::winCond(Board& currentboard)
{

    std::vector<std::vector<std::string>> checkBoard = currentboard.getvPlayboard();
    std::string winMark = " ";

    //
    // Check if the Playboard is full (Could be moved to board class?)
    //
    bool fullboard = false;
    int emptyBoard;
    emptyBoard = currentboard.getEmptyCells();
    if (emptyBoard == 0)
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
    // Win Return Score Value depending on how good that move is for the AI
    //
    if (winMark == "[X]")
    {
        return -1;
    }   
    else if(winMark=="[O]")
    {
        return 1;
    }
    else if(fullboard == true)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

// function for adding a score to a player (Logic Mistake, since the Player is part of the Gamelogic it also gets destroyed when the game ends...)
void Player::setScore(int Score)
{
    scoreCount = scoreCount + Score;
}