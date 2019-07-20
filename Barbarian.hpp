


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2017
**  Description:  Barbarian header file
**************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP


#include <string>

class Barbarian : public Creature
{
    protected:
        Die* BarbarianDie;

public:
    Barbarian();
    ~Barbarian();
    int attack();
    int defend(int);


};
#endif


    
    
    
