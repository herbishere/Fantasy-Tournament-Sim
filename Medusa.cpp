/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/09/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE MEDUSA CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
*************************************************************************************/
// Medusa.cpp

#include "Medusa.hpp"

/**************************************************************************************************
** Description:	Medusa();						 **PUBLIC::2019.02.09::HD**
**		This is the default constructor for the Medusa class	 **************************
**************************************************************************************************/
Medusa::Medusa() : Character (	MEDUSA_ATT_NUM, MEDUSA_ATT_SIDES, MEDUSA_DEF_NUM,
				MEDUSA_DEF_SIDES, MEDUSA_ARMOR, MEDUSA_STR	)
{
	setFighterType(MEDUSA);
	setSpecial(false);
}

/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.09::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the Medusa class. If the attackRoll is 12, the function returns 999 dmg
**************************************************************************************************/
int Medusa::attack(int attackRoll)
{
	setSpecial(false);

	// check if special attack is triggered
	if (attackRoll == MEDUSA_ATT_NUM * MEDUSA_ATT_SIDES)
	{
		setSpecial(true);
		//SPECIAL ABILITY - GLARE
		return 999;
	}
	else
	{
		return attackRoll;
	}
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member.
**************************************************************************************************/
int Medusa::defense(int attDmg, int defRoll)
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

