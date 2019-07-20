
/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  Stack header file
**************************************/

#ifndef STACK_HPP
#define STACK_HPP


#include <string>

class Stack
{

protected:
    struct StackNode
    {
        Creature* value;
        StackNode *next;
        StackNode(Creature* value1, StackNode *next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode *head;  //Stack head pointer
public:
    Stack();
    ~Stack();
    void push(Creature*);
    Creature* pop();
    void displayList();
    
    
   
};
#endif


    
    
    
    
