//CS 211 Spring 2024 - Week 02 Lab
// Bryan, Blake and Ambrose

/*=====
    a class representing a simple character in a role-playing game;
    has a name, strength, agility, and role

    last modified: 25 Jan 2023
=====*/

#ifndef PLAYERCHAR_H
#define PLAYERCHAR_H

#include <string>
using namespace std;

const string DEFAULT_NAME = "Fred";
const int DEFAULT_STRENGTH = 250;
const double DEFAULT_AGILITY = 5.0;
const string DEFAULT_ROLE = "Ogre";

// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments
// of 0.01 -- for use in PlayerChar battles

double randPct();

class PlayerChar {
    public:

        // constructors

        PlayerChar(string a_name, int a_strength, double an_agility,
                   string a_role);
        PlayerChar(string a_name, string a_role);
        PlayerChar();

        // accessors

        string getName() const;
        int getStrength() const;
        double getAgility() const;
        string getRole() const;
        double getHP() const;

        // mutators
        //
        // (here, a programmer can ONLY change a player character's
        //     name and role and HP directly)

        void setName(string new_name);
        void setRole(string new_role);
        void setHP(double new_hp);
        void resetHP();

        // other methods

        // method: printPlayerChar: void -> void
        // purpose: expects nothing, has the side-effect of
        //     printing to the screen the current data fields of the
        //     calling PlayerChar instance, and returns nothing

        void printPlayerChar() const;

        // method: battle: PlayerChar -> void
        // purpose: expects a PlayerChar, returns nothing
        // side effects: calculates damage to each PlayerChar
        //          reduces HP value of each PlayerChar
        //          prints to the screen results of the battle

        void battle(PlayerChar& opponent);

    private:
        string name;
        int    strength;
        double agility;
        string role;
        double hp;

};   // DO NOT FORGET the SEMICOLON!

#endif
