#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MyFunctions.h"
#include <conio.h>


// Programm um eine Liste an Einträgen in eine richtig aussehende DTMS zu verwandeln.
// DTMS Creator 
// Author Marcel Schulz
// Version 0.8
// 12.10.2023

int main()
{
    bool isRunning = true;
    std::vector<std::vector<std::string>> extracedNamesAndPaths;  // index 0 = names and index 1 = paths
    std::vector<std::string> extracedNames;
    std::vector<std::string> extracedPaths;
    std::vector<std::string> materialList;

    std::vector<std::vector<std::string>> matchVector;
    std::vector<std::string> searchString;
    std::vector<std::string> materialReplacement;
    std::vector<std::string> name;



    while (isRunning)
    {
         materialList = CollectMaterialList();

         print("Press Any Key");
         _getch();
         system("cls");

         extracedNamesAndPaths = searchForNames();

         extracedNames = extracedNamesAndPaths[0];
         extracedPaths = extracedNamesAndPaths[1];

         matchVector = match(extracedNames, extracedPaths, materialList);
         searchString = matchVector[0];
         materialReplacement = matchVector[1];
         name = matchVector[2];


         saveDTMS(matchVector);


        isRunning = exitCond();
    }

}