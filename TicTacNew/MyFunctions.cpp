#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "MyFunctions.h"
#include <conio.h>
#include <sys/stat.h>
#include <locale>
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