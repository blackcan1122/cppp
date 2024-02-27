#include "Board.h"
#include "Gamelogic.h"
#include "MyFunctions.h"
#include <iostream>
#include <locale>


Board::Board()
{

    generatePlayboard();
    validCol();
    validRows();
    printBoard();

}


void Board::generatePlayboard()
{

    vPlayboard = {

    {"   ", " A ", " B ", " C "},
    {"0  ", "[ ]", "[ ]", "[ ]"},
    {"1  ", "[ ]", "[ ]", "[ ]"},
    {"2  ", "[ ]", "[ ]", "[ ]"}

    };



}




void Board::printBoard()
{
    for (const auto& row : vPlayboard) 
    {
        for (const std::string& cell : row) {
            std::cout << cell;
        }
        std::cout << '\n'; // Move to the next line for the next row
    }

}


std::vector<std::vector<std::string>> Board::getvPlayboard()
{
    return vPlayboard;

}

std::vector<std::string> Board::getIsTaken()
{
    std::vector<std::string> isTakenCombined;
    isTakenCombined.reserve(isTakenX.size()+isTakenO.size());
    isTakenCombined.insert(isTakenCombined.end(), isTakenX.begin(), isTakenX.end());
    isTakenCombined.insert(isTakenCombined.end(), isTakenO.begin(), isTakenO.end());

    return isTakenCombined;
}

std::vector<std::string> Board::getIsTakenX()
{
    return isTakenX;
}
std::vector<std::string> Board::getIsTakenO()
{
    return isTakenO;
}

std::vector<std::string> Board::addItemtoIsTakenX(std::string itemToAdd)
{
    isTakenX.push_back(itemToAdd);
    return isTakenX;
}

std::vector<std::string> Board::addItemtoIsTakenO(std::string itemToAdd)
{
    isTakenO.push_back(itemToAdd);
    return isTakenO;
}


void Board::updatePlayboard(std::string input, bool PlayerOne)
{

    // Beispiel B1

    if(PlayerOne == true)
    {
        addItemtoIsTakenX(input);
    }
    else 
    {
        addItemtoIsTakenO(input);
    }
    
    char charcordA = toupper(input[0]);
    char charcordB = input[1];


    int cordA = charcordA - 'A'+1;
    int cordB = charcordB - '0'+1;

    std::vector<std::vector<std::string>> tempvPlayboard = getvPlayboard();

    if(PlayerOne == true)
    {
        tempvPlayboard[cordB][cordA] = "[X]";
    }
    else
    {
        tempvPlayboard[cordB][cordA] = "[O]";
    }
    
    vPlayboard = tempvPlayboard;

}

void Board::validCol()
{
    std::vector<char> tempCol;
    std::vector<std::vector<std::string>> tempvPlayboard = getvPlayboard();
    for (size_t i = 1; i < tempvPlayboard[0].size(); ++i)
    {
        tempCol.push_back(tempvPlayboard[0][i][1]);
    }


    vCol = tempCol;

}

void Board::validRows()
{
    std::vector<char> tempRow;
    std::vector<std::vector<std::string>> tempvPlayboard = getvPlayboard();
    for (size_t i = 1; i < tempvPlayboard.size(); ++i)
    {
        tempRow.push_back(tempvPlayboard[i][0][0]); // Index 0 enthält die Zahl
    }


    vRows = tempRow;
}


    std::vector<char> Board::getValidCols()
    {
        return vCol;
    }
    
    std::vector<char> Board::getValidRows()
    {
        return vRows;
    }


    bool Board::saveCurrentPlayboard()
    {
        savedPlayboard = vPlayboard;
        savedIsTakenX = isTakenX;
        savedIsTakenO = isTakenO;
        if (savedPlayboard == vPlayboard)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Board::resetSavedPlayboard()
    {
        vPlayboard = savedPlayboard;
        isTakenO = savedIsTakenO;
        isTakenX = savedIsTakenX;
        if(vPlayboard == savedPlayboard)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    std::vector<std::string> Board::validRowsStr()
    {

        std::vector<char> validRows = vRows;  // Valide Rows und Collums holen
        std::vector<char> validCols = vCol;  
        std::vector<std::string> strVRows(validRows.size());    // String Vector erstellen mit der größe der Validen Rows
        std::vector<std::string> strVCols(validCols.size());


        std::vector<std::string> isTakenCombined;
        isTakenCombined.reserve(isTakenX.size()+isTakenO.size());
        isTakenCombined.insert(isTakenCombined.end(), isTakenX.begin(), isTakenX.end());
        isTakenCombined.insert(isTakenCombined.end(), isTakenO.begin(), isTakenO.end());


        std::vector<std::string> isTaken = isTakenCombined;

        //Umwandeln von Vector Char to Vector String
        for (int x = 0; x < validCols.size(); x++)
        {
            strVRows[x] = std::string(1,validRows[x]);

        }
        
        return strVRows;

    }


    std::vector<std::string> Board::validColStr()
    {

        
        std::vector<char> validRows = vRows;  // Valide Rows und Collums holen
        std::vector<char> validCols = vCol;  
        std::vector<std::string> strVRows(validRows.size());    // String Vector erstellen mit der größe der Validen Rows
        std::vector<std::string> strVCols(validCols.size());


        std::vector<std::string> isTakenCombined;
        isTakenCombined.reserve(isTakenX.size()+isTakenO.size());
        isTakenCombined.insert(isTakenCombined.end(), isTakenX.begin(), isTakenX.end());
        isTakenCombined.insert(isTakenCombined.end(), isTakenO.begin(), isTakenO.end());


        std::vector<std::string> isTaken = isTakenCombined;

        //Umwandeln von Vector Char to Vector String
        for (int x = 0; x < validCols.size(); x++)
        {
            strVCols[x] = std::string(1,validCols[x]);
        }
        
        return strVCols;

    }