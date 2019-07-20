


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2017
**  Description:  HarryPotter Header File
**************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP


#include <string>

class HarryPotter : public Creature
{
    protected:
        Die* HarryDie;
        bool revive;

public:
    HarryPotter();
    ~HarryPotter();
    int attack();
    int defend(int);
    bool revives(int&);

};
#endif


    
    
    
