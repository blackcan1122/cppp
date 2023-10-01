// class for Profile
#include <string>
#include <vector>

//Declaration for std cout / string / vector
using std::string;
using std::vector;

class profile {
    //attribute for Constructor
    string init_vorname;
    string init_nachname;
    int init_age;
    string init_pronouns;
    int init_id_user;

    //attribute
    string vorname;
    string nachname;
    int age; 
    string pronouns;
    int id_user;

    string city; 
    string country;
    vector <string> hobbies;
    int birthday[3];
 


    //methoden
    private:

        int calculate_age(int birthday[3]);



    public:

        // Constructor
        profile(int init_id_user, string init_vorname, string init_nachname, int init_age, string init_pronouns);

        // Get Methodes
        string get_name();
        string get_city();

        vector<string> get_hobbies();

        int get_age();

        // Set Methods        
        void set_city(string new_city);
        void set_hobbies(vector<string> new_hobbies);
        void set_pronouns(string new_pronouns);


};