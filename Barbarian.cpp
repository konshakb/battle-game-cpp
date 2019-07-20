


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  Barbarian cpp file
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
#include "Barbarian.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/***********************************
**  Function: Barbarian Constructor
**  Description:  sets name armor strength and BarbarianDie
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
Barbarian::Barbarian() : Creature()
{
    this->name = "Barbarian";
    this->armor = 0;
    this->strength = 12;
    BarbarianDie = new Die(6);
}
Barbarian::~Barbarian() 
/***********************************
**  Function: Barbarian Destructor
**  Description:  cleans up die pointer
**  Parameters:  
**  Pre-Conditions:  hanging pointers
**  Post-Conditions: frees up memory
**  Return:
**************************************/
{
    delete BarbarianDie;
}
/***********************************
**  Function: attack()
**  Description:  barbarian's attack
**  Parameters:  
**  Pre-Conditions:  strength > 0
**  Post-Conditions: attack role
**  Return:  attack int
**************************************/
int Barbarian::attack()
{
    int attackOne = BarbarianDie->dieScore();
    //cout << attackOne << endl;
    int attackTwo = BarbarianDie->dieScore();
    //cout << attackTwo << endl;
    int barbarianAttack = attackOne + attackTwo;
    
    //cout << "The barbarian attacks with a score of: " << barbarianAttack  << endl;
    return barbarianAttack;
}
int Barbarian::defend(int oppAttack)
/***********************************
**  Function: defend()
**  Description:  barbarian's attack
**  Parameters: attck from other player 
**  Pre-Conditions:  strength > 0
**  Post-Conditions: strength returned possible death
**  Return: int strength
**************************************/
{
    int defendOne = BarbarianDie->dieScore();
    //cout << defendOne << endl;
    int defendTwo = BarbarianDie->dieScore();
    //cout << defendTwo << endl;
    int barbarianDefend = defendOne + defendTwo;
    cout << "The Barbarian defends with a roll of: " << barbarianDefend << endl;
    int damage = (oppAttack - barbarianDefend);
   // cout << damage << " before armor " << endl;
//    int totalDamage=(damage-armor);
    if (damage < 1)
    {
        damage = 0;
        cout << "No damage inflicted " << endl;
        
    }
    else 
    {
        strength -= damage-armor;//subtract from damage if any damage occured
        cout << "Damage inflected: " << damage-armor << endl;
    }

    
    if (strength < 0)
        strength = 0;

   // cout << "DEFEND" << endl;
  // cout << "The Barbarian's remaining strength: " << strength;
    return strength;
}
