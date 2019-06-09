/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/05/2019
** Description: THIS IS THE HEADER FILE OF THE CHARACTER CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**		ABSTRACTION OF:	A Medusa Warrior
**		PURPOSE:	Hold all function specific for a Medusa Warrior
**		HOW TO USE:	Create a Barbrian object using the constructor and apply applicable
**				functions from the Character base class, or functions for the
**				medusa.
**		SUMMARY:	The Medusa class has two functions:
**				The attack function takes the attack roll as an argument and
**				returns the total attack damage. The attack function includes the
**				additional functionality of doing 999 dmg when the Medusa rolls a
**				12. This is Medusa's special ablilty: GLARE
**				The defense function takes the total attack damage and the defense
**				roll to determine the actual damage done. This damage done is
**				applied to the defender and returned.
**************************************************************************************************/
// Medusa.hpp

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

// Global constants
const int MEDUSA_ATT_SIDES = 6;
const int MEDUSA_ATT_NUM = 2;
const int MEDUSA_DEF_SIDES = 6;
const int MEDUSA_DEF_NUM = 1;
const int MEDUSA_ARMOR = 3;
const int MEDUSA_STR = 8;

#include "Character.hpp"

class Medusa : public Character
{
	public:
		Medusa();			// default constructor
		virtual int attack(int);
		virtual int defense(int, int);
};
#endif
