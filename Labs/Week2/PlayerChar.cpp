// CS 211 Spring 2023 - Week 02 Lab
// Blake Culbertson, Bryan Holmes, Ambrose Sturgill

/*=====
 PlayerChar
    implementation of the constructors and methods for
    a class representing a simple character in a role-playing game;
    has a name, strength, agility, and role

    last modified: 26 Jan 2023
=====*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "PlayerChar.h"
using namespace std;

//=====
// implement PlayerChar's constructors

PlayerChar::PlayerChar(string a_name, int a_strength,
                       double an_agility, string a_role) {
    name = a_name;
    strength = a_strength;
    agility = an_agility;
    role = a_role;
    hp = strength * agility;
}

// WRITE CODE FOR OTHER CONSTRUCTOR(S) HERE!

PlayerChar::PlayerChar() {
    name = DEFAULT_NAME;
    strength = DEFAULT_STRENGTH;
    agility = DEFAULT_AGILITY;
    role = DEFAULT_ROLE;
    hp = strength * agility;
}

PlayerChar::PlayerChar(string a_name, string a_role){
    name = a_name;
    strength = DEFAULT_STRENGTH;
    agility = DEFAULT_AGILITY;
    role = a_role;
    hp = strength * agility;
}

//=====
// implement PlayerChar's accessors

string PlayerChar::getName() const {
    return name;
}

int PlayerChar::getStrength() const {
    return strength;
}

double PlayerChar::getAgility() const {
    return agility;
}

string PlayerChar::getRole() const {
    return role;
}

// WRITE CODE FOR OTHER ACCESSOR METHOD(S) HERE!

double PlayerChar::getHP() const{
    return hp;
}

//=====
// implement PlayerChar's mutators

void PlayerChar::setName(string new_name) {
    name = new_name;
}

void PlayerChar::setRole(string new_role) {
    role = new_role;
}

void PlayerChar::resetHP() {
    hp = strength * agility;
}


// WRITE CODE FOR OTHER MUTATOR METHOD(S) HERE!

void PlayerChar::setHP(double new_hp){
    hp = new_hp;
}

//=====
// implement PlayerChar's other methods

// method: printPlayerChar: void -> void
// purpose: expects nothing, has the side-effect of
//     printing to the screen the current data fields of the
//     calling PlayerChar instance, and returns nothing

void PlayerChar::printPlayerChar() const {
    cout << "PlayerChar name:       " << name  << endl
         << "           strength:   " << strength  << endl
         << "           agility:    " << agility  << endl
         << "           role:       " << role << endl;
}


// method: battle: PlayerChar -> void
// purpose: expects a PlayerChar (call by reference!), returns nothing
// side effects: calculates damage to each PlayerChar
//          reduces HP value of each PlayerChar
//          prints to the screen results of the battle
//          and declares a winner!

// WRITE CODE FOR BATTLE METHOD HERE!

void PlayerChar::battle(PlayerChar& opponent) {



    //initialize variables
    double p1Damage, p2Damage;
    p1Damage = getHP() * randPct();
    p2Damage = opponent.getHP() * randPct();
    cout << "\nBATTLE BEGINS!\n";

    //deal damage
    cout << getName() << " is going to deal " << p1Damage << " damage!" << endl;
    cout << opponent.getName() << " is going to deal " << p2Damage << " damage!" << endl;
    setHP(getHP() - p2Damage);
    opponent.setHP(opponent.getHP() - p1Damage);



    //check damage done is greater than health, floor to 0
    if(getHP() <= 0){
        setHP(0);
        cout << getName() << " has fainted!" << endl;
    }
    if(opponent.getHP() <= 0){
        cout << opponent.getName() << " has fainted!" << endl;
        opponent.setHP(0);
    }
    cout << getName() << " has " << getHP() << " health left!" << endl;
    cout << opponent.getName() << " has " << opponent.getHP() << " health left!" << endl;
    if(getHP() > opponent.getHP()){
        cout << getName() << " wins!" << endl;
    }
    else if(getHP() < opponent.getHP()) {
        cout << opponent.getName() << " wins!" << endl;
    } else {
        cout << "Its a tie!" << endl;
    }











}

// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments
// of 0.01 -- for use in battles between PlayerChars

double randPct() {
    double return_val;
    return_val = (rand() % 100 + 1) * 0.01;
    return return_val;
}
