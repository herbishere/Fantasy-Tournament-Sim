/********************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Herbert Diaz <diazh@oregonstate.edu>
** Date: 2/26/2019
** Description: THIS IS THE MAIN FUNCTION OF PROJECT 4
** PROGRAM FUNCTION: This program simulates combat between two teams of fighters.
**  Users can select the number of Fighters in each team and choose from
**  different fighter types: Barbarians, Vampires, Medusas, Blue Men, and Harry
**  Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed,
**  the user can view the losers and re-run the program if they choose to.
** TO RUN PROGRAM: In terminal run the makefile using the "make" command to run
**  the executable file "main".
********************************************************************************/
// main.cpp

#include "menuFunctions.hpp"
#include "Lineup.hpp"
#include "Tournament.hpp"

using std::cout;

int main()
{
    int choice; // Stores the user's choice for the main menu

    dispTitle();            // Show Program's description
    dispMenu();             // Show Program's main menu 
    choice = validateMenu();// Get User's choice
    cleanInput();
    printBorder();

    do
    {

        // Run the Program
        if (choice == 1)
        {
            // Create Lineup Objects
            Lineup team1;
            Lineup team2;
            Lineup defeated;

            // Create Tournament Object
            Tournament match(&team1, &team2, &defeated);

            // Configure The Numbers of Fighters for each team;
            queryNumFighters(1);    // for Team 1
            int numFight1 = validateNumFighters();
            printBorder();
            cleanInput();
            queryNumFighters(2);    // for Team 2
            int numFight2 = validateNumFighters();
            printBorder();
            cleanInput();

            // Configure Each Fighter on each Team Lineup
            // For Team 1
            for (int index = 0; index < numFight1; index++)
            {
                dispFighterConfig(index + 1, numFight1, 1);
                // Get Fighter Type
                dispFighterMenu();
                int fighter = validateFighterType();
                cleanInput();
                // Set Fighter Type
                Fighter type;
                if (fighter == 1)
                {
                    type = BARBARIAN;
                }
                else if (fighter == 2)
                {
                    type = VAMPIRE;
                }
                else if (fighter == 3)
                {
                    type = BLUEMEN;
                }
                else if (fighter == 4)
                {
                    type = MEDUSA;
                }
                else if (fighter == 5)
                {
                    type = HARRYPOTTER;
                }
                // Get Fighter's Name
                queryFighterName();
                string name = getFighterName();
                // Add Fighter To Team
                team1.addFighterBack(type,name);
            }
            printBorder();

            for (int index = 0; index < numFight2; index++)
            {
                dispFighterConfig(index + 1, numFight2, 2);
                // Get Fighter Type
                dispFighterMenu();
                int fighter = validateFighterType();
                cleanInput();
                // Set Fighter Type
                Fighter type;
                if (fighter == 1)
                {
                    type = BARBARIAN;
                }
                else if (fighter == 2)
                {
                    type = VAMPIRE;
                }
                else if (fighter == 3)
                {
                    type = BLUEMEN;
                }
                else if (fighter == 4)
                {
                    type = MEDUSA;
                }
                else if (fighter == 5)
                {
                    type = HARRYPOTTER;
                }
                // Get Fighter's Name
                queryFighterName();
                string name = getFighterName();
                // Add Fighter To Team
                team2.addFighterBack(type,name);
            }
            printBorder();

            // Start Tournament
            match.startTournament();
            cleanInput();
            printBorder();

            // Ask the user if they want to play again
            dispReplay();
            choice = validateMenu();
            cleanInput();
            printBorder();
        }
    } while (choice != 2);

	return 0;
}
