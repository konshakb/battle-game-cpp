


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  HarryPotter.cpp
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
#include "HarryPotter.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/***********************************
**  Function: Harry  Constructor
**  Description:  sets name armor strength and HarryDie
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
HarryPotter::HarryPotter() : Creature()
{
    this->name = "HarryPotter";
    this->armor = 0;
    this->strength = 10;
    HarryDie = new Die(6);
    revive = true;
}
/***********************************
**  Function: Harry Destructor
**  Description:  cleans up die pointer
**  Parameters:  
**  Pre-Conditions:  hanging pointers
**  Post-Conditions: frees up memory
**  Return:
**************************************/
HarryPotter::~HarryPotter() 
{
    delete HarryDie;
}
/***********************************
**  Function: attack()
**  Description:  Harry's attack
**  Parameters:  
**  Pre-Conditions:  strength > 0
**  Post-Conditions: attack role
**  Return:  attack int
**************************************/
int HarryPotter::attack()
{
    int attackOne = HarryDie->dieScore();
    //cout << attackOne << endl;
    int attackTwo = HarryDie->dieScore();
   // cout << attackTwo << endl;
    int harryPotterAttack = attackOne + attackTwo;
    
    //cout << "Harry Potter attacks: " << harryPotterAttack  << endl;
    return harryPotterAttack;
}
/***********************************
**  Function: defend()
**  Description:  Harry's defense revive after first death
**  Parameters: attck from other player 
**  Pre-Conditions:  strength > 0
**  Post-Conditions: strength returned possible death
**  Return: int strength
**************************************/
int HarryPotter::defend(int oppAttack)
{
    int defendOne = HarryDie->dieScore();
    //cout << defendOne << endl;
    int defendTwo = HarryDie->dieScore();
    //cout << defendTwo << endl;
    int harryPotterDefend = defendOne + defendTwo;
    cout << "Harry Potter defends with a roll of: " << harryPotterDefend << endl;
    int damage = (oppAttack - harryPotterDefend);
    //cout << damage << " before armor " << endl;
    if (damage < 1)
    {
        damage = 0;
        cout << "No damage inflicted " << endl;
        
    }
    else 
    {
        strength -= (damage-armor);//subtract from damage if any damage occured
        cout << "Damage inflected: " << (damage-armor) << endl;
    }
    
    if (strength < 0)
        strength = 0;
    if (strength == 0 && revive  )
        revives(strength);

   // cout << "DEFEND" << endl;
    return strength;
}

/***********************************
**  Function:revives
**  Description:  Harry comes back to life
**  Parameters:  strength
**  Pre-Conditions:  strength = 0
**  Post-Conditions: strength =  20, bool is false
**  Return:  bool false
**************************************/
bool HarryPotter::revives(int& strength)
{   strength = 20;
    revive = false;
    cout << "Harry Potter rises again!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    return revive;
}
    
