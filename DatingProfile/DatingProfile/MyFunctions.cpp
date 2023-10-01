#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "profile.h"

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

std::string InputClean() {

    std::string dirtyInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> dirtyInput;
    
    return dirtyInput;

}