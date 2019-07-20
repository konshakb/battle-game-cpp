

/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2017
**  Description:  Vampire Header File
**************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP


#include <string>

class Vampire : public Creature
{
    protected:
        Die* VampireDieAttack;
        Die* VampireDieDefense;
//    std::string name;

public:
    Vampire();
    ~Vampire();
    int attack();
    int defend(int);
    bool charmTrue();
    //std::string name;

};
#endif


    
    
    
