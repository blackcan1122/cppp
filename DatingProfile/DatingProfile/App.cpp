#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "profile.h"
#include "MyFunctions.h"


int main() {

    bool run = true; // Exit Condition, When 'run' = false, loop stops

    int menu;



    


    while (run) {

        std::cout << "What would you like to do?\n";
        std::cout << "==========================================\n";
        std::cout << "1) Create a Profile\n";
        std::cout << "2) View a Profile\n";
        std::cout << "3) Delete a Profile\n";
        std::cout << "4) Edit Profile\n";
        std::cout << "5) List all avaiable Profiles\n";

        std::cin >> menu;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (menu = 1) {

            std::cout << "Bitte "

            profile isabell(0, "Isabel", "Hans", 16, "Die");

            std::cout << isabell.get_name() << "\n";

        }

        


        // Exit Condition
        
        run = exitCond();

    }
}