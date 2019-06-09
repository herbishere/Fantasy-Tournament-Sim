/**************************************************************************************************
** Program name:Program 04 - Fantasy Combat Tournament
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/08/2018
** Description:	THIS IS THE HEADER FILE FOR THE DIE CLASS
**  This program simulates combat between two teams of fighters. Users can select the number of 
**  Fighters in each team and choose from different fighter types: Barbarians, Vampires, Medusas,
**  Blue Men, and Harry Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed, the user can view
**  the losers and re-run the program if they choose to.
**		ABSTRACTION OF:	A Die with "N" number of sides.
**		PURPOSE:	Create a die and roll it to get a randomly chosen integer up to N.
**		HOW TO USE:	Create a die class and set the number of sides using the
**				constructor or Then, use the rollthedice function to get a random
**				number between 1 and N.
**		SUMMARY:	::::::Private Member Variables::::::
**				N represents the number of sides of the dice
**				::::::Public Member Functions::::::
**				Constructor sets the number of sides when dice is first declared.
**				roll() returns a random integer between 1 and N
**				::::::Protected Member Functions::::::
**				getN() returns the number of sides of the die object
**************************************************************************************************/
// Die.hpp
#ifndef DIE_HPP
#define DIE_HPP

#include <ctime>
#include <cstdlib>

using std::srand;

class Die
{
	private:
		int N;			// number of sides of the dice
		static bool seed;	// determines whether the class has been seeded or not.
	public:
		Die();			// default constructor
		Die(int);		// constructor
		virtual int roll();	// return a random integer between 1 and N
		int getN();		// returns the private member variable N
		void setN(int);		// this function sets the number of sides of the Die.
};

#endif
