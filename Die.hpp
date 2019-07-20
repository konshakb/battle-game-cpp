


/***********************************
**  Author:  Bryan Konshak
**  Date:  10/11/2016
**  Description:  Die class
**************************************/


#ifndef DIE_HPP
#define DIE_HPP

//
class Die
{
protected:
    int score;
    int sides;
public:
    Die(int sidesIn);
    Die();
    virtual ~Die();
    void setSides(int sideIn);
    int getSides();
    virtual int dieScore();
    int getScore();

};
#endif


