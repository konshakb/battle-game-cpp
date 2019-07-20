


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2017
**  Description:  Medusa Header File
**************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP


#include <string>

class Medusa : public Creature
{
    protected:
        Die* MedusaDie;

public:
    Medusa();
    ~Medusa();
    int attack();
    int defend(int);

};
#endif


    
    
    
