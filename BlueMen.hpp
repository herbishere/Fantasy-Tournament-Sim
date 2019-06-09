/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/05/2019
** Description: THIS IS THE HEADER FILE OF THE BLUEMEN CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**		ABSTRACTION OF:	A BlueMen Warrior
**		PURPOSE:	Hold all function specific for a Blue Men Warrior
**		HOW TO USE:	Create a BlueMen object using the constructor and apply applicable
**				functions from the Character base class, or functions for the
**				blue men.
**		SUMMARY:	The Blue Men has two Functions:
**				The attack function takes the attack roll as an argument and
**				returns the total attack damage.
**				The defense() includes the Blue Men's special move MOB with its 
**				additional functionality of reducing the number of defense die 
**				every 4 strengthVal lost.
**************************************************************************************************/
// BlueMen.hpp

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

// Global constants
const int BLUEMEN_ATT_SIDES = 10;
const int BLUEMEN_ATT_NUM = 2;
const int BLUEMEN_DEF_SIDES = 6;
const int BLUEMEN_DEF_NUM = 3;
const int BLUEMEN_ARMOR = 3;
const int BLUEMEN_STR = 12;
const int BLUEMAN_STR = 4;

#include "Character.hpp"

class BlueMen : public Character
{
	public:
		BlueMen();			// default constructor
		virtual int attack(int);
		virtual int defense(int,int);
};
#endif
