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
    std::vector<std::vector<std::string>> Playboard = currentboard.getvPlayboard();
    char charcordA = toupper(input[0]);
    char charcordB = input[1];


    int cordA = charcordA - 'A'+1;
    int cordB = charcordB - '0'+1;

    if (Playboard[cordB][cordA] == "[X]" || Playboard[cordB][cordA] == "[O]")
    {
        return false;
    }
    else if (Playboard[cordB][cordA] == "[ ]")
    {
        return true;
    }
    {
        return false;
    }

}

std::string Player::calcMove(Board& currentBoard)
{
    int bestScore = -INFINITY;
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
    return  bestMove;


}

int Player::minimax(Board& currentBoard, int depth, bool isMaximizing)
{
    std::vector<std::string> strVRows = currentBoard.validRowsStr();
    std::vector<std::string> strVCols =currentBoard.validColStr();

    std::map<std::string, int> score{{"X",-1},{"O",1},{"Tie",0}};
    // Win Condition
    int result = winCond(currentBoard);
    if (result != score["Tie"])
    {
        return result;
        
    }

    // Maximazing Player
    else if (isMaximizing == true)
    {
        int bestScore = -INFINITY;
        int currentScore;
        std::string currentMove;

        std::vector<std::string> strVRows = currentBoard.validRowsStr();
        std::vector<std::string> strVCols =currentBoard.validColStr();
        bestScore=-INFINITY;
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
                    currentBoard.printBoard();
                    std::cout << depth << "\n";
                    currentScore = minimax(currentBoard, depth+1, false);
                    currentBoard.resetPlayboardForRecursion(currentMove);

                    if (currentScore > bestScore)
                    {
                        bestScore = currentScore;
                    }
                }
            }
            
        }
        return bestScore;
    }

    // Minimizing Player
    else 
    {
        int bestScore = -INFINITY;
        int currentScore;
        std::string currentMove;

        std::vector<std::string> strVRows = currentBoard.validRowsStr();
        std::vector<std::string> strVCols =currentBoard.validColStr();
        bestScore=-INFINITY;
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
                    currentBoard.printBoard();
                    std::cout << depth << "\n";
                    currentScore = minimax(currentBoard, depth+1, true);
                    currentBoard.resetPlayboardForRecursion(currentMove);
                    if (currentScore < bestScore)
                    {
                        bestScore = currentScore;
                    }
                }
            }
            
        }
        return bestScore;
    }
}


// Iwas geht hier vorsich kein plan sollt ich mal checken
int Player::winCond(Board& currentboard)
{

    std::vector<std::vector<std::string>> checkBoard = currentboard.getvPlayboard();
    std::string winMark = " ";

    currentboard.getIsTakenO();
    currentboard.getIsTakenX();
    bool fullboard = false;
    if (currentboard.getEmptyCells().size() == 0)
    {
        fullboard = true;
    }

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
    if(winMark=="[O]")
    {
        return 1;
    }
    if(fullboard == true)
    {
        return 0;
    }

    
    

}