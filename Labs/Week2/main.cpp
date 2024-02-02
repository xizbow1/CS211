//CS 211 Spring 2024 - Week 02 Lab
// Bryan, Blake and Ambrose

/*=====
    a small main "exercising" the parts of class PlayerChar

    last modified: 26 Jan 2023
=====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "PlayerChar.h"
using namespace std;

int main() {
    cout << boolalpha;
    srand(time(NULL));

    // Sample test code for trying out PlayerChar constructors

    PlayerChar angie("Angie", 450, 2.2, "Angel");

    // trying out accessors AND seeing if 4-argument constructor
    // set angie as expected

    cout << endl;
    cout << "Angie's initial info: " << endl;
    cout << angie.getName() << " " << angie.getStrength()
         << " " << angie.getAgility() << " " << angie.getRole()
         << endl;

    // trying out other-method print_player_char

    cout << endl;
    cout << "Calling printPlayerChar: " << endl;
    angie.printPlayerChar();
    cout << endl;

    // Code to test randPct
    cout << "*** Should see 10 values from 0.01 to 1.00 "
         << "on the next line ***" << endl;
    for (int i=0; i<10; i++) {
        cout << randPct() << " ";
    }
    cout << endl;

    // BATTLE CODE!  (Uncomment when ready :-)

    cout << "*** LET'S BATTLE! ***" << endl;

    PlayerChar fred;  // By default, he's Fred the Ogre
    fred.printPlayerChar();

    PlayerChar ariel("Ariel", "Sprite");
    ariel.printPlayerChar();
    cout << endl;

    // Code for a single battle

    fred.battle(ariel);

    // This code has Fred and Ariel battle repeatedly
    // until one faints!

    while (fred.getHP() > 0.0 && ariel.getHP() > 0.0)
        fred.battle(ariel);

    return EXIT_SUCCESS;
}
