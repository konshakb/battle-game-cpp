




/***********************************
**  Program Filename:  Queue.cpp
**  Author:  Bryan Konshak
**  Date:  11/5/16
**  Description:  Queue class
**************************************/
#include <iostream>
//#include <stdio.h>
//#include <unistd.h>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <iomanip>
#include "Creature.hpp"
#include "Queue.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
//using std::setw;


/***********************************
**  Function: Queue Constructor
**  Description:  sets head and tail to NULL
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
Queue::Queue()
{
head = NULL;
tail = NULL;
empty = false;
}
/***********************************
**  Function:  Queue Desctructor
**  Description: Clean up dynamically allocated memore
**  Parameters:  
**  Pre-Conditions:  
**  Post-Conditions:
**  Return:
**************************************/
Queue::~Queue()
{
    QueueNode *nodePtr = head;
    while (nodePtr != NULL)
    {
        QueueNode *garbage = nodePtr;//clean up the dynamic memory
        nodePtr = nodePtr->next;
        delete garbage;
    }
}
/***********************************
**  Function: push function add to queue
**  Description:  Adds double to end of queue
**  Parameters: double number
**  Pre-Conditions:
**  Post-Conditions:  sets nodePtr to head or at end of queue.  sets tail and head
**  Return:
**************************************/

void Queue::push(Creature* number)
{
    QueueNode *nodePtr = new QueueNode(number);

    if (head == NULL)//set head and tail to the node pointer
    {
        head = tail = nodePtr;
//        cout << tail->value << " this is the end " << endl;

        
    }

    else
    {
        QueueNode *nodePtr = head;//traverse through the node
        while (nodePtr->next != NULL)
            nodePtr = nodePtr->next;

        nodePtr->next = new QueueNode(number);
        tail = nodePtr->next;
        if (nodePtr->next == NULL)
            tail = nodePtr->next;//tail at end of node
  //      cout << tail->value << " this is the end " << endl;

    }
        

}
/***********************************
**  Function: pop()
**  Description:  remove members from Queue
**  Parameters:  NONE
**  Pre-Conditions: if empty does nothing
**  Post-Conditions:  If not empty remove member from front of queue
**  Return: return the member that is removed
**************************************/
Creature* Queue::pop()
{
    if (head==NULL)
    {
        cout << "GAME OVER!" << endl;
        empty = true;
        return 0;
    }
    else
    {
    QueueNode *nodePtr;
    nodePtr = head;
    Creature* number = nodePtr->value;
    head = head->next;
    delete nodePtr;
    return number;
    }
}

/***********************************
**  Function: displayList()
**  Description: print the list
**  Parameters:
**  Pre-Conditions:  
**  Post-Conditions:  print the queue
**  Return:
**************************************/
void Queue::displayList()
{
    QueueNode *nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->value->getName() << "   ";
        nodePtr = nodePtr->next;
    }
    cout << endl << endl;
}
/***********************************
**  Function: getEmpty
**  Description: returns bool empty
**  Parameters:
**  Pre-Conditions:  
**  Post-Conditions:  will end game if empty queue
**  Return:
**************************************/
bool Queue::getEmpty()
{
return empty;
}
    
    
    
