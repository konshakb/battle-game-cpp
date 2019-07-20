


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  Medusa.cpp
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
#include "Medusa.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/***********************************
**  Function: Medusa Constructor
**  Description:  sets name armor strength and MedusaeDie
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
Medusa::Medusa() : Creature()
{
    this->name = "Medusa";
    this->armor = 3;
    this->strength = 8;
    MedusaDie = new Die(6);
}
/***********************************
**  Function: Medusa Destructor
**  Description:  cleans up die pointer
**  Parameters:  
**  Pre-Conditions:  hanging pointers
**  Post-Conditions: frees up memory
**  Return:
**************************************/
Medusa::~Medusa() 
{
    delete MedusaDie;
}

/***********************************
**  Function: attack()
**  Description:  medusa's attack that wins if 12 is thrown
**  Parameters:  
**  Pre-Conditions:  strength > 0
**  Post-Conditions: attack role
**  Return:  attack int
**************************************/
int Medusa::attack()
{
    int attackOne = MedusaDie->dieScore();
    //cout << attackOne << endl;
    int attackTwo = MedusaDie->dieScore();
    //cout << attackTwo << endl;
    int medusaAttack = attackOne + attackTwo;
    if (medusaAttack == 12)
    {
        medusaAttack = 1000;
        cout << "TURNED TO STONE!! GAME OVER!!!" << endl;
        return medusaAttack;
    }
    else 
    {
      //  cout << "The medusa attacks: " << medusaAttack  << endl;
        return medusaAttack;
    }
}
/***********************************
**  Function: defend()
**  Description:  medusa's defense
**  Parameters: attck from other player 
**  Pre-Conditions:  strength > 0
**  Post-Conditions: strength returned possible death
**  Return: int strength
**************************************/
int Medusa::defend(int oppAttack)
{
    int medusaDefend = MedusaDie->dieScore();
    //cout << medusaDefend << endl;
    cout << "The Medusa defends with a roll of: " << medusaDefend << endl;
    int damage = (oppAttack - medusaDefend);
    //cout << damage << " before armor " << endl;
    if (damage < 1 || (damage - armor) < 0)
    {
        damage = 0;
        cout << "No damage inflicted" << endl;
        
    }
    else
    {
        if (damage-armor > 0 )
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
