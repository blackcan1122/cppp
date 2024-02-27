#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "MyFunctions.h"
#include "Board.h"
#include "Gamelogic.h"

//Ein commandline Anwendung f�r Tic Tac Toe
//Author Marcel Schulz
// 

int main ()
{
    std::string userInput;
    bool userInputConverted = true;

    std::cout << "Do you want to Play against a Human?\n";
    std::cout << "Y/N\n";
    std::cin >> userInput;
    system("cls");
    if (userInput[0] == 'y' || userInput[0] == 'Y')
    {
        userInputConverted = true;
    } 
    else 
    {
        userInputConverted = false;
    }

    //creating a instance of the class Gamelogic with Player2 Parameter
    Gamelogic game1(userInputConverted);
}