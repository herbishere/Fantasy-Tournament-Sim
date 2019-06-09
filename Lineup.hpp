/********************************************************************************
** Program name:    Program 04 - Fantasy Combat Tournament
** Author:          Herbert Diaz <diazh@oregonstate.edu>
** Date:            02/26/2019
** Description:     THIS IS THE HEADER FILE FOR THE LINEUP CLASS
**  This program simulates combat between two teams of fighters.
**  Users can select the number of Fighters in each team and choose from
**  different fighter types: Barbarians, Vampires, Medusas, Blue Men, and Harry
**  Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed,
**  the user can view the losers and re-run the program if they choose to.
** ABSTRACTION OF:  A Lineup of Different Fighters
** PURPOSE:         Encapsulate the variables and functions related to a cirular
**                  linked list.
** HOW TO USE:      Create a Lineup object using the constructor and use public
**                  functions on the object.
** SUMMARY:         Lineup() - Use constructor to create a Queue object.
**                  ~Lineup() - Deconstructor
**                  isEmpty() - Determines if the list is empty
**                  addFighter() - Adds a FighterNode to the List
**                  moveFighter() - Moves a fighter from one Lineup to Another
**                  getFighter() - Returns a character object
*******************************************************************************/
// Lineup.hpp

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include <iostream>
#include <string>

#include "FighterNode.hpp"

using std::cout;
using std::cin;
using std::string;

class Lineup
{
    private:
        FighterNode* front;
    public:
        Lineup();
        ~Lineup();
        bool isEmpty();
        void addFighterBack(Fighter, string);
        void addFighterFront(FighterNode*);
        string getFrontType();
        string getFrontName();
        void moveFighter(Lineup*);
        void frontToBack();
        Character* getFrontFighter();
        void printLineup();
};
#endif
