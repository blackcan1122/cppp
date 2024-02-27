#include "Player.h"
#include <iostream>
#include "Board.h"
#include "Gamelogic.h"
#include <algorithm>
#include <map>
#include <utility>


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
            if (validInput(currentMove, currentBoard) == true)
            {
                currentBoard.saveCurrentPlayboard();
                currentBoard.updatePlayboard(currentMove,false);
                currentBoard.printBoard();
                currentScore = minimax(currentBoard,0,false);
                currentBoard.resetSavedPlayboard();
                if (currentScore > bestScore)
                {
                    bestScore = currentScore;
                    bestMove = currentMove;
                }

            }

            currentMove.clear();
            
        }
        
    }
    currentBoard.updatePlayboard(bestMove,false);
    currentBoard.printBoard();
    return  bestMove;


}

bool Player::isPlayerOrHuman()
{
    return isPlayer;
        

}

bool Player::validInput(std::string input, Board& currentboard)

{
    std::vector<std::string> taken = currentboard.getIsTaken();
    bool isNotAlreadyTaken = std::find(taken.begin(), taken.end(), input) != taken.end();
    if (isNotAlreadyTaken == false)
    {
        if (input.length() == 2)
        {

        
            std::vector<char> validCols = currentboard.getValidCols();
            std::vector<char> validRows = currentboard.getValidRows();

            bool isValidCols = std::find(validCols.begin(), validCols.end(), input[0]) != validCols.end();
            bool isValidRows = std::find(validRows.begin(), validRows.end(), input[1]) != validRows.end();

            bool isValid = isValidCols && isValidRows;
            return isValid;

        }
        else 
        {
            
            return false;

        }
    }
    else 
    {
       
        return false;
    }

}


int Player::minimax(Board& currentBoard, int depth, bool isMaximizing)
{
    std::cout << depth << "\n";
    std::vector<std::string> strVRows = currentBoard.validRowsStr();
    std::vector<std::string> strVCols =currentBoard.validColStr();

    std::map<std::string, int> score{{"X",-1},{"O",1},{"Tie",0}};
    // Win Condition
    int result = winCond(currentBoard);
    if (result != score["Tie"])
    {
        currentBoard.resetSavedPlayboard();
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
                if (validInput(currentMove, currentBoard) == true)
                {
                    currentBoard.saveCurrentPlayboard();
                    currentBoard.updatePlayboard(currentMove,false);
                    currentBoard.printBoard();
                    currentScore = minimax(currentBoard, depth+1, false);
                    currentBoard.resetSavedPlayboard();

                    if (currentScore > bestScore)
                    {
                        bestScore = currentScore;
                    }

                }

                currentMove.clear();
                
            }
            
        }
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
                if (validInput(currentMove, currentBoard) == true)
                {
                    currentBoard.saveCurrentPlayboard();
                    currentBoard.updatePlayboard(currentMove,true);
                    currentBoard.printBoard();
                    currentScore = minimax(currentBoard, depth+1, true);
                    currentBoard.resetSavedPlayboard();
                    if (currentScore < bestScore)
                    {
                        bestScore = currentScore;
                    }

                }

                currentMove.clear();
                
            }
            
        }
    }
}



int Player::winCond(Board& currentboard)
{

    std::vector<std::vector<std::string>> checkBoard = currentboard.getvPlayboard();
    std::string winMark = " ";

    currentboard.getIsTakenO();
    currentboard.getIsTakenX();
    int fullboard;
    fullboard = currentboard.getIsTakenO().size() + currentboard.getIsTakenX().size();

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
    if(fullboard = 9)
    {
        return 0;
    }

    
    

}