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

         extracedNamesAndPaths = searchForNames();

         extracedNames = extracedNamesAndPaths[0];
         extracedPaths = extracedNamesAndPaths[1];

         //for (int i = 0; i < extracedNames.size(); i++)
         //{

         //    print(extracedNames[i]);

         //}
         //for (int i = 0; i < extracedPaths.size(); i++)
         //{

         //    print(extracedPaths[i]);

         //}

         matchVector = match(extracedNames, extracedPaths, materialList);
         searchString = matchVector[0];
         materialReplacement = matchVector[1];
         name = matchVector[2];


         for (int i = 0; i < searchString.size(); i++)
         {

             std::cout << materialReplacement[i] << "\n";
             std::cout << searchString[i] << "\n";
             std::cout << "\n";
             std::cout << "\n";
             std::cout << "\n";
         }


        isRunning = exitCond();
    }

}