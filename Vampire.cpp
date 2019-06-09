/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/06/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE VAMPIRE CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
*************************************************************************************/
// Vampire.cpp

#include "Vampire.hpp"

/**************************************************************************************************
** Description:	Vampire();						 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the Vampire class	 **************************
**************************************************************************************************/
Vampire::Vampire() : Character (	VAMPIRE_ATT_NUM, VAMPIRE_ATT_SIDES, VAMPIRE_DEF_NUM,
					VAMPIRE_DEF_SIDES, VAMPIRE_ARMOR, VAMPIRE_STR	)
{
	setFighterType(VAMPIRE);
	setSpecial(false);
}

/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.08::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the Vampire class.
**************************************************************************************************/
int Vampire::attack(int attackRoll)
{
	setSpecial(false);
	return attackRoll;
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member. This defense 
**		function is outfitted with the Vampire's Special Move: GLARE, which has additional
**		the functionality of having a 50% chance of avoiding an attack
**************************************************************************************************/
int Vampire::defense(int attDmg, int defRoll)
{
	setSpecial(false);
	int totalDmg;
	
	// CHARM
	// Use attack die to determine whether to trigger a special attack or not
	int roll = rollAttack();

	// if the attack die rolls the lower 50% of its possible rolls, trigger damage
	if (roll <= ((VAMPIRE_ATT_SIDES * VAMPIRE_ATT_NUM) / 2))
	{	// calculate total damage
		totalDmg =  attDmg - (defRoll + getArmorVal());
	}
	// otherwise, do not trigger any damage done.
	else
	{	// return no damage
		totalDmg = 0;
		setSpecial(true);
	}

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
