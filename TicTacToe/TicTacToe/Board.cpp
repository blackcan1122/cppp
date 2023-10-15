#include "board.h"
#include "Gamelogic.h"
#include "MyFunctions.h"
#include <iostream>
#include <locale>


Board::Board()
{

    generatePlayboard();

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
    return isTaken;
}

std::vector<std::vector<std::string>> Board::setvPlayboard(std::vector<std::vector<std::string>> newvPlayboard)
{
    vPlayboard = newvPlayboard;
    return vPlayboard;

}

std::vector<std::string> Board::addItemtoIsTaken(std::string itemToAdd)
{
    isTaken.push_back(itemToAdd);
    return isTaken;
}


void Board::updatePlayboard(std::string input)
{

    // Beispiel B1


    addItemtoIsTaken(input);


    char charcordA = input[0];
    char charcordB = input[1];

    int cordA = charcordA - 'A'+1;
    int cordB = charcordB - '0'+1;

    std::vector<std::vector<std::string>> tempvPlayboard = getvPlayboard();
    tempvPlayboard[cordB][cordA] = "[X]";
    setvPlayboard(tempvPlayboard);


}