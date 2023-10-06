#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "profile.h"
#include "MyFunctions.h"
#include <stdlib.h>
#include <conio.h>
#include "GenerateRandomProfiles.h"
#include <fstream>


int main() {

    bool run = true; // Exit Condition, When 'run' = false, loop stops
    int target_ID;
    int menu;
    int id_counter = 0;
    bool loopcheck = false;
    int amountFakeProfiles;

    std::string ProfileData; // User input for Profile Init
    std::vector<std::string> ProfileDataSplit; // Splitted variant of User Input 

    std::string objectName; // Is Used for Naming the Object


    std::vector<std::string> savedVornamen;     //Saves all Variables for Profiles
    std::vector<std::string> savedNachname;     
    std::vector<int> savedAge;        
    std::vector<std::string> savedPronoun;      
    std::vector<std::string> savedCity;
    std::vector<std::string> savedCountry;
    std::vector<std::vector<std::string>> savedHobbies;
    std::vector<RandomPeopleStruct> generatedProfiles;



    while (run) {
        if (loopcheck == true) // After first Loop wait for user input to reset screen
        { 
            _getch();
        }
        system("cls"); // Clear Screen for better view
        print("========================================================");
        print("What would you like to do?");
        print("==========================================");
        print("1) Create a Profile");
        print("2) View a Profile");
        print("3) Delete a Profile");
        print("4) Edit Profile");
        print("5) List all avaiable Profiles");
        print("6) Generate Random Profile Data");
        print("7) Save to File");
        print("8) LoadDataset");  // Need implementation yet
        print("9) Exit");
        loopcheck = true;
        std::cin >> menu;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (menu == 1) // Create Profile
        {
            print("========================================================");
            print("Please enter Name, Surname, Age and Pronoun seperated by a comma");
            print("========================================================");
            std::cin >> ProfileData;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ProfileDataSplit = splitstring(ProfileData);
            if (ProfileDataSplit.size() == 4)
            {
                objectName = ProfileDataSplit[0];

                // Age Check for Int
                string numberCheck = ProfileDataSplit[2];
                bool isNumber = true;
                for (int c = 0; c <= numberCheck.size(); c++) 
                {

                    if (numberCheck[c] == 'a' || numberCheck[c] == 'e' || numberCheck[c] == 'i' || numberCheck[c] == 'o' || numberCheck[c] == 'u')
                    {
                        isNumber = false;
                        c = numberCheck.size();


                    }
                    else {
                        isNumber = true;
                    }


                }
                
                // Erstellen des Objekts

                if (isNumber == true)
                {
                    profile objectName(id_counter, ProfileDataSplit[0], ProfileDataSplit[1], stoi(ProfileDataSplit[2]), ProfileDataSplit[3]);

                    id_counter++;
                    print("========================================================");
                    std::cout << "Profil with ID : " << id_counter << " was created\n";
                    print("========================================================");

                    // Speicher Objekt Daten in Variablen

                    savedVornamen.push_back(ProfileDataSplit[0]);
                    savedNachname.push_back(ProfileDataSplit[1]);
                    savedAge.push_back(stoi(ProfileDataSplit[2]));
                    savedPronoun.push_back(ProfileDataSplit[3]);

                    // Vektoren für stadt, land und hobbies schon befüllen, damit der Vektor ein eintrag für den jeweiligen index erstellt hat.

                    savedCity.push_back(" ");
                    savedCountry.push_back(" ");
                    savedHobbies.push_back({ " " });
                }
                else
                {
                    print("========================================================");
                    print("========================================================");
                    print("The entered Age isn't a number! Please Try Again");
                    print("========================================================");
                    print("========================================================");

                }
                
            }
            else 
            {
                print("========================================================");
                print("========================================================");
                print("Error; Your input had no valid inputs, please make sure it only has name surname age and pronouns (e.g. Max,Mustermann,25,He)");
                print("========================================================");
                print("========================================================");

            }
        }
        else if (menu == 2)  // View Profile
        {
            print("========================================================");
            print("Please Enter ID");
            print("==============================");
            std::cin >> target_ID;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Abfrage ob target_ID valid
            if (target_ID > id_counter || target_ID==0) 
            {

                print("WARNUNG, Wrong ID");
            }
            else 
            { 
                std::string temp_hobbie_string;
                target_ID = target_ID - 1;
                print("Hier ist ihr gesuchtes Profil:");
                print("==============================");
                print("==============================");
                print(savedVornamen[target_ID]);
                print(savedNachname[target_ID]);
                print(savedAge[target_ID]);
                print(savedPronoun[target_ID]);
                print(savedCountry[target_ID]);
                print(savedCity[target_ID]);
                print("Hobbies:");
                for (int j = 0; j < savedHobbies[target_ID].size(); j++)
                {
                    for (int k = 0; k < savedHobbies[target_ID][j].size(); k++)
                    {

                        std::cout << savedHobbies[target_ID][j][k];
                        
                    }
                    std::cout << "\n";
                }
                
                print("==============================");
                print("==============================");
            }
        }
        else if (menu == 3) // Delete Profile
        {
            print("==============================");
            print("Enter ID of Profile you want to delete");
            print("==============================");
            std::cin >> target_ID;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (target_ID > id_counter || target_ID == 0) {

                print("WARNUNG, Wrong ID");
            }
            else {

                target_ID = target_ID - 1;

                savedVornamen.erase(savedVornamen.begin() + target_ID);
                savedNachname.erase(savedNachname.begin() + target_ID);
                savedAge.erase(savedAge.begin() + target_ID);
                savedPronoun.erase(savedPronoun.begin() + target_ID);
                savedCity.erase(savedCity.begin() + target_ID);
                savedCountry.erase(savedCountry.begin() + target_ID);
                savedHobbies.erase(savedHobbies.begin() + target_ID);
                id_counter = id_counter - 1;


            }


        }
        else if (menu == 4) // Edit a Profile
        {
            print("========================================================");
            print("Enter ID of Profile you want to edit");
            std::cin >> target_ID;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (target_ID > id_counter || target_ID == 0) {

                print("WARNUNG, Wrong ID");
            }
            else 
            {
                int editChoose;
                std::string EditInput;
                std::vector<std::string> vEditInput;
                target_ID = target_ID - 1;
                bool editMode = true;
                while (editMode) {
                    print("========================================================");
                    print("Enter option to Change");
                    print("1) Name");
                    print("2) Surname");
                    print("3) age");
                    print("4) City");
                    print("5) Country");
                    print("6) Hobbies");
                    print("7) Pronouns");
                    print("8) Exit Edit Mode");
                    print("========================================================");


                    std::cin >> editChoose;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (editChoose == 1)
                    {
                        print("========================================================");
                        print("Enter The new Name");
                        std::cin >> EditInput;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        savedVornamen[target_ID] = EditInput;


                    }
                    else if (editChoose == 2)
                    {
                        print("========================================================");
                        print("Enter The new Surname");
                        std::cin >> EditInput;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        savedNachname[target_ID] = EditInput;


                    }
                    else if (editChoose == 3)
                    {
                        print("========================================================");
                        print("Enter The new Age");
                        std::cin >> EditInput;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        savedAge[target_ID] = stoi(EditInput);


                    }
                    else if (editChoose == 4)
                    {
                        print("========================================================");
                        print("Enter The new City");
                        std::cin >> EditInput;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        savedCity[target_ID] = EditInput;


                    }
                    else if (editChoose == 5)
                    {
                        print("========================================================");
                        print("Enter The new Country");
                        std::cin >> EditInput;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        savedCountry[target_ID] = EditInput;


                    }
                    else if (editChoose == 6)
                    {
                        print("========================================================");
                        print("Enter The Hobbies seperated by commas");
                        std::cin >> EditInput;
                        vEditInput = splitstring(EditInput);
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        savedHobbies[target_ID] = vEditInput;


                    }
                    else if (editChoose == 7)
                    {
                        print("========================================================");
                        print("Enter The new Pronoun");
                        std::cin >> EditInput;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        savedPronoun[target_ID] = EditInput;


                    }
                    else if (editChoose == 8)
                    {
                        editMode = false;


                    }
                    else
                    {
                        print("Wrong Option");
                    }
                }

            }
        }
        else if (menu == 5)
        {
            for (int h = 0; h < id_counter; h++)
            {
                print("==============================");
                std::cout << "Name: ";
                print(savedVornamen[h]);
                std::cout << "Nachname: ";
                print(savedNachname[h]);
                std::cout << "ID: ";
                print(h);
                print("==============================");
            }

        }
        else if (menu == 6) 
        {
            print("========================================================");
            print("Please input the Amount of fake Profiles you want to create");
            std::cin >> amountFakeProfiles;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            generatedProfiles = fakeProfile(amountFakeProfiles, id_counter);

            for (int i = 0; i < generatedProfiles.size(); i++)
            {

                savedVornamen.push_back(generatedProfiles[i].structName);
                savedNachname.push_back(generatedProfiles[i].structLastName);
                savedCity.push_back(generatedProfiles[i].structCities);
                savedCountry.push_back(generatedProfiles[i].structCountries);
                savedHobbies.push_back(generatedProfiles[i].structHobbies);
                savedPronoun.push_back(generatedProfiles[i].structPronouns);
                savedAge.push_back(generatedProfiles[i].structAge);
                id_counter++;


            }


            
        }
        else if (menu == 7)
        {
            std::ofstream outFile("Dataset.txt");
            if (outFile.is_open())
            {
                for (int i = 0; i < savedVornamen.size(); i++)
                {

                    std::string tempVorname = savedVornamen[i];
                    std::string tempNachname = savedNachname[i];
                    int tempAge = savedAge[i];
                    std::string tempPronouns = savedPronoun[i];
                    std::string tempCity = savedCity[i];
                    std::string tempCountry = savedCountry[i];

                    outFile << tempVorname << ",";
                    outFile << tempNachname << ",";
                    outFile << tempAge << ",";
                    outFile << tempPronouns << ",";
                    outFile << tempCity << ",";
                    outFile << tempCountry << ",";

                    for (int j = 0; j < savedHobbies[i].size(); j++) {

                        std::string tempHobbies = savedHobbies[i][j];
                        outFile << tempHobbies << ",";

                    }
                    outFile << "\r\n";
                }
                outFile.close();
                print("Dataset was succesfully written to file!");
            }
            else 
            {
                print("Problem with writing File!");
            }

        
        }
        else if (menu == 8) 
        {

            // Exit Condition

            run = exitCond();

        }
        else 
        {
            print("Falsche eingabe");
        }




    }
}