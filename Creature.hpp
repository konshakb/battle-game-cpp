

/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  Creature Header File
**************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP


#include <string>

class Creature
{

protected:
    std::string name;
    int armor;
    int strength;
public:
    Creature();
    virtual ~Creature();
    virtual int attack()= 0;
    virtual int defend(int) = 0;
    virtual std::string getName(); 
    virtual int getStrength();
    virtual bool charmTrue();
    virtual int mob(int);
    virtual bool revives(int&);
    virtual void regainStrength();
    
    

    

    
    
   
};
#endif


    
    
    
