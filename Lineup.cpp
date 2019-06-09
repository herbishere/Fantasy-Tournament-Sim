/********************************************************************************
** Program name:Program 04 - Fantasy Combat Tournament
** Author:      Herbert Diaz <diazh@oregonstate.edu>
** Date:        02/26/2019
** Description: THIS IS THE IMPLEMENTATION FILE FOR THE LINEUP CLASS
**  This program simulates combat between two teams of fighters.
**  Users can select the number of Fighters in each team and choose from
**  different fighter types: Barbarians, Vampires, Medusas, Blue Men, and Harry
**  Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed,
**  the user can view the losers and re-run the program if they choose to.
********************************************************************************/
// Lineup.cpp

#include "Lineup.hpp"

/********************************************************************************
** Lineup();
**  This is the Constructor for the Lineup class
** notes:
**  modified 2/18/2019 by HD
********************************************************************************/
Lineup::Lineup()
{
    front = nullptr;
}

/********************************************************************************
** ~Lineup();
**  This is the Destructor for the Lineup Clsas
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
Lineup::~Lineup()
{
    if (front != nullptr)
    {
        FighterNode* temp = front;

        // Delete FighterNodes until reaching Last FighterNode
        while (temp->next != front)
        {
            FighterNode* trash = temp;
            delete trash->fighter;
            trash->fighter = nullptr;
            temp = temp->next;
            delete trash;
            trash = nullptr;
        }

        // Delete the Last FighterNode
        if (temp->next == front)
        {
            delete temp->fighter;
            temp->fighter = nullptr;
            delete temp;
            temp = nullptr;
        }
    }
}

/********************************************************************************
** bool isEmpty();
**  This function determines if the list is empty or not.
** Returns:
**  True if the List is Empty, False if the List is not Empty.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
bool Lineup::isEmpty()
{
    if (front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/********************************************************************************
** void addFighterBack(Character*, string);
**  This function creates a FighterNode and adds it to the back of the list
** Arguments:
**  This function takes a pointer to a character object for the FighterNode, and
**  a string to set the Character object's name.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void Lineup::addFighterBack(Fighter type, string name)
{
    // Get Create Character Derived Class Object
    Character* tempFighter;
    if (type == VAMPIRE)
    {
        tempFighter = new Vampire;
    }
    else if (type == BARBARIAN)
    {
        tempFighter = new Barbarian;
    }
    else if (type == BLUEMEN)
    {
        tempFighter = new BlueMen;
    }
    else if (type == MEDUSA)
    {
        tempFighter = new Medusa;
    }
    else if (type == HARRYPOTTER)
    {
        tempFighter = new HarryPotter;
    }

    // If the List is Empty, add the first FighterNode
    if (isEmpty())
    {
        front = new FighterNode;
        front->next = front;
        front->prev = front;
        front->fighter = tempFighter;
        tempFighter->setName(name);     // set the fighter's name
    }

    // Else Add Integer to List
    else
    {
        // Set the last FighterNode as lastOld
        FighterNode* lastOld = front->prev;

        // Create a new FighterNode
        FighterNode* lastNew = new FighterNode;

        // Make the FighterNode the "Last" FighterNode and Set the Val
        lastNew->next = front;
        lastNew->prev = lastOld;
        lastNew->fighter = tempFighter;

        // Set other FighterNodes to include the new FighterNode
        lastOld->next = lastNew;
        front->prev = lastNew;
        tempFighter->setName(name);     // set the fighter's name
    }
}

/********************************************************************************
** void addFighterFront(FighterNode*);
**  This function gets a FighterNode and adds it to the front of the list
** Arguments:
**  This function takes a pointer to a FighterNode and adds it to the Lineup
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void Lineup::addFighterFront(FighterNode* fighter)
{
    // If the List is Empty, add the first FighterNode
    if (isEmpty())
    {
        front = fighter;
        front->next = front;
        front->prev = front;
    }

    // Else Add Integer to List
    else
    {
        // Point to the first FighterNode
        FighterNode* firstOld = front;

        // Point to the new First FighterNode
        FighterNode* firstNew = fighter;

        // Point to the last FighterNode
        FighterNode* last = front->prev;

        // Set the new First FighterNode
        firstNew->next = firstOld;
        firstNew->prev = last;
        front = firstNew;

        // Set the old FighterNodes to point to the front;
        firstOld->prev = front;
        last->next = front;
    }
}


/********************************************************************************
** string getFrontType();
**  This function gets and returns the type of the fighter as a string
** Returns:
**  A string that states the type of Fighter for the Front's fighter member.
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
string Lineup::getFrontType()
{
    // If the Lineup is Empty, Inform User
    if (isEmpty())
    {
        cout << "\n<!>LINEUP IS EMPTY, NO FIGHTER TYPE RETURNED<!>\n";

        // return error number
        return "";
    }

    // Else Return the type of the front FighterNode's fighter
    else
    {
        Character* temp;
        temp = front->fighter;
        Fighter type = temp->getFighterType();
        if (type == VAMPIRE)
        {
            return "Vampire";
        }
        else if (type == BARBARIAN)
        {
            return "Barbarian";
        }
        else if (type == BLUEMEN)
        {
            return "Blue Men";
        }
        else if (type == MEDUSA)
        {
            return "Medusa";
        }
        else if (type == HARRYPOTTER)
        {
            return "Harry Potter";
        }
        else
        {
            return "ERROR_unassigned";
        }
    }
}

/********************************************************************************
** string getFrontName();
**  This function gets and returns the name of the Front's Character object
** Returns:
**  A string that contains the name of the Front's Character object
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
string Lineup::getFrontName()
{
    // If the Lineup is Empty, Inform User
    if (isEmpty())
    {
        cout << "\n<!>LINEUP IS EMPTY, NO NAME RETURNED<!>\n";

        // return error number
        return "";
    }

    // Else Return the name of the front FighterNode's character
    else
    {
        Character* temp;
        temp = front->fighter;
        string name = temp->getName();
        return name;
    }
}

/********************************************************************************
** void moveFighter(Lineup);
**  This function moves the front FighterNode from the Lineup into another Lineup
** notes:
**  modified 2/26/2019 by HD
********************************************************************************/
void Lineup::moveFighter(Lineup* otherLineup)
{
    // If the Lineup is Empty, Inform User
    if (isEmpty())
    {
        cout << "\n<!>QUEUE IS EMPTY, NO FIGHTERS REMOVED<!>\n";
    }

    // Else Remove the First FighterNode
    else
    {
        // If there are more than one FighterNode in the list.
        if (front->next != front)
        {
            // Get the next and prev FighterNodes
            FighterNode* tempNext = front->next;
            FighterNode* tempPrev = front->prev;

            // Connect them together
            tempNext->prev = tempPrev;
            tempPrev->next = tempNext;

            // Get Current Front FighterNode
            FighterNode* tempNode = front;
            otherLineup->addFighterFront(tempNode);

            // Set front to the next FighterNode
            front = tempNext;
        }
        // Else remove the last FighterNode
        else
        {
            FighterNode* tempNode = front;
            otherLineup->addFighterFront(tempNode);
            front = nullptr;
        }
    }
}


