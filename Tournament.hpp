/********************************************************************************
** Program name: Program 04 - Fantasy Combat Tournament
** Author: Herbert Diaz <diazh@oregonstate.edu>
** Date: 02/27/2019
** Description: THIS IS THE HEADER FILE FOR THE TOURNAMENT CLASS
**  This program simulates combat between two teams of fighters.
**  Users can select the number of Fighters in each team and choose from
**  different fighter types: Barbarians, Vampires, Medusas, Blue Men, and Harry
**  Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed,
**  the user can view the losers and re-run the program if they choose to.
** ABSTRACTION OF: A Tournament Between Two Teams of Fighters
** PURPOSE: Encapsulate the functions related to the fight between two teams of
**  Character objects.
** HOW TO USE: Create a Tournament object 
** SUMMARY:
********************************************************************************/
// Tournament.hpp

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "Lineup.hpp"
#include "Die.hpp"
#include <iostream>

using std::cout;

// Global Variables
const int WSCOREMOD    = 2;
const int LSCOREMOD    = -1;

class Tournament
{
    private:                // member variables
        Lineup* team1;
        Lineup* team2;
        Lineup* defeated;
        int round;
        int scoreTeam1;
        int scoreTeam2;
        Die coin;           // for determining who goes first in combat
    public:
        Tournament(Lineup*, Lineup*, Lineup*);
        void startTournament();
    private:
        void fightRound();  // fight until only one character is alive
        void fightSingle(Character*, Character*); 
        // display functions
        void dispRoundInfo(); //results of fightRound
        void dispFinalStats();
        void queryDefeated();
        // validation functions
        int validateDefeated();
        
};
#endif
