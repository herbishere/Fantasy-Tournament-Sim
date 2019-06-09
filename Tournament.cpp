/********************************************************************************
** Program name: Program 04 - Fantasy Combat Tournament
** Author: Herbert Diaz <diazh@oregonstate.edu>
** Date: 02/27/2019
** Description: THIS IS THE IMPLEMENTATION FILE FOR THE TOURNAMENT CLASS
**  This program simulates combat between two teams of fighters.
**  Users can select the number of Fighters in each team and choose from
**  different fighter types: Barbarians, Vampires, Medusas, Blue Men, and Harry
**  Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed,
**  the user can view the losers and re-run the program if they choose to.
********************************************************************************/
// Tournament.cpp

#include "Tournament.hpp"

/////////////////////////////////
// = PUBLIC MEMBER FUNCTIONS = //
/////////////////////////////////

/********************************************************************************
** Tournament(Lineup*, Lineup*, Lineup*)
**  This is the constructor for the Tournament class has the user set the
**  pointers to Lineup object data members.
** Arguments:
**  Lineup* team1 - Pointer to the Lineup for Team 1
**  Lineup* team2 - Pointer to the Lineup for Team 2
**  Lineup* defeated - Pointer to the List of Defeated Characters
** notes:
**  modified 02/28/2019 by HD
********************************************************************************/
Tournament::Tournament(Lineup* team1, Lineup* team2, Lineup* defeated)
{
    this->round = 1;
    this->scoreTeam1 = this->scoreTeam2 = 0;
    coin.setN(2);
    this->team1 = team1;
    this->team2 = team2;
    this->defeated = defeated;
}


/********************************************************************************
** void startTournament();
**  This function performs the entire Tournament.
** notes:
********************************************************************************/
void Tournament::startTournament()
{
    cout << "\nThe Tournament Has Begun!\n";

    // Fight Until One of the Teams has Run Out of Fighters
    while (!team1->isEmpty() && !team2->isEmpty())
    {
        fightRound();
    }

    // Declare Winner
    dispFinalStats();

    // Ask the user if they want to display the defeated lineup
    queryDefeated();
    int choice = validateDefeated();

    cout << "\n";

    if (choice == 1)
    {
        defeated->printLineup();
    }
}

//////////////////////////////////
// = PRIVATE MEMBER FUNCTIONS = //
//////////////////////////////////

/********************************************************************************
** void fightRound();
**  This function has a character from each team fighting until one is defeated.
**  The defeated character is then placed into the loser pile while the winner.
**  recovers some health and set sent to the back of their team's Lineup.
** notes:
**  Originally from Program 03 Battle::commence(Character*, Character*)
**  modified 02/28/2019 by HD
********************************************************************************/
void Tournament::fightRound()
{
    // Get Character Objects from Lineup
    Character* fighter1 = team1->getFrontFighter();
    Character* fighter2 = team2->getFrontFighter();

    int firstHit;

    // Fight Until One Character has no Strength
    while (fighter1->isAlive() == true && fighter2->isAlive() == true)
    {
        //flip a coin, 1 for fighter1, 2 for fighter2
        firstHit = coin.roll();

        // fighter 1 attacks first
        if (firstHit == 1)
        {
            fightSingle(fighter1,fighter2);
            // if fighter 2 is alive, continue counterattack
            if (fighter2->isAlive() == true)
            {
                fightSingle(fighter2,fighter1);
            }
        }
        // fighter 2 attacks first
        else if (firstHit == 2)
        {
            fightSingle(fighter2,fighter1);
            // if fighter 1 is alive, continue counterattack
            if (fighter1->isAlive() == true)
            {
                fightSingle(fighter1,fighter2);
            }
        }
    }

    // Declare the winner
    dispRoundInfo();

    // if Team 1 won
    if (team1->getFrontFighter()->isAlive())
    {
        // Recover Winner Health and Send to the Back of Lineup
        team1->getFrontFighter()->recoverStr();
        team1->frontToBack();
        scoreTeam1 += WSCOREMOD;
        // Send Loser to Defeated Lineup
        team2->moveFighter(defeated);
        scoreTeam2 += LSCOREMOD;
    }

    // if Team 2 won
    else
    {
        // Recover Winner Health and Send to the Back of Lineup
        team2->getFrontFighter()->recoverStr();
        team2->frontToBack();
        scoreTeam2 += WSCOREMOD;
        // Send Loser to Defeated Lineup
        team1->moveFighter(defeated);
        scoreTeam1 += LSCOREMOD;
    }

    // Increment the number of rounds
    round++;
}

