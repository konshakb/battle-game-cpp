


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  BlueMen.cpp
**************************************/
#include <iostream>
//#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "Die.hpp"
#include "Creature.hpp"
#include "BlueMen.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/***********************************
**  Function: BLUEMEN  Constructor
**  Description:  sets name armor strength and Blue die
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
BlueMen::BlueMen() : Creature()
{
    this->name = "BlueMen";
    this->armor = 3;
    this->strength = 12;
    BlueDefense = new Die(6);
    BlueAttack = new Die(10);
}
/***********************************
**  Function: blue menDestructor
**  Description:  cleans up die pointer
**  Parameters:  
**  Pre-Conditions:  hanging pointers
**  Post-Conditions: frees up memory
**  Return:
**************************************/
BlueMen::~BlueMen() 
{
    delete BlueDefense;
    delete BlueAttack;
}
/***********************************
**  Function: attack()
**  Description:  blue men's attack
**  Parameters:  
**  Pre-Conditions:  strength > 0
**  Post-Conditions: attack role
**  Return:  attack int
**************************************/
int BlueMen::attack()
{
    int attackOne = BlueAttack->dieScore();
    //cout << attackOne << endl;
    int attackTwo = BlueAttack->dieScore();
    //cout << attackTwo << endl;
    int totalAttack = attackOne + attackTwo;
    
    //cout << "The " << name << " attacks: " << totalAttack  << endl;
    return totalAttack;
}
/***********************************
**  Function: defend()
**  Description:  blue men's attack
**  Parameters: attck from other player 
**  Pre-Conditions:  strength > 0
**  Post-Conditions: strength returned possible death
**  Return: int strength
**************************************/
int BlueMen::defend(int oppAttack)
{
    int blueDefend = mob(strength);
    cout << "The Blue Men defend with a roll of: " << blueDefend << endl;
    int damage = (oppAttack - blueDefend);
    //cout << damage << " before armor " << endl;
    if (damage < 1)
    {
        damage = 0;
        cout << "No damage inflicted " << endl;
        
    }
    else 
    {
        if (damage-armor > 0)
        {
            strength -= (damage-armor);//subtract from damage if any damage occured
            cout << "Damage inflected: " << (damage-armor) << endl;
        }
        else
            cout << "No damage inflicted" << endl;
    }
    
    if (strength < 0)
        strength = 0;

   // cout << "DEFEND" << endl;
    return strength;
}
/***********************************
**  Function: mob
**  Description:  changes dice based on strength
**  Parameters:  strenth
**  Pre-Conditions:  strength
**  Post-Conditions: return attack role
**  Return:  int attack role
**************************************/
int BlueMen::mob(int)
{
//cout << "STRENGTH IN MOB FUNCTION: " << strength << endl;
    int defendOne = BlueDefense->dieScore();
   // cout << defendOne << endl;
    int defendTwo = BlueDefense->dieScore();
   // cout << defendTwo << endl;
    int defendThree = BlueDefense->dieScore();
   // cout << defendThree << endl;
    int blueMob;
if (strength > 8)
    blueMob = defendOne + defendTwo + defendThree;
else if (strength > 4)
    blueMob = defendOne + defendTwo;
else if (strength > 0)
    blueMob = defendOne;

return blueMob;
}
    












