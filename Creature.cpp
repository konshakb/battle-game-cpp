

/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  Critter.cpp class
**************************************/
#include <iostream>
//#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "Creature.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/***********************************
**  Function: Creature Constructor
**  Description:  Not used
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
Creature::Creature()
{
  //  this->name = "CREATURE";
}
Creature::~Creature()
{
}

std::string Creature::getName()
{return name;}
int Creature::getStrength() 
{return strength;}
bool Creature::charmTrue()
{
    return true;
}
int Creature::mob(int)
{
    return -19;
}
bool Creature::revives(int&)
{
    return true;
}
void Creature::regainStrength()
{
    strength *= 1.5;
}

