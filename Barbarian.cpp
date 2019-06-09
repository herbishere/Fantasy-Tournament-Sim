/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/06/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE BARBARIAN CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**************************************************************************************************/
// Barbarian.cpp

#include "Barbarian.hpp"

/**************************************************************************************************
** Description:	Barbarian();						 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the Barbarian class	 **************************
**************************************************************************************************/
Barbarian::Barbarian() : Character (	BARBARIAN_ATT_NUM, BARBARIAN_ATT_SIDES, BARBARIAN_DEF_NUM,
					BARBARIAN_DEF_SIDES, BARBARIAN_ARMOR, BARBARIAN_STR	)
{
	setFighterType(BARBARIAN);
	setSpecial(false);
}

/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.08::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the Barbarian class.
**************************************************************************************************/
int Barbarian::attack(int attackRoll)
{
	setSpecial(false);
	return attackRoll;
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member.
**************************************************************************************************/
int Barbarian::defense(int attDmg, int defRoll)
{
	setSpecial(false);

	// calculate total damage
	int totalDmg =  attDmg - (defRoll + getArmorVal());

	// if damage was done, apply damage and return the total damage
	if (totalDmg > 0)
	{
		// apply the damage to the character
		setStrengthVal(getStrengthVal() - totalDmg);

		// if the strengthVal is 0 or below, set the target as dead
		if (getStrengthVal() < 1)
		{
			setAlive(false);
		}

		// return the total damage
		return totalDmg;
	}
	// otherwise, return no damage
	else
	{
		return 0;
	}
}

