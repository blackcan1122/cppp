#include <iostream>
#include <string>
#include <ctype.h>

int main() {

    //declare and init Variables
    int gryffindor = 0;
    int hufflepuff = 0;
    int ravenclaw = 0;
    int slytherin = 0;

    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    int answer4 = 0;

    char gender;
    std::string anrede;
    std::string name;
    bool nathalie;

    std::string house;
    int max = 0;


    // Function

    std::cout << "The Sorting Hat Quiz!\n";

    // Geschlechtsabfrage
    std::cout << "Welches Geschlecht hast du? m/w \n";
    std::cin >> gender;
    std::cin.ignore(256, '\n'); // Leerzeichen und Zeilenumbruch Überspringen
    gender = tolower(gender);



    // Anrede abhängig des geschlechts setzen
    if (gender == 'm') {
        anrede = "Der";
    }
    else {
        anrede = "Die";
    }


    // Abfrage für Name:

    std::cout << "Wie ist dein Name\n";
    std::cin >> name;
    std::cout << "Dann lass uns herausfinden in welches Haus du kommst " << name << "\n";






    // Namens variationen

    if (name == "Nathalie" || name == "nathalie" || name == "Natha" || name == "natha" || name == "Nikkie" || name == "nikkie") {


        if (gender == 'w') {
            nathalie = true;
        }
        else {
            nathalie = false;
        }

    }
    else nathalie = false;

    // Betrug und beschiss

    if (nathalie == true) {
        slytherin = slytherin + 99;

    }
    else {
        slytherin = slytherin - 99;

    }








    std::cout << "\n";
    // Quiz Frage 1

    std::cout << "Frage 1:\n";
    std::cout << "Wenn ich tot bin möchte ich, dass die Menschen mich als was erinnern?\n";
    std::cout << "1) " << anrede << " Gute\n";
    std::cout << "2) " << anrede << " Grosse\n";
    std::cout << "3) " << anrede << " Weise\n";
    std::cout << "4) " << anrede << " Mutige\n";

    std::cin >> answer1;

    // Auswertung Frage 1

    switch (answer1) {

    case 1:
        hufflepuff = hufflepuff + 1;
        break;

    case 2:
        slytherin = slytherin + 1;
        break;

    case 3:
        ravenclaw = ravenclaw + 1;
        break;

    case 4:
        gryffindor = gryffindor + 1;
        break;

    default:
        std::cout << "Fatal Error\n";
        return 0;
        break;

    }

    // Quiz Frage 2

    std::cout << "Frage 2:\n";
    std::cout << "Sonnenaufgang oder Untergang?\n";
    std::cout << "1) Sonnenaufgang\n";
    std::cout << "2) Sonnenuntergang\n";

    std::cin >> answer2;

    // Auswertung Frage 2

    if (answer2 == 1) {
        gryffindor = gryffindor + 1;
        ravenclaw = ravenclaw + 1;

    }
    else {
        slytherin = slytherin + 1;
        hufflepuff = hufflepuff + 1;
    }

    // Quiz Frage 3

    std::cout << "Frage 3:\n";
    std::cout << "Welche Art von Instrument wählst du?\n";
    std::cout << "1) Die Violine\n";
    std::cout << "2) Die Trompete\n";
    std::cout << "3) Das Piano\n";
    std::cout << "4) Die Trommel\n";

    std::cin >> answer3;

    // Auswertung Frage 3

    switch (answer3) {

    case 1:
        slytherin = slytherin + 1;
        break;

    case 2:
        hufflepuff = hufflepuff + 1;
        break;

    case 3:
        ravenclaw = ravenclaw + 1;
        break;

    case 4:
        gryffindor = gryffindor + 1;
        break;

    default:
        std::cout << "Fatal Error\n";
        return 0;
        break;

    }

    // Quiz Frage 4

    std::cout << "Frage 3:\n";
    std::cout << "Welchen Weg wählst du?\n";
    std::cout << "1) Die breite sonnige strasse\n";
    std::cout << "2) Die enge dunkle laternen beleuchtete allee\n";
    std::cout << "3) Der durch zweig und ast verwinkelte Wald\n";
    std::cout << "4) Die historische Altstadt\n";

    std::cin >> answer4;

    // Auswertung Frage 4

    switch (answer4) {

    case 1:
        hufflepuff = hufflepuff + 1;
        break;

    case 2:
        slytherin = slytherin + 1;
        break;

    case 3:
        gryffindor = gryffindor + 1;
        break;

    case 4:
        ravenclaw = ravenclaw + 1;
        break;

    default:
        std::cout << "Fatal Error\n";
        return 0;
        break;

    }

    if (gryffindor > max) {

        max = gryffindor;
        house = "Gryffindor";
    }

    if (hufflepuff > max) {

        max = hufflepuff;
        house = "hufflepuff";
    }

    if (ravenclaw > max) {

        max = ravenclaw;
        house = "ravenclaw";
    }

    if (slytherin > max) {

        max = slytherin;
        house = "slytherin";
    }

    std::cout << "\n";
    std::cout << "\n";

    std::cout << house << "!\n";
    return 0;
}