/*********************************************************************************
 *  
***********************************
**  Function: battle()
**  Description:  runs the simulation of the creature tournament
**  Parameters:  CreatureOne, CreatureTwo, Queue One, Queue Two, Stack Loser, String team nameOne, teamNameTwo
**  Pre-Conditions: Runs when two creature teams are created
**  Post-Conditions: When one team's queue bool empty is false, the game ends and results are posted
**  Return: return the member that is removed
**************************************
 *
 *
 * **********************************************************************************/

#include <iostream>
//#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "Die.hpp"
#include "Creature.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "battle.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

void battle(Creature* creatureOne, Creature* creatureTwo, Queue teamOne, Queue teamTwo, Stack losers, string nameTeamOne, string nameTeamTwo)
{
    int wins1 = 0;//win totals
    int wins2 = 0;

    //for (int i = 0; i < players; i++)
while (teamOne.getEmpty() == false && teamTwo.getEmpty() == false)//game goes on until a queue is empty
{
    //A round of battle

    while (creatureOne->getStrength() != 0 && creatureTwo->getStrength() != 0)//game goes until someone dies
    {
    if (creatureOne->getStrength() != 0 && creatureTwo->getStrength() != 0)//attack if someone isn't dead--assures no ties
    {
        cout << "************************************************************************************************" << endl << endl;
        cout << "Team " <<nameTeamOne << ": " << creatureOne->getName()<< " attacks: " ;
        int attacksOne = creatureOne->attack() ;
        cout << attacksOne << endl;//show attack
        cout << "Team " <<nameTeamTwo << ": ";
        int defendsTwo = creatureTwo->defend(attacksOne);//show defense
        cout << creatureTwo->getName()<< " strength after attack: " << defendsTwo << endl << endl ;//show remaining strength
        cout << "************************************************************************************************" << endl << endl;
        //cout << "Press enter to continue\n";
        //cin.ignore();
                usleep(1005000);  //refresh rate
        cout << "\33[2J\033[1;1H" << endl;//refresh the screen
    }
    if (creatureOne->getStrength() != 0 && creatureTwo->getStrength() != 0)
    {
        cout << "************************************************************************************************" << endl << endl;
        cout << "Team " <<nameTeamTwo<<": " << creatureTwo->getName()<< " attacks: " ;
        int attacksTwo = creatureTwo->attack();
        cout << attacksTwo << endl;
        cout << "Team " <<nameTeamOne<<": " ;
        int defendsOne = creatureOne->defend(attacksTwo);
        cout << creatureOne->getName() <<" Strength after attack: " << defendsOne << endl << endl ;
        cout << "************************************************************************************************" << endl << endl;
        //cout << "Press enter to continue\n";
        //cin.ignore();
                usleep(1005000);  //refresh rate
        cout << "\33[2J\033[1;1H" << endl;//refresh the screen
    }
        //cout << endl;
    }
        //cout << playerOne[i]->getStrength() << "Here lies the getter for strength" << endl;
    if (creatureOne->getStrength()== 0)//someone died
    {
        cout <<  creatureTwo->getName() <<" from Team " << nameTeamTwo << " wins! " << endl;//declare winner
        wins2++;
        losers.push(creatureOne);//add to loser pile
        //cout << "Creature Two Strength is " << creatureTwo->getStrength() << endl;
        creatureTwo->regainStrength();//regain strength
        cout << creatureTwo->getName() << " gets a strength boost!  New strength is: " << creatureTwo->getStrength() << endl;
        teamTwo.push(creatureTwo);//winning creature goes to back of queue
        cout << "New Line-up for Team " << nameTeamOne << " is: " ;
        teamOne.displayList() ;//display lineup
        cout << "New Line-up for Team " << nameTeamTwo << " is: " ;
        teamTwo.displayList() ;
        cout << endl;
        cout << "Team " << nameTeamOne << " score: " << wins1 <<  endl;//display score
        cout << "Team " << nameTeamTwo << " score: " << wins2 <<  endl << endl;
        //cout << "Press enter to continue\n";
        //cin.ignore();
    
    }
    if (creatureTwo->getStrength()== 0)
    {
        cout << creatureOne->getName() <<" from Team " << nameTeamOne << " wins! " << endl;
        wins1++;
        losers.push(creatureTwo);
        //cout << "Creature One Strength is " << creatureOne->getStrength() << endl;
        creatureOne->regainStrength();
        cout << creatureOne->getName() << " gets a strength boost!  New strength is: " << creatureOne->getStrength() << endl;
        teamOne.push(creatureOne);
        cout << "New Line-up for Team " << nameTeamOne << " is: ";
        teamOne.displayList();
        cout << "New Line-up for Team " << nameTeamTwo << " is: ";
        teamTwo.displayList();
        cout << endl;
        cout << "Team " << nameTeamOne << " score: " << wins1 <<  endl;
        cout << "Team " << nameTeamTwo << " score: " << wins2 <<  endl << endl;
        //cout << "Press enter to continue\n";
        //cin.ignore();
    }
        //cout << "Press enter to continue\n";
        //cin.ignore();
    creatureOne = teamOne.pop();//next monster up to attack
    creatureTwo = teamTwo.pop();
    }
    cout << "Team " << nameTeamOne << " won " << wins1 << " times." << endl;//show winner
    cout << "Team " << nameTeamTwo << " won " << wins2 << " times." << endl;
    if (wins1 > wins2)
    cout << "Team " << nameTeamOne<< " wins!" << endl;
    else
    cout << "Team " << nameTeamTwo<< " wins!" << endl;
    losers.displayList();
}
//cout << "Player 1 wins: " <<  wins1 << endl;
//cout << "Player 2 wins: " <<  wins2 << endl;
//delete playerOne[i];//free memory
//delete playerTwo[i]

