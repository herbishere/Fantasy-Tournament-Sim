/**************************************************************************************************
** Program name:Program 04 - Fantasy Combat Tournament
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/27/2018
** Description:	THIS IS THE IMPLEMENTATION FILE FOR THE DIE CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**************************************************************************************************/
// Die.cpp
#include "Die.hpp"


/**************************************************************************************************
** Description: Die();							 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the Die class that	 **************************
**		seeds the random function
**************************************************************************************************/
Die::Die()
{
	// Seed random generator
	static bool seed = false;
	if (seed == false)
	{
		srand(time(0));
		seed = true;
	}
}


/**************************************************************************************************
** Description: Die(int);						 **PUBLIC::2019.01.23::HD**
**		This is a constructor for the Die class that sets the	 **************************
**		number of sides of the die. 
**		Takes an integer as arguments to be stored in the N data member. 
**************************************************************************************************/
Die::Die(int sideIn)
{
	this->N = sideIn;

	// Seed random generator
	static bool seed = false;
	if (seed == false)
	{
		srand(time(0));
		seed = true;
	}
}

/**************************************************************************************************
** Description: roll();							 **PUBLIC::2019.01.23::HD**
**              Returns a random integer between 1 and N.		 **************************
**************************************************************************************************/
int Die::roll()
{
	return rand() % N + 1;
}

/**************************************************************************************************
** Description:	getN();							 **PUBLIC::2019.01.24::HD**
**		Returns the N data member.				 **************************
**************************************************************************************************/

int Die::getN()
{
	return N;
}


/**************************************************************************************************
** Description:	setN();							 **PUBLIC::2019.01.24::HD**
**		sets the number of sides of the die via the N		 **************************
**************************************************************************************************/

void Die::setN(int N)
{
	this->N = N;
}
