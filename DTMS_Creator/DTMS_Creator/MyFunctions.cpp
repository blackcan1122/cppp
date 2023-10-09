#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "MyFunctions.h"
#include <sys/stat.h>
#include <locale>
#include <filesystem>
#include <fstream>
#include <sstream>

bool exitCond() {
    bool SpellCheckExit = true;
    char input_user;

    while (SpellCheckExit) {

        std::cout << "Do you want to Exit? Y/N\n";
        std::cin >> input_user;
        input_user = tolower(input_user);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (input_user == 'y') {

            return false;
        }
        else if (input_user == 'n') {

            return true;

        }
        else {
            std::cout << "Falsche eingabe bitte wiederholen\n";

            SpellCheckExit = true;

        }

    }

    return NULL;
}

void InputClean() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//template <typename t>
//void print(t text ) {
//
//    std::cout << text << std::endl;
//
//}


//String Splitter

std::vector<std::string> splitstring(const std::string& profileData, char seperator) 
{
    int startIndex = 0;
    int stopIndex = 0;
    std::vector<std::string> result;
    std::vector<char> garbage;


    for (int i = 0; i <= profileData.size(); i++) {

        if (i == profileData.size() || profileData[i] == seperator) {
            stopIndex = i;
            std::string temp;

            temp = profileData.substr(startIndex, stopIndex - startIndex);
            startIndex = stopIndex + 1;
            result.push_back(temp);
            
        }
    }

    return result;

}


// Geht namen durch und speichert sie in variablen

std::vector<std::vector<std::string>> searchForNames()
{
    bool inLoop = true;
    bool isValidPath;
    std::string folderPath;

    std::vector<std::string> fileNameDirty;    
    std::vector<std::string> fileName;
    std::vector<std::string> filePathsDirty;
    std::vector<std::string> filePaths;

    while (inLoop)
    {
        print("=========================================================================");
        print("Please enter a path to a folder where you want to look for matching names");
        print("Enter as much Paths as you want, when you're finished enter X");
        print("=========================================================================");

        std::cin >> folderPath;
        InputClean();

        isValidPath = std::filesystem::is_directory(folderPath);

        if (folderPath == "x" || folderPath == "X") // Exit Condition
        {

            inLoop = false;
            std::vector<std::vector<std::string>> result;
            result.push_back(fileName);
            result.push_back(filePaths);
            // Debug
            //for (int i = 0; i < result[1].size(); i++)
            //{
            //    print(result[1][i]);
            //}

            return result;

        }
        else
        {
            if (isValidPath == true)
            {


                for (const auto& entry : std::filesystem::directory_iterator(folderPath))   // Für jede Datei im Verzeichnis in ein Vektor Speichern als Name und als Pfad
                {
                    if (entry.is_regular_file()) {
                        // Vollständiger Pfad zur Datei hinzufügen
                        filePathsDirty.push_back(entry.path().string());                       

                        // Dateiname ohne Pfad hinzufügen
                        fileNameDirty.push_back(entry.path().filename().string());
                    }

                }
                /* Debugging
               for (int i = 0 ; i < fileNames.size(); i++)
               {
                   print(fileNames[i]);
               }
               for (int i = 0; i < filePaths.size(); i++)
               {
                   print(filePaths[i]);
               }
               */

                for (int i = 0; i < fileNameDirty.size(); i++)   // .uasset von datein entdernen
                {
                    std::string tempString = fileNameDirty[i];
                    auto start_position_to_erase = tempString.find(".uasset");

                    tempString.erase(start_position_to_erase, 7);
                    fileName.push_back(tempString);

                    // Debug
                    //print(tempString);
                }

                for (int i = 0; i < filePathsDirty.size(); i++)    // Pfad umändern damit er bei game beginnt und ohne .uasset endung
                {
                    std::string tempString = filePathsDirty[i];
                    auto const start_pos_to_replace_content = tempString.find("Content");
                    tempString = tempString.substr(start_pos_to_replace_content);
                    tempString = tempString.replace(0, 7, "Game");

                    auto const start_pos_to_replace_uasset = tempString.find(".uasset");
                    tempString = tempString.erase(start_pos_to_replace_uasset, 7);
                    filePaths.push_back(tempString);

                    // Debug
                    //print(tempString);

                }



            }
            else // Falls pfad invalid ist
            {
                print("invalid Path! Please make sure its right");
                print(folderPath);
            }
        }
    }




}


std::vector<std::vector<std::string>> match(std::vector<std::string> searchFileNames, std::vector<std::string> SearchFilePaths,std::vector<std::string> materialList)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> searchString;
    std::vector<std::string> materialReplacement;
    std::vector<std::string> name;
    bool foundFlag = false;
    int foundIndex = 0;




    for (auto materialListItem : materialList)
    {
        auto it = std::find(searchFileNames.begin(), searchFileNames.end(), materialListItem);
        if (it != searchFileNames.end())
        {
            searchString.push_back(materialListItem);
            materialReplacement.push_back(SearchFilePaths[it - searchFileNames.begin()]);
//            name.push_back(std::to_string(i));  
        }
        else 
        {
            searchString.push_back(materialListItem);
            materialReplacement.push_back("None");
 //           name.push_back(std::to_string(i));
        }
    }

    // Make Result Vector

    result.push_back(searchString);
    result.push_back(materialReplacement);
    result.push_back(name);
    return result;

}

std::vector<std::string> CollectMaterialList()
{
    std::string listPath;
    std::string line;
    std::vector<std::string> materialList;

    print("Pleaser enter the path to your unformated list");
    std::cin >> listPath;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ifstream infile(listPath);

    if (!infile.is_open())
    {
        std::cerr << "Error: Unable to open file please Makre Sure this Path is correct " << listPath << std::endl;
        return materialList; // Return an empty list on failure
    }

    while (std::getline(infile, line))
    {

        materialList.push_back(line);

    }

    for (int i = 0; i < materialList.size(); i++)
    {

        print(materialList[i]);

    }
    return materialList;
}