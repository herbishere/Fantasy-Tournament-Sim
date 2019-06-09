/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/26/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE CHARACTER  CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**************************************************************************************************/
// Character.cpp

#include "Character.hpp"

/**************************************************************************************************
** Description:	Character(int,int,int,int,int,int)			 **PUBLIC::2019.02.08::HD**
**             	This is the constructor for the character class.	 **************************
**************************************************************************************************/
Character::Character(int numAtt, int attSides, int numDef, int defSides, int armorVal, int strengthVal)
{
	this->numAtt = numAtt;
	attackDie.setN(attSides);
	this->numDef = numDef;
	defenseDie.setN(defSides);
	this->armorVal = armorVal;
	this->strengthVal = strengthVal;
	this->alive = true;
    this->name = "UNNAMED";
    this->strengthMax = strengthVal;
}

/**************************************************************************************************
** Description:	int rollAttack();					 **PUBLIC::2019.02.08::HD**
**             	Rolls the Attack Die a number of times determined by the **************************
**		numAtt data member and returns the total value
**************************************************************************************************/
int Character::rollAttack()
{
	int total = 0;

	for (int start = 0; start < numAtt; start++)
	{
		total += attackDie.roll();
	}

	return total;
}

/**************************************************************************************************
** Description:	int rollDefense();					 **PUBLIC::2019.02.08::HD**
**             	Rolls the Defense Die a number of times determined by	 **************************
**		numDef data member and returns the total value
**************************************************************************************************/
int Character::rollDefense()
{
	int total = 0;

	for (int start = 0; start < numDef; start++)
	{
		total += defenseDie.roll();
	}

	return total;
}

/********************************************************************************
** void recoverStr();
**  This function restores a random number of strength points
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void Character::recoverStr()
{
    if (strengthVal < strengthMax)
    {
        int strengthLost = strengthMax - strengthVal;
        Die strDie(strengthLost);
        int recover = strDie.roll();
        this->strengthVal += recover;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/// == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	int getNumAtt();					 **PUBLIC::2019.02.08::HD**
**             	This function returns the numAtt data member.		 **************************
**************************************************************************************************/
int Character::getNumAtt()
{
	return numAtt;
}

/**************************************************************************************************
** Description:	int getSidesAtt();					 **PUBLIC::2019.02.08::HD**
**             	This function returns the number of sides of the attack	 **************************
**		die.
**************************************************************************************************/
int Character::getSidesAtt()
{
	return attackDie.getN();
}

/**************************************************************************************************
** Description:	int getNumDef();					 **PUBLIC::2019.02.08::HD**
**             	This function returns the numDef data member.		 **************************
**************************************************************************************************/
int Character::getNumDef()
{
	return numDef;
}

/**************************************************************************************************
** Description:	int getSidesDef();					 **PUBLIC::2019.02.08::HD**
**             	This function returns the number of sides of the	 **************************
**		defense die.
**************************************************************************************************/
int Character::getSidesDef()
{
	return defenseDie.getN();
}

/**************************************************************************************************
** Description:	int getArmorVal();					 **PUBLIC::2019.02.08::HD**
**             	This function returns the armorVal data member.		 **************************
**************************************************************************************************/
int Character::getArmorVal()
{
	return armorVal;
}

/**************************************************************************************************
** Description:	int getStrengthVal();					 **PUBLIC::2019.02.08::HD**
**             	This function returns the strengthVal data member.	 **************************
**************************************************************************************************/
int Character::getStrengthVal()
{
	return strengthVal;
}

/**************************************************************************************************
** Description:	bool isAlive();						 **PUBLIC::2019.02.08::HD**
**             	This function returns the alive data member.		 **************************
**************************************************************************************************/
bool Character::isAlive()
{
	return alive;
}

/**************************************************************************************************
** Description:	bool getSpecial();					 **PUBLIC::2019.02.08::HD**
**             	This function returns the special data member.		 **************************
**************************************************************************************************/
bool Character::getSpecial()
{
	return special;
}

/**************************************************************************************************
** Description:	Fighter getFighterType();				 **PUBLIC::2019.02.08::HD**
**             	This function returns the fighter type data member.	 **************************
**************************************************************************************************/
Fighter Character::getFighterType()
{
	return type;
}

/********************************************************************************
** string getName();
**  This function gets the name of the Character
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
string Character::getName()
{
    return name;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/// == SET FUNCTIONS == SET FUNCTIONS == SET FUNCTIONS == SET FUNCTIONS == SET FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	void setStrengthVal(int)				 **PUBLIC::2019.02.08::HD**
**             	This function sets the strengthVal data member.		 **************************
**************************************************************************************************/
void Character::setStrengthVal(int strengthVal)
{
	this->strengthVal = strengthVal;
}

/**************************************************************************************************
** Description:	void setAlive(bool);					 **PUBLIC::2019.02.08::HD**
**             	This function sets the alive data member.		 **************************
**************************************************************************************************/
void Character::setAlive(bool alive)
{
	this->alive = alive;
}

/**************************************************************************************************
** Description:	void setNumDef(int)					 **PUBLIC::2019.02.08::HD**
**             	This function sets the numDef data member. 		 **************************
**************************************************************************************************/
void Character::setNumDef(int numDef)
{
	this->numDef = numDef;
}

/**************************************************************************************************
** Description:	void setNumDef(int)					 **PUBLIC::2019.02.08::HD**
**             	This function sets the numDef data member. 		 **************************
**************************************************************************************************/
void Character::setFighterType(Fighter type)
{
	this->type = type;
}

/**************************************************************************************************
** Description:	void setSpecial(bool)					 **PUBLIC::2019.02.08::HD**
**             	This function sets the special data member. 		 **************************
**************************************************************************************************/
void Character::setSpecial(bool special)
{
	this->special = special;
}

/********************************************************************************
** string getName();
**  This function sets the name of the Character
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void Character::setName(string name)
{
    this->name = name;
}
