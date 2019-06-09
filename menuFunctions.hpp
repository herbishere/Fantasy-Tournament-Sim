/********************************************************************************
** Program name: Program 04 - Fantasy Combat Tournament
** Author: Herbert Diaz <diazh@oregonstate.edu>
** Date: 2/23/2019
** Description: THIS IS THE HEADER FILE FOR THE MENU FUNCTIONS
**  This program simulates combat between two teams of fighters. Users can select
**  the number ofFighters in each team and choose from different fighter types:
**  Barbarians, Vampires, Medusas, Blue Men, and Harry Potters to add to the
**  team. Once both teams are configured, the winner of each match is displayed
**  until a team has run out of fighters. Once completed, the user can view the
**  losers and re-run the program if they choose to.
********************************************************************************/
// menuFunctions.hpp

#ifndef MENUFUNCTIONS_HPP
#define MENUFUNCTIONS_HPP

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::getline;
using std::string;

//Global Constants
const int IGNORE_NUMF   = 10000;
const int MIN_MENU      = 1;    // The Minimum Menu Value
const int MAX_MENU      = 2;    // The Maximum Menu Value
const int NUM_FIGHTERS  = 5;    // The Number of Different Fighters

// Utility Functions
void printBorder();
void cleanInput();

// Display Functions
void dispTitle();
void dispMenu();
void dispReplay();
void queryNumFighters(int);
void dispFighterConfig(int,int,int);
void dispFighterMenu();
void queryFighterName();

// Input Validation Functions
int validateMenu();
int validateNumFighters();
int validateFighterType();
string getFighterName();

#endif
