// class for Profile
#include <string>
#include <vector>
#include <iostream>

//Declaration for std cout / string / vector
using std::string;
using std::vector;

class profile {
    //attribute
    string vorname;
    string nachname;
    int age; 
    string pronouns;
    int id_user=0;

    string city; 
    string country;
    vector <string> hobbies;
    int birthday[3];
 


    //methoden
    private:

        int calculate_age(int birthday[3]);



    public:

        static vector<profile*> dataObjects;
        // Constructor
        profile(int id_user, string vorname, string nachname, int age, string pronouns);

        // Get Methodes
        string get_name();
        string get_city();

        vector<string> get_hobbies();

        int get_age();

        // Set Methods        
        void set_city(string new_city);
        void set_country(string new_country);
        void set_hobbies(vector<string> new_hobbies);
        void set_pronouns(string new_pronouns);



};