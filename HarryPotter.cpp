/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/26/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE HARRYPOTTER CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**************************************************************************************************/
// HarryPotter.cpp

#include "HarryPotter.hpp"

/**************************************************************************************************
** Description:	HarryPotter();						 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the HarryPotter	 **************************
**		class
**************************************************************************************************/
HarryPotter::HarryPotter() :
 Character (	HARRYPOTTER_ATT_NUM, HARRYPOTTER_ATT_SIDES, HARRYPOTTER_DEF_NUM,
		HARRYPOTTER_DEF_SIDES, HARRYPOTTER_ARMOR, HARRYPOTTER_STR	)
{
	setFighterType(HARRYPOTTER);
	setSpecial(false);
	canRevive = true;
}


/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.08::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the Character class.
**************************************************************************************************/
int HarryPotter::attack(int attackRoll)
{
	setSpecial(false);
	return attackRoll;
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member. This function
**		also has a special ability called HOGWARTS which revives Harry Potter to 20 
**		strength points if he hasn't revived once before. 
**************************************************************************************************/
int HarryPotter::defense(int attDmg, int defRoll)
{
	setSpecial(false);

	// calculate total damage
	int totalDmg =  attDmg - (defRoll + getArmorVal());

	// if damage was done, apply damage and return the total damage
	if (totalDmg > 0)
	{
		// apply the damage to the character
		setStrengthVal(getStrengthVal() - totalDmg);

		// SPECIAL ABILITY: HOGWARTS
		// if the strengthVal is 0 or below, check if the target can revive
		if (getStrengthVal() < 1)
		{
			if (canRevive == true)
			{
				setSpecial(true);
				setStrengthVal(HARRYPOTTER_REVIVE);
				canRevive = false;
			}
			else
			{
				setAlive(false);
			}
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

