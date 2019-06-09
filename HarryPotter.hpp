/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/09/2019
** Description: THIS IS THE HEADER FILE OF THE CHARACTER CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**		ABSTRACTION OF:	A HarryPotter Warrior
**		PURPOSE:	Hold all function specific for a HarryPotter Warrior
**		HOW TO USE:	Create a Barbrian object using the constructor and apply applicable
**				functions from the Character base class, or functions for the
**				harrypotter.
**		SUMMARY:	Harry Potter has Two Functions:
**				The attack function takes the attack roll as an argument and
**				returns the total damage done.
**				The defense function takes the total attack damage and the defense
**				roll to determine the actual damage done. This damage done is
**				applied to the defender and returned. The defense function has a 
**				special ability called HOGWARTS where Harry Potter can revive if
**				the character dies and hasn't revived already.
**************************************************************************************************/
// HarryPotter.hpp

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

// Global constants
const int HARRYPOTTER_ATT_SIDES = 6;
const int HARRYPOTTER_ATT_NUM = 2;
const int HARRYPOTTER_DEF_SIDES = 6;
const int HARRYPOTTER_DEF_NUM = 2;
const int HARRYPOTTER_ARMOR = 0;
const int HARRYPOTTER_STR = 10;
const int HARRYPOTTER_REVIVE = 20;

#include "Character.hpp"

class HarryPotter : public Character
{
	private:
		bool canRevive;			// determines whether harrypotter can revive
	public:
		HarryPotter();			// default constructor
		virtual int attack(int);
		virtual int defense(int,int);
};
#endif
