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

bool Player::validInputAI(std::string input, Board& currentboard)
{

    char charcordA = toupper(input[0]);
    char charcordB = input[1];


    int cordA = charcordA - 'A'+1;
    int cordB = charcordB - '0'+1;

    if (currentboard.getvPlayboard()[cordB][cordA] == "[X]" || currentboard.getvPlayboard()[cordB][cordA] == "[O]")
    {
        return false;
    }
    else if (currentboard.getvPlayboard()[cordB][cordA] == "[ ]")
    {
        return true;
    }
    {
        return false;
    }

}

std::string Player::calcMove(Board& currentBoard)
{
    loopCount = 0;
    int bestScore = -2;
    int currentScore;
    std::string bestMove;
    std::string currentMove;

    std::vector<std::string> strVRows = currentBoard.validRowsStr();
    std::vector<std::string> strVCols =currentBoard.validColStr();
    // Alle möglichen Moves definieren
    for (int i = 0; i < strVRows.size(); i++)
    {
        for (int j = 0; j < strVCols.size(); j++)
        {
            loopCount++;
            currentMove = strVCols[j]+strVRows[i];           

            //Validierung ob das Feld bereits belegt ist
            if (validInputAI(currentMove, currentBoard) == true)
            {
                currentBoard.updatePlayboardForSimulation(currentMove,false);
                currentScore = minimax(currentBoard,0,false);
                currentBoard.resetPlayboardForRecursion(currentMove); 
                if (currentScore > bestScore)
                {
                    bestScore = currentScore;
                    bestMove = currentMove;
                }

            }
        }
        
    }
    std::cout << "Amount of Loops: " << loopCount << "\n";
    return  bestMove;


}

int Player::minimax(Board& currentBoard, int depth, bool isMaximizing)
{
    loopCount++;
    std::vector<std::string> strVRows = currentBoard.validRowsStr();
    std::vector<std::string> strVCols = currentBoard.validColStr();

    std::map<std::string, int> score{{"X",-1},{"O",1},{"Tie",0}};
    // Win Condition
    int result = winCond(currentBoard);
    if (result == score["X"] || result == score["O"] )
    {
        return result;
        
    }
    else if (result == 0)
    {
        return result;
    }
    // Maximazing Player
    else if (isMaximizing == true)
    {
        int bestScore = -2;
        int currentScore;
        std::string currentMove;


        // Alle möglichen Moves definieren
        for (int i = 0; i < strVRows.size(); i++)
        {
            for (int j = 0; j < strVCols.size(); j++)
            {
                currentMove = strVCols[j]+strVRows[i];           

                //Validierung ob das Feld bereits belegt ist
                if (validInputAI(currentMove, currentBoard) == true)
                {
                    currentBoard.updatePlayboardForSimulation(currentMove,false);
                    currentScore = minimax(currentBoard, depth+1, false);
                    currentBoard.resetPlayboardForRecursion(currentMove);

                    bestScore = std::max(currentScore,bestScore);
                }
            }
        }
        return bestScore;
    }

    // Minimizing Player
    else 
    {
        int bestScore = 2;
        int currentScore;
        std::string currentMove;


        // Alle möglichen Moves definieren
        for (int i = 0; i < strVRows.size(); i++)
        {
            for (int j = 0; j < strVCols.size(); j++)
            {
                currentMove = strVCols[j]+strVRows[i];           

                //Validierung ob das Feld bereits belegt ist
                if (validInputAI(currentMove, currentBoard) == true)
                {
                    currentBoard.updatePlayboardForSimulation(currentMove,true);
                    currentScore = minimax(currentBoard, depth+1, true);
                    currentBoard.resetPlayboardForRecursion(currentMove);

                    
                    bestScore = std::min(currentScore,bestScore);
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


    bool fullboard = false;
    int emptyBoard;
    emptyBoard = currentboard.getEmptyCells();
    if (emptyBoard == 0)
    {
        fullboard = true;
    }

    
    for (int i = 1; i <= 3; i++) 
    {
        if (checkBoard[i][1] == checkBoard[i][2] && checkBoard[i][2] == checkBoard[i][3] && (checkBoard[i][1] == "[X]" || checkBoard[i][1] == "[O]")) {
            winMark = checkBoard[i][1];
            break; // Sobald eine Gewinnbedingung gefunden wurde, kann die Schleife abgebrochen werden
        }
    }
    for (int j = 1; j <= 3; j++) 
    {
        if (checkBoard[1][j] == checkBoard[2][j] && checkBoard[2][j] == checkBoard[3][j] && (checkBoard[1][j] == "[X]" || checkBoard[1][j] == "[O]")) {
            winMark = checkBoard[1][j];
            break; // Sobald eine Gewinnbedingung gefunden wurde, kann die Schleife abgebrochen werden
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