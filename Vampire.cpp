

/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  Vampire.cpp
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
#include "Vampire.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/***********************************
**  Function: Vampire Constructor
**  Description:  sets name armor strength and VampireDie
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
Vampire::Vampire() : Creature()
{
    this->name = "Vampire";
    this->armor = 1;
    this->strength = 18;
    VampireDieAttack = new Die(12);
    VampireDieDefense = new Die(6);
    unsigned seed;
    seed = time(0);
    srand(seed);
}
/***********************************
**  Function: Vampire Destructor
**  Description:  cleans up die pointer
**  Parameters:  
**  Pre-Conditions:  hanging pointers
**  Post-Conditions: frees up memory
**  Return:
**************************************/
Vampire::~Vampire()
{
    delete VampireDieAttack;
    delete VampireDieDefense;
}
/***********************************
**  Function: attack()
**  Description:  vampire's attack
**  Parameters:  
**  Pre-Conditions:  strength > 0
**  Post-Conditions: attack role
**  Return:  attack int
**************************************/
int Vampire::attack()
{
    int attack = VampireDieAttack->dieScore();
    //cout << "The vampire attacks: " << attack << endl;
    return attack;
}
/***********************************
**  Function: defend()
**  Description:  vampire's defense
**  Parameters: attck from other player 
**  Pre-Conditions:  strength > 0
**  Post-Conditions: strength returned possible death
**  Return: int strength
**************************************/
int Vampire::defend(int oppAttack)
{
    int defense = VampireDieDefense->dieScore();
    cout << "The Vampire defends with a roll of: " <<defense << endl;
    int damage = (oppAttack-defense);
    //cout << damage << " before armor " << endl;
    if (charmTrue())
    {
        cout << "The vampire charmed the attack! " << endl;
            return strength;
    }


    else if (damage < 1)
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

   // cout << "DEFEND" << endl;
    return strength;
}
/***********************************
**  Function: charmTrue
**  Description:  vampire charm dodges attack using srand
**  Parameters:  
**  Pre-Conditions:  called in defend()
**  Post-Conditions: either charmed or not
**  Return:  bool true or false
**************************************/
bool Vampire::charmTrue()
{
int charmChance;
charmChance = rand() % 2;
if (charmChance == 0)
    return false;
else return true;
}



