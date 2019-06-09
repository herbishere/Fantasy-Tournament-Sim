/**************************************************************************************************
** Program name:Project 4 - Fantasy Combat Tournament
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/26/2019
** Description: THIS IS THE HEADER FILE OF THE CHARACTER CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**	ABSTRACTION OF:	The base class for all subsequent character classes
**	PURPOSE:	The Character base class holds all the member variables and
**			    functions that are utilized by the Derived classes
**	HOW TO USE:	Use Character as a base class and override virutal functions to
**				create own functions.
**	SUMMARY:	The constructor takes 6 variables to set the data members.
**				The attack function rely on rolling the die, which roll the attack
**				die a number of times depending the number of attack die.
**				The defense function relies on the defense roll, which is
**				determined similarly to the attack roll, as well as the armor value
**				data member. The attack and defense functions are virtual and can
**				be overridden by derived classes.
**				Get functions return specific data members.
**				Set functions set specific data members.
**************************************************************************************************/
// Character.hpp

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Die.hpp"

using std::string;

enum Fighter {ERROR, VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRYPOTTER};

class Character
{
	private:
		int numAtt;		// the number of attack die
		Die attackDie;
		int numDef;		// the number of defense die
		Die defenseDie;
		int armorVal;
        int strengthMax;
		int strengthVal;
		bool alive;
		bool special;
		Fighter type;
        string name;
	public:
		// the constructor
		Character(int, int, int, int, int, int);

		// attack functions
		virtual int attack(int) = 0;
		int rollAttack();
		// defense functions
		virtual int defense(int,int) = 0;
		int rollDefense();
        // recover functions
        void recoverStr();

		// get functions
		int getNumAtt();
		int getSidesAtt();
		int getNumDef();
		int getSidesDef();
		int getArmorVal();
		int getStrengthVal();
		bool isAlive();
		bool getSpecial();
		Fighter getFighterType();
        string getName();

		// set functions
		void setStrengthVal(int);
		void setAlive(bool);
		void setNumDef(int);
		void setFighterType(Fighter);
		void setSpecial(bool);
        void setName(string);
};
#endif
