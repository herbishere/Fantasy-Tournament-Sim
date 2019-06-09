/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/05/2019
** Description: THIS IS THE HEADER FILE OF THE VAMPIRE CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		ABSTRACTION OF:	A Vampire Warrior
**		PURPOSE:	Hold all function specific for a Vampire Warrior
**		HOW TO USE:	Create a Vampire object using the constructor and apply applicable
**				functions from the Character base class, or functions for the
**				vampire.
**		SUMMARY:	The Vampire has two functions:
**				The attack function takes the attack roll as an argument and
**				returns the total attack damage.
**				The defense function takes the total attack damage and the defense
**				roll to determine the actual damage done. This damage done is
**				applied to the defender and returned. Furthermore, the defense
**				function also has the Vampire's Special Move: CHARM, which has a
**				50% chance of negating the attacker's damage.
**************************************************************************************************/
// Vampire.hpp

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

// Global constants
const int VAMPIRE_ATT_SIDES = 12;
const int VAMPIRE_ATT_NUM = 1;
const int VAMPIRE_DEF_SIDES = 6;
const int VAMPIRE_DEF_NUM = 1;
const int VAMPIRE_ARMOR = 1;
const int VAMPIRE_STR = 18;

#include "Character.hpp"

class Vampire : public Character
{
	public:
		Vampire();			// default constructor
		virtual int attack(int);
		virtual int defense(int,int);
};
#endif
