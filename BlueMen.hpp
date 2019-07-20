


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2017
**  Description:  Blue Men Header file
**************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


#include <string>

class BlueMen : public Creature
{
    protected:
        Die* BlueDefense;
        Die* BlueAttack;
//    std::string name;

public:
    BlueMen();
    ~BlueMen();
    int attack();
    int defend(int);
    int mob(int);



};
#endif


    
    
    