/********************************************************************************
** void frontToBack()
**  This function makes the front FighterNode the last FighterNode;
** notes:
**  modified 2/27/2019 by HD
********************************************************************************/
void Lineup::frontToBack()
{
    // If the Lineup is Empty, Inform User
    if (!isEmpty())
    {
        front = front->next;
    }
}

/********************************************************************************
** Character* getFrontFighter();
**  This function returns a pointer to the character object held in the
**  FighterNode's fighter member.
** notes:
**  modified 2/27/2019 by HD
********************************************************************************/
Character* Lineup::getFrontFighter()
{
    // If the Lineup is Empty, Inform User
    if (isEmpty())
    {
        cout << "\n<!>LINEUP IS EMPTY, NO FIGHTERS RETURNED<!>\n";
        return nullptr;
    }

    // Else Remove the First FighterNode
    else
    {
        return front->fighter;
    }
}

/********************************************************************************
** void printLineup()
**  This function prints all the type and name of each Character in the Lineup
** notes:
**  modified 2/19/2019 by HD
********************************************************************************/
void Lineup::printLineup()
{
    if (isEmpty())
    {
        cout << "\nThe Lineup is Empty!\n";
    }
    else
    {
        int count = 1;
        FighterNode* tempNode = front;

        cout << "The Defeated Fighters (from Last to First Defeated):\n";
        // Go through the List and Print the Integers
        do
        {
            Character* tempFighter = tempNode->fighter;

            // Get Fighter's Class
            Fighter type = tempFighter->getFighterType();
            string typeName;
            if (type == VAMPIRE)
            {
                typeName = "Vampire";
            }
            else if (type == BARBARIAN)
            {
                typeName = "Barbarian";
            }
            else if (type == BLUEMEN)
            {
                typeName = "Blue Men";
            }
            else if (type == MEDUSA)
            {
                typeName = "Medusa";
            }
            else if (type == HARRYPOTTER)
            {
                typeName = "Harry Potter";
            }
            else
            {
                typeName = "ERROR_unassigned";
            }
            string name = tempFighter->getName();

            cout << "   " << count << ") " << typeName << " " << name << "\n";
            tempNode = tempNode->next;
            count++;
        } while (tempNode != front);
        cout << "\n";
    }
}
