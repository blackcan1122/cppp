#pragma once
#include <iostream>
#include <vector>

struct RandomPeopleStruct {
    std::string structName;
    std::string structLastName;
    int structAge;
    std::string structPronouns;
    std::string structCities;
    std::string structCountries;
    std::vector<std::string> structHobbies;
    int structID;
};


std::vector<RandomPeopleStruct> fakeProfile(int Anzahl, int alreadyExisting);