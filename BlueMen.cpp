/**************************************************************************************************
** Program name:Project 4 - FANTASY COMBAT TOURNAMENT
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/26/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE BLUEMEN CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**************************************************************************************************/
// BlueMen.cpp

#include "BlueMen.hpp"

/**************************************************************************************************
** Description:	BlueMen();						 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the BlueMen class	 **************************
**************************************************************************************************/
BlueMen::BlueMen() : Character (	BLUEMEN_ATT_NUM, BLUEMEN_ATT_SIDES, BLUEMEN_DEF_NUM,
					BLUEMEN_DEF_SIDES, BLUEMEN_ARMOR, BLUEMEN_STR	)
{
	setFighterType(BLUEMEN);
	setSpecial(false);
}

/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.08::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the BlueMen class.
**************************************************************************************************/
int BlueMen::attack(int attackRoll)
{
	setSpecial(false);
	return attackRoll;
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member. This function
**		includes the special move, MOB, where the number of defense die of the Blue Men are
**		reduced for every 4 strengthVal lost.
**************************************************************************************************/
int BlueMen::defense(int attDmg, int defRoll)
{
	setSpecial(false);

	// calculate total damage
	int totalDmg =  attDmg - (defRoll + getArmorVal());

	// if damage was done, apply damage and return the total damage
	if (totalDmg > 0)
	{
		// apply the damage to the character
		setStrengthVal(getStrengthVal() - totalDmg);

		// apply the special effect: MOB
		// calculate lost health
		int lostStrength = BLUEMEN_STR - getStrengthVal();
		// hold the total dice when at max health
		int totalDice = BLUEMEN_DEF_NUM;
		// subtract 1 from the total dice for every BLUEMAN_STR strength lost
		while (lostStrength > 3)
		{
			lostStrength -= BLUEMAN_STR;
			totalDice--;
			setSpecial(true);
		}
		// set number of defense die to the amount according to strengthVal
		setNumDef(totalDice);

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

