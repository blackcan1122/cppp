#include "profile.h"
#include <string>
#include <vector>
#include <math.h>

//Constructor

profile::profile(int init_id_user, string init_vorname, string init_nachname, int init_age, string init_pronouns) {

    vorname = init_vorname;
    nachname = init_nachname;
    age = init_age;
    pronouns = init_pronouns;
    id_user = init_id_user;

}



// definitions of profile.h

string profile::get_name() {

    
    return vorname + " " + nachname;


}