/********************************************************************************
** void fightSingle();
**  This function commences a fight between an attacker and a defender Character
** Arguments:
**  Character* attacker - A pointer to the attacking Character
**  Character* defender - A pointer to the defending Character
** notes:
**  Originally from Program 03 Battle::fight(Character*, Character*)
**  modified 02/28/2019 by HD
********************************************************************************/
void Tournament::fightSingle(Character* attacker, Character* defender)
{
    // get the attacker's attack roll
    int attackRoll = attacker->rollAttack();

    // get the defender's defense roll
    int defenseRoll = defender->rollDefense();

    // get the attacker's total attack damage
    int attackDmg = attacker->attack(attackRoll);

    // get and apply the actual damage
    int actualDmg = defender->defense(attackDmg, defenseRoll);

}

///////////////////////////
// = DISPLAY FUNCTIONS = //
///////////////////////////

/********************************************************************************
** void dispRoundInfo(Character*, Character*)
**  This function displays the round information, including the current round,
**  who is fighting, and the winner.
** Arguments:
**  Character* fighter1, Character* fighter2 - The Two Fighters
** notes:
**  modified 02/28/2019 by HD
********************************************************************************/
void Tournament::dispRoundInfo()
{
    cout << "Round " << round << ": ";

    // Display team 1 fighter info
    cout << "Team 1 " << team1->getFrontType() << " " << team1->getFrontName();
    cout << " vs. ";

    // Display team 2 fighter info
    cout << "Team 2 " << team2->getFrontType() << " " << team2->getFrontName();
    cout << ", ";

    // Declare Winner
    if (team1->getFrontFighter()->isAlive())
    {
        cout << team1->getFrontType() << " " << team1->getFrontName();
    }
    else
    {
        cout << team2->getFrontType() << " " << team2->getFrontName();
    }

    cout << " Won!\n";
}

/********************************************************************************
** void dispFinalStats();
**  This function displays the final score, and declares the winner based on the
**  score.
** notes:
**  modified 02/28/2019 by HD
********************************************************************************/
void Tournament::dispFinalStats()
{
    cout << "\n";

    // Declare each team's score.
    cout << "Team 1 Final Score: " << scoreTeam1 << "\n";
    cout << "Team 2 Final Score: " << scoreTeam2 << "\n";

    // If Team 1 has a higher score
    if (scoreTeam1 > scoreTeam2)
    {
        cout << "Congratulations to Team 1 for Winning!\n";
    }
    // If Team 2 has a higher score
    else if (scoreTeam2 > scoreTeam1)
    {
        cout << "Congratulations to Team 2 for Winning!\n";
    }
    // If Both Teams have the same score
    else
    {
        cout << "It's a Draw! Thanks for Participating!\n";
    }
}

/********************************************************************************
** void queryDefeated();
**  This function asks the user if they would like to see the defeated Characters
** notes:
**  modified 02/28/2019 by HD
********************************************************************************/
void Tournament::queryDefeated()
{
    cout << "\n";
    cout << "View the Defeated Fighters?\n";
    cout << "   [1] Yes\n";
    cout << "   [2] No\n";
}

////////////////////////////////////
// = INPUT VALIDATION FUNCTIONS = //
////////////////////////////////////

/********************************************************************************
** int validateDefeated();
**  This function gets, validates, and returns the user's choice for queryDefated
** Returns:
**  An integer representing the user's choice.
** notes:
**  modified 02/28/2019 by HD
********************************************************************************/
int Tournament::validateDefeated()
{
    // Get Input
    int choice;
    cin >> choice;

    while (!cin || choice < 1 || choice > 2)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "<!>INPUT INVALID: PLEASE ENTER INTEGER BETWEEN 1 and 2<!>\n";
        cin >> choice;
    }

    return choice;
}
