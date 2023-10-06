#include "profile.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

//Constructor

// Initialisieren Sie das statische Mitglied dataObjects
std::vector<profile*> profile::dataObjects;

profile::profile(int id_user, string vorname, string nachname, int age, string pronouns)
    :id_user(id_user), vorname(vorname), nachname(nachname), age(age), pronouns(pronouns)
{

    dataObjects.push_back(this);   

}





// definitions of profile.h

string profile::get_name() {

    
    return vorname + " " + nachname;


}


int profile::calculate_age(int birthday[3]) {
    
    return 0;
}

string profile::get_city() {
    return city;
}

vector<string> profile::get_hobbies() {
    return hobbies;
}

int profile::get_age() {
    return age;
}

void profile::set_city(string new_city) {
    city = new_city;
}

void profile::set_country(string new_country) {
    country = new_country;
}

void profile::set_hobbies(vector<string> new_hobbies) {
    hobbies = new_hobbies;
}

void profile::set_pronouns(string new_pronouns) {
    pronouns = new_pronouns;
}