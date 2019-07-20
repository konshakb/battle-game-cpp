


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/11/2016
**  Description:  Die Class
**************************************/
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include "Die.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Die::Die(int sideIn)
{
    sides = sideIn;//initialize with side input, use srand for die probability
    unsigned seed;
    seed = time(0);
    srand(seed);

}
Die::Die()
{
    this->sides = 6;
}
Die::~Die()
{

}
void Die::setSides(int sideIn)
{
    this->sides=sideIn;//set side function
}
 int Die::getSides()
{   cout << " should be six " << endl;
    return this->sides;
}
int Die::dieScore()
{
 /*   unsigned seed;
    seed = time(0);
    srand(seed);*/
    score = rand() % sides + 1;//probbility for dice
    return this->score;
}
int Die::getScore()
{
    return this->score;
}
