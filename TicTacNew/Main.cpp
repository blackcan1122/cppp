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
    bool restart = true;
    bool userInputConverted = true;

    while (restart == true)
    {
    print("Do you want to Play against a Human?");
    print("Y/N");
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
        print("Do you want to Restart the Game?");
        print("Y/N");
        std::cin >> userInput;
        system("cls");
        if (userInput[0] == 'y' || userInput[0] == 'Y')
        {
            restart = true;
        } 
        else 
        {
            restart = false;
        }
    }
}
