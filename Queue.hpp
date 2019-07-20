



/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/2016
**  Description:  Queue header file
**************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP


#include <string>

class Queue
{

protected:
    struct QueueNode
    {
        Creature* value;
        QueueNode *next;
        QueueNode *previous;
        QueueNode(Creature* value1, QueueNode *next1 = NULL)/* QueueNode *previous1 = NULL)*/
        {
            value = value1;
            next = next1;
            //previous = previous1;
        }
    };
    QueueNode *head;  //Stack head pointer
    QueueNode *tail;
    bool empty;
public:
    Queue();
    ~Queue();
    void push(Creature*);
    Creature* pop();
    void displayList();
    bool getEmpty();
    
    
   
};
#endif

    
    
