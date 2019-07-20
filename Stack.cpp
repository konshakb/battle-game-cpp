

/***********************************
**  Author:  Bryan Konshak
**  Date:  11/6/2016
**  Description:  Stack.cpp Class
**************************************/
#include <iostream>
//#include <stdio.h>
//#include <unistd.h>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <iomanip>
#include "Creature.hpp"
#include "Stack.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
//using std::setw;

/***********************************
**  Function: Stack Constructor
**  Description:  sets head to NULL
**  Parameters:  
**  Pre-Conditions:
**  Post-Conditions:
**  Return:
**************************************/
Stack::Stack()
{
head = NULL;
}
/***********************************
**  Function:  Stack Desctructor
**  Description: Clean up dynamically allocated memore
**  Parameters:  
**  Pre-Conditions:  
**  Post-Conditions:
**  Return:
**************************************/
Stack::~Stack()
{
    StackNode *nodePtr = head;
    while (nodePtr != NULL)
    {
        StackNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

/***********************************
**  Function: push function add to stack
**  Description:  Adds double to beginning of stack
**  Parameters: double number
**  Pre-Conditions:
**  Post-Conditions:  sets nodePtr to head or at end of stack.  sets head
**  Return:
**************************************/
void Stack::push(Creature* creature)
{
/*    if (head == NULL)
        head = new StackNode(number);
    else
    {
    StackNode *nodePtr = new StackNode(number, head);//new stackNode
    nodePtr->value = number;//store the value
    nodePtr->next = head;
    head = nodePtr;
    }*/
    head = new StackNode(creature, head);//Thats it!  
}
/***********************************
**  Function: pop()
**  Description:  remove members from Stack
**  Parameters:  NONE
**  Pre-Conditions: if empty does nothing
**  Post-Conditions:  If not empty remove member from front of queue
**  Return: return the member that is removed
**************************************/
Creature* Stack::pop()
{
    if (head==NULL)
    {
        cout << "The list is empty" << endl;
        return 0;
    }
    else
    {
    StackNode *nodePtr;//create node and set it to head
    nodePtr = head;
    Creature* number = nodePtr->value;
    head = head->next;//set head to next node
    delete nodePtr;//delete prior head
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
void Stack::displayList()
{
    StackNode *nodePtr = head;
    cout <<"The losing creatures: ";
    while (nodePtr)
    {
        cout << nodePtr->value->getName() << "   ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
    
    
    
