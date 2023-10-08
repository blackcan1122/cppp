#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MyFunctions.h"


// Programm um eine Liste an Einträgen in eine richtig aussehende DTMS zu verwandeln.

int main()
{
    bool isRunning = true;

    while (isRunning)
    {

        //
        std::string listPath; // path to list
        print("Pleaser enter the path to your unformated list");
        std::cin >> listPath;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        searchForNames();



        isRunning = exitCond();
    }

}