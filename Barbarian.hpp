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
**		ABSTRACTION OF:	A Barbarian Warrior
**		PURPOSE:	Hold all function specific for a Barbarian Warrior
**		HOW TO USE:	Create a Barbrian object using the constructor and apply applicable
**				functions from the Character base class.
**		SUMMARY:	The barbarian has two functions:
**				The attack function takes the attack roll as an argument and
**				returns the total attack damage.
**				The defense function takes the total attack damage and the defense
**				roll to determine the actual damage done. This damage done is
**				applied to the defender and returned.
**************************************************************************************************/
// Barbarian.hpp

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

// Global constants
const int BARBARIAN_ATT_SIDES = 6;
const int BARBARIAN_ATT_NUM = 2;
const int BARBARIAN_DEF_SIDES = 6;
const int BARBARIAN_DEF_NUM = 2;
const int BARBARIAN_ARMOR = 0;
const int BARBARIAN_STR = 12;

#include "Character.hpp"

class Barbarian : public Character
{
	public:
		Barbarian();			// default constructor
		virtual int attack(int);
		virtual int defense(int, int);
};
#endif
