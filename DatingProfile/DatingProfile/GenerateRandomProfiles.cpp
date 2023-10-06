#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "GenerateRandomProfiles.h"

std::vector<std::string> firstNames = 
{
        "Max", "Liam", "Ethan", "Oliver", "Lucas", "Noah", "Mason", "Elijah", "Logan", "Carter",
        "Olivia", "Emma", "Ava", "Charlotte", "Sophia", "Amelia", "Isabella", "Mia", "Evelyn", "Harper", 
        "Sophia", "Olivia", "Emma", "Ava", "Isabella", "Mia", "Zoe", "Lily", "Emily", "Grace",
        "Liam", "Noah", "Elijah", "Oliver", "Lucas", "Carter", "Mason", "Logan", "Ethan", "James"
};


std::vector<std::string> lastNames = 
{
    "Smith", "Johnson", "Brown", "Jones", "Williams", "Davis", "Miller", "Wilson", "Moore", "Taylor",
    "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson"
};

std::vector<int> ages;

std::vector<std::string> pronouns = 
{
    "he/him", "she/her", "they/them", "ze/hir", "ey/em", "per/pers", "ve/ver"
};


std::vector<std::string> cities = 
{
    "New York", "Los Angeles", "Chicago", "Houston", "Phoenix", "Philadelphia", "San Antonio", "San Diego", "Dallas", "San Jose",
    "Berlin", "Munich", "Hamburg", "Cologne", "Frankfurt", "Stuttgart", "Düsseldorf", "Dortmund", "Essen", "Leipzig"
};

std::vector<std::string> countries = 
{
    "USA", "Canada", "UK", "Australia", "Germany", "France", "Spain", "Italy", "Japan", "China",
    "Mexico", "Brazil", "India", "South Korea", "Russia", "Argentina", "South Africa", "Egypt", "Saudi Arabia", "Turkey"
};

std::vector<std::string> hobbies = {
    "Lesen", "Sport", "Gaming", "Reisen", "Kochen", "Malen", "Musik", "Wandern", "Fotografie", "Tanzen",
    "Basteln", "Angeln", "Gärtnern", "Theater", "Schwimmen", "Fahrrad fahren", "Klettern", "Skifahren", "Surfen", "Yoga"
};

std::vector<RandomPeopleStruct> fakeProfile(int Anzahl, int alreadyExisting)
{

    // Attributes of Functions

    std::vector<RandomPeopleStruct> result;

    std::string tempName;
    std::string templastName;
    int tempAge;
    std::string tempPronouns;
    std::string tempCities;
    std::string tempCountries;
    std::vector<std::string> tempHobbies;
    // Creation of Ages between 18 and 35
    std::vector<int> ages;
    for (int i = 18; i <= 35; i++) {
        ages.push_back(i);
    }

    // RandomSeed
    srand(time(NULL));

    for (int i = 0; i < Anzahl; i++)
    {
        int id = alreadyExisting + i;
        tempName = firstNames[rand() % firstNames.size()];              // Get a random First name depending on Rand modulo the size of the vector
        templastName = lastNames[rand() % lastNames.size()];
        tempPronouns = pronouns[rand() % pronouns.size()];
        tempCities = cities[rand() % cities.size()];
        tempCountries = countries[rand() % countries.size()];
        tempAge = ages[rand() % ages.size()];
        tempHobbies.clear();                                            // clearing hobbies so it can be filled again
        for (int j = 0; j < rand() % 6 + 4; j++)                        
        {
            tempHobbies.push_back(hobbies[rand()%hobbies.size()]);
        }
        result.push_back(RandomPeopleStruct());
        // Implementierung um sachen in Struct zu schreiben.
        result[i].structName = tempName;
        result[i].structLastName = templastName;
        result[i].structPronouns = tempPronouns;
        result[i].structCountries = tempCountries;
        result[i].structCities = tempCities;
        result[i].structHobbies = tempHobbies;
        result[i].structID = id;
        result[i].structAge = tempAge;

    }


    return result;
}