/********************************************************************************
** Program name:    Program 04 - Fantasy Combat Tournament
** Author:          Herbert Diaz <diazh@oregonstate.edu>
** Date:            02/26/2019
** Description:     THIS IS THE HEADER FILE FOR THE FIGHTERNODE STRUCT
**  This program simulates combat between two teams of fighters.
**  Users can select the number of Fighters in each team and choose from
**  different fighter types: Barbarians, Vampires, Medusas, Blue Men, and Harry
**  Potters to add to the team. Once both teams are configured, the winner of
**  each match is displayed until a team has run out of fighters. Once completed,
**  the user can view the losers and re-run the program if they choose to.
** ABSTRACTION OF:  A single node that holds an Character object.
** PURPOSE:         Hold a pointer to the next and previous FighterNode variable
** HOW TO USE:      Create a Fighter variable and set the next and prev pointer
**                  and set the val data member with an integer.
** SUMMARY:         The QueueNode struct is used in conjunction with the Queue
**                  class to make a circularly linked list.
***                 This program uses a circular linked list that the user can
**                  manipulate. The user is provided a menu where the user can 
**                  add values to the back of a queue, display the first item of
**                  the queue, remove the front node, and display the node's
**                  content.
*******************************************************************************/
// FighterNode.hpp

#ifndef FIGHTERNODE_HPP
#define FIGHTERNODE_HPP

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

struct FighterNode
{
    FighterNode*    next;
    FighterNode*    prev;
    Character*      fighter;
};
#endif
