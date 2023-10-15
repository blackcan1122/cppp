#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "MyFunctions.h"
#include <conio.h>
#include <sys/stat.h>
#include <locale>
#include <filesystem>
#include <fstream>
#include <sstream>



//Exit Condition abfrage
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


// Cleant den input
void InputClean() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


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


// Geht datei namen in Ordner durch und speichert sie in variablen als klarname und pfad
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


        // Exit Condition
        if (folderPath == "x" || folderPath == "X") 
        {
            print("=========================================================================");
            print("=========================================================================");
            print("Successfully finished parsing Folder!");
            print("=========================================================================");
            print("=========================================================================");

            print("Press Any Key");
            _getch();
            system("cls");
            inLoop = false;
            std::vector<std::vector<std::string>> result;
            result.push_back(fileName);
            result.push_back(filePaths);
            return result;


        }
        else
        {
            if (isValidPath == true)
            {

                // Für jede Datei im Verzeichnis in ein Vektor Speichern als Name und als Pfad
                for (const auto& entry : std::filesystem::directory_iterator(folderPath))   
                {
                    if (entry.is_regular_file()) {
                        // Vollständiger Pfad zur Datei hinzufügen
                        filePathsDirty.push_back(entry.path().string());                       

                        // Dateiname ohne Pfad hinzufügen
                        fileNameDirty.push_back(entry.path().filename().string());
                    }

                }

                // .uasset von datein entdernen für den Filename
                for (int i = 0; i < fileNameDirty.size(); i++)   
                {
                    if (fileNameDirty[i].find(".uasset") != std::string::npos)
                    {
                        std::string tempString = fileNameDirty[i];
                        auto start_position_to_erase = tempString.find(".uasset");
                        tempString.erase(start_position_to_erase, 7);
                        fileName.push_back(tempString);

                        // Debug
                        //print(tempString);
                    }
                    else
                    {
                        print("atleast one File in Folder wasn't a .uasset");
                        print(fileNameDirty[i]);
                    }
                }

                // Pfad umändern damit er bei game beginnt und ohne .uasset endung und als Pfad speichern
                for (int i = 0; i < filePathsDirty.size(); i++)    
                {
                    if (fileNameDirty[i].find(".uasset") != std::string::npos)
                    {
                            // Pfad umändern
                            std::string tempString = filePathsDirty[i];
                            auto const start_pos_to_replace_content = tempString.find("Content");
                            tempString = tempString.substr(start_pos_to_replace_content);
                            tempString = tempString.replace(0, 7, "Game");
                           // tempString = tempString.replace("\\", 1, "\/");
                            std::replace(tempString.begin(), tempString.end(), '\\', '/');  

                            // uasset endung entfernen
                            auto const start_pos_to_replace_uasset = tempString.find(".uasset");
                            tempString = tempString.erase(start_pos_to_replace_uasset, 7);
                            filePaths.push_back(tempString);


                    }
                    else // Falls eine datei keine .uasset endung hat
                    {
                        print("atleast one File in Folder wasn't a .uasset");
                        print(fileNameDirty[i]);
                    }

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
        print("===============================");
        print("Folder was Successfully Parsed!");
        print("===============================");
        print("Press Any Key");
        _getch();
        system("cls");
    }




}




// collectMaterialList Funktion um eine liste mit materialien durchzu parsen
std::vector<std::string> CollectMaterialList()
{
    std::string listPath;
    std::string line;
    std::vector<std::string> materialList;
    bool inputFalse = true;

    while (inputFalse == true)
    {
        print("Please enter the path to your unformatted list");
        std::cin >> listPath;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::ifstream infile(listPath);

        if (!infile.is_open())
        {
            std::cerr << "Error: Unable to open file please make Sure this Path is correct " << listPath << std::endl;
            
        }
        if (infile.is_open())
        {
            inputFalse = false;
        }
        if (inputFalse == false)
        {
            while (std::getline(infile, line))
            {

                materialList.push_back(line);
                
            }
        }
    }
    print("=======================");
    print("=======================");
    print("Successfully Read File!");
    print("=======================");
    print("=======================");
    return materialList;
}


// match funktion um listen mit materialiste abzugleichen und eine vollständige liste der matches auszugeben || erfordert eine material liste, eine klarnamen liste und eine pfad liste
std::vector<std::vector<std::string>> match(const std::vector<std::string>& searchFileNames, const std::vector<std::string>& SearchFilePaths, const std::vector<std::string>& materialList)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> searchString;
    std::vector<std::string> materialReplacement;
    std::vector<std::string> name;




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


// Speichert alle inhalte der Listen formatiert in eine .json
void saveDTMS(std::vector<std::vector<std::string>> inputLists)
{

    std::vector<std::string> searchString = inputLists[0];
    std::vector<std::string> materialReplacement = inputLists[1];
    int index_ID = 0;
    std::string preFix = "/Script/Engine.Material'/";
    //print("Please Input Folder where to save");

    std::ofstream outFile("Dataset.json");


    outFile << "[";
    outFile << "\n";
    if (outFile.is_open())
    {
        for (auto searchStringItem : searchString)
        {
            
           
           index_ID++;
           outFile << " " << "{" << "\n";
           outFile << " " << " " << "\"Name\": " << "\"" << index_ID << "\"," << "\n";
           outFile << " " << " " << "\"SearchString\": " << "\"" << searchStringItem << "\"," << "\n";
           outFile << " " << " " << "\"StringMatch\": " << "\"ExactMatch\"," << "\n";
           outFile << " " << " " << "\"MaterialReplacement\": " << "\"" << preFix << materialReplacement[index_ID-1] << "." << searchStringItem << "'" << "\"" << "\n";
           if (searchStringItem == searchString.back())
           {
               outFile << " " << "}" << "\n";
           }
           else
           {
               outFile << " " << "}," << "\n";
           }
                

            

            
            
            
        }
        if (searchString.size() > 1)
        {
            print("File Succesfully Written");
            outFile << "]";
            outFile << "\n";
        }
    }

}