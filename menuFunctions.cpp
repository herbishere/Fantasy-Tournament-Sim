/********************************************************************************
** Program name: Program 04 - Fantasy Combat Tournament
** Author: Herbert Diaz <diazh@oregonstate.edu>
** Date: 2/23/2019
**  This program simulates combat between two teams of fighters. Users can select
**  the number ofFighters in each team and choose from different fighter types:
**  Barbarians, Vampires, Medusas, Blue Men, and Harry Potters to add to the
**  team. Once both teams are configured, the winner of each match is displayed
**  until a team has run out of fighters. Once completed, the user can view the
**  losers and re-run the program if they choose to.
********************************************************************************/
// menuFunctions.cpp

#include "menuFunctions.hpp"

///////////////////////////
// = UTILITY FUNCTIONS = //
///////////////////////////

/********************************************************************************
** void printBorder();
** This function prints a border for display functions
** notes:
**  modified 2/18/2019 by HD
********************************************************************************/
void printBorder()
{
    cout << "\n";
    cout << "==================================================================";
    cout << "\n";
}

/********************************************************************************
** void cleanInput();
** This function combines cin.ignore and cin.clear for input.
** notes:
**  modified 2/18/2019 by HD
********************************************************************************/
void cleanInput()
{
    cin.clear();
    cin.ignore(IGNORE_NUMF,'\n');
}

///////////////////////////
// = DISPLAY FUNCTIONS = //
///////////////////////////

/********************************************************************************
** void dispTitle();
**  This function displays the title and description of the program.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void dispTitle()
{
    cout << "\n";
    cout << "===CS162===PROGRAM04_FANTASY_COMBAT_TOURNAMENT===HERBERT_DIAZ===\n";
    cout << "||   This program simulates a tournament between 2 teams of   ||\n";
    cout << "||   fighters. User sets the number of Fighters on each team  ||\n";
    cout << "|| and sets the type of each Fighter on the team. Once a team ||\n";
    cout << "||         runs out of fighters, the other team wins.         ||\n";
    cout << "================================================================\n";
    cout << "\n";
}

/********************************************************************************
** void dispMenu();
**  This function prints the main menu of the program.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void dispMenu()
{
    cout << "\n";
    cout << "Please Select an Option:\n\n";
    cout << "   [1] START\n";
    cout << "   [2] QUIT\n";
    cout << "\n";
}

/********************************************************************************
** void dispMenu();
**  This function prints the replay menu of the program.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void dispReplay()
{
    cout << "\n";
    cout << "Would You Like to Replay the Program?:\n\n";
    cout << "   [1] REPLAY\n";
    cout << "   [2] QUIT\n";
    cout << "\n";
}

/********************************************************************************
** void queryNumFighters(int)
** This function queries the user for the number of fighters on the team.
** ARGUMENTS:
**  int team = the team #
** notes:
**  modified 2/23/2019 by HD
********************************************************************************/
void queryNumFighters(int team)
{
    cout << "\n";
    cout << "How Many Fighters Would You Like on Team " << team << "? \n";
}

/********************************************************************************
** void dispFighterConfig(int, int, int)
**  This function informs the user about the current fighter being configured
** notes:
**  modified 2/23/2019 by HD
********************************************************************************/
void dispFighterConfig(int currentNum, int maxNum, int teamNum)
{
    cout << "\n";
    cout << "/Team " << teamNum << "/Fighter " << currentNum << " of " << maxNum;
    cout << "/\n";
}

/********************************************************************************
** void dispFighterMenu();
**  This function displays the fighter menu.
** notes:
**  modified 2/23/2019 by HD
********************************************************************************/
void dispFighterMenu()
{
    cout << "\n";
    cout << "Please Select a Fighter Type:\n\n";
    cout << "   [1] Barbarian\n";
    cout << "   [2] Vampire\n";
    cout << "   [3] Blue Men\n";
    cout << "   [4] Medusa\n";
    cout << "   [5] Harry Potter\n";
    cout << "\n";
}

/********************************************************************************
** void queryFighterName();
**  This function queries the user for the Fighter's name;
** notes:
**  modified 2/23/2019 by HD
********************************************************************************/
void queryFighterName()
{
    cout << "\n";
    cout << "What is this Fighter's name?\n";
    cout << "\n";
}

////////////////////////////////////
// = INPUT VALIDATION FUNCTIONS = //
////////////////////////////////////

/********************************************************************************
** int validateMenu();
**  This function gets, validates, and returns the user's choice for dispMenu()
** Returns:
**  This function returns an integer representing the user's choice.
** notes:
**  modified 2/11/2019 by HD
********************************************************************************/
int validateMenu()
{
    // Get Input
    int choice;
    cin >> choice;

    // Ask Until Input Valid
    while (!cin || choice < MIN_MENU || choice > MAX_MENU)
    {
        cleanInput();
        cout << "\n<!>INPUT INVALID: PLEASE ENTER INTEGER BETWEEN " << MIN_MENU;
        cout << " and " << MAX_MENU << "<!>\n";
        cin >> choice;
    }

    return choice;
}

/********************************************************************************
** int validateNumFighters();
**  This function gets, validates, and returns the user's choice for the number
**  of fighters.
** Returns:
**  This function returns an integer representing the user's choice.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
int validateNumFighters()
{
    // Get Input
    int choice;
    cin >> choice;

    // Ask Until Input Valid
    while (!cin || choice < 1)
    {
        cleanInput();
        cout << "\n<!>INPUT INVALID: PLEASE ENTER POSITIVE INTEGER<!>\n";
        cin >> choice;
    }

    return choice;
}


/********************************************************************************
** int validateFighterType();
**  This function gets, validates, and returns the user's choice for the type
**  of the fighter.
** Returns:
**  This function returns an integer representing the user's choice.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
int validateFighterType()
{
    // Get Input
    int choice;
    cin >> choice;

    // Ask Until Input Valid
    while (!cin || choice < MIN_MENU || choice > NUM_FIGHTERS)
    {
        cleanInput();
        cout << "\n<!>INPUT INVALID: PLEASE ENTER INTEGER BETWEEN " << MIN_MENU;
        cout << " and " << NUM_FIGHTERS << "<!>\n";
        cin >> choice;
    }

    return choice;
}

/********************************************************************************
** string getFighterName()
**  This function gets and returns the Fighter's name
** Returns:
    Returns a string that hold's the file's Name
** notes:
**  modified 2/23/2019 by HD
********************************************************************************/
string getFighterName()
{
    string name;
    // Get Input
    getline(cin,name);

    return name;
}
