
    //    letsPlay.moveAnt();

/***********************************
**  Author:  Bryan Konshak
**  Date:  10/25/1016
**  Description:  main for creature battles and driver functions to attack with different creatures
**************************************/
#include <iostream>
//#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>
#include "Die.hpp"
#include "Creature.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "battle.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    //Creature *playerOne[i] = NULL;
    //Creature *playerTwo[i] = NULL;
    Creature *creatureOne = NULL;//needed to hold Creature values and run battle
    Creature *creatureTwo = NULL;
    Creature** playerOne;//arrays to hold creatures
    Creature** playerTwo;
    Queue teamOne;//queues for each team
    Queue teamTwo;
    Stack losers;//stack for losing creatures
    int players;//number of players
    string teamNameOne, teamNameTwo;//names of team
cout << "Welcome to the CS162 Battle Royale!  You will pick two teams of monsters and they will battle it out!" << endl;
cout << "What is the name of Team One? " << endl;//get names and input validation
//cin.ignore(1000, 'n');
getline(cin, teamNameOne);
cout << "What is the name of Team Two? " << endl;
//cin.ignore(1000, 'n');
getline(cin, teamNameTwo);
    while (cout  << "How many creatures will fight for each team?  Select a number between 1 and 10: "  &&( !(cin >> players ) || players < 1 || players > 10))
        //  if user inputs int outside of range or a word, loops and asks again
    {
        
            cout << "That's not a number between 1 and 10. " << endl;
            cin.clear();//clear bad input
            cin.ignore(1000, '\n');//ignore till next line
    }


    playerOne = new Creature*[players];//arrays created
    playerTwo = new Creature*[players];
    
    //cout << boardArray[0][0]->getName() << endl;

    

//    int wins1 = 0;
//    int wins2 = 0;
string menu;
cout << "Team " << teamNameOne << " pick your team!" << endl;//pick the teams using this menu
    for (int i =0; i < players; i++)
    {
    //    playerOne[i] = new Creature();
do
{   //menu template pick a monster
    cout << "(1) Barbarian " << endl;
    cout << "(2) Vampire " << endl;
    cout << "(3) Blue Men " << endl;
    cout << "(4) Medusa " << endl;
    cout << "(5) Harry Potter " << endl;
    //cout << "(4) MENU OPTION 4! " << endl;
    cout << "Choose option 1, 2, 3, 4, or 5: " << endl;
    cin >> menu;
    cin.clear();
    cin.ignore(1000, '\n');
    
    
}  while (menu != "1" && menu != "2" && menu != "3" && menu != "4" && menu != "5");
    if (menu == "1")
    {
    playerOne[i] = new Barbarian();//type of creature object
    teamOne.push(playerOne[i]);//push to queue
    cout << teamNameOne << ": " ;//list the picked creatures
    teamOne.displayList();
    //cout << teamOne.getEmpty() << endl;

    }
    if (menu == "2")
    {
    playerOne[i] = new Vampire();
    teamOne.push(playerOne[i]);
    cout << teamNameOne << ": " ;
    teamOne.displayList();
    }
    if (menu == "3")
    {
    playerOne[i] = new BlueMen();
    teamOne.push(playerOne[i]);
    cout << teamNameOne << ": " ;
    teamOne.displayList();
    }
    if (menu == "4")
    {
    playerOne[i] = new Medusa();
    teamOne.push(playerOne[i]);
    cout << teamNameOne << ": " ;
    teamOne.displayList();
    }
    if (menu == "5")
    {
    playerOne[i] = new HarryPotter();
    teamOne.push(playerOne[i]);
    cout << teamNameOne << ": " ;
    teamOne.displayList();
    }
}
cout << "Team " << teamNameTwo << " pick your team!" << endl;
    for (int i =0; i < players; i++)
    {
    //    playerOne[i] = new Creature();
do
{   //menu template
    cout << "(1) Barbarian " << endl;
    cout << "(2) Vampire " << endl;
    cout << "(3) Blue Men " << endl;
    cout << "(4) Medusa " << endl;
    cout << "(5) Harry Potter " << endl;
    //cout << "(4) MENU OPTION 4! " << endl;
    cout << "Choose option 1, 2, 3, 4 or 5 " << endl;
    cin >> menu;
    cin.clear();
    cin.ignore(1000, '\n');
    
    
}  while (menu != "1" && menu != "2" && menu != "3" && menu != "4" && menu != "5");
    if (menu == "1")
    {
    playerTwo[i] = new Barbarian();
    teamTwo.push(playerTwo[i]);
    cout << teamNameTwo << ": " ;
    teamTwo.displayList();
    }
    if (menu == "2")
    {
    playerTwo[i] = new Vampire();
    teamTwo.push(playerTwo[i]);
    cout << teamNameTwo << ": " ;
    teamTwo.displayList();
    }
    if (menu == "3")
    {
    playerTwo[i] = new BlueMen();
    teamTwo.push(playerTwo[i]);
    cout << teamNameTwo << ": " ;
    teamTwo.displayList();
    }
    if (menu == "4")
    {
    playerTwo[i] = new Medusa();
    teamTwo.push(playerTwo[i]);
    cout << teamNameTwo << ": " ;
    teamTwo.displayList();
    }
    if (menu == "5")
    {
    playerTwo[i] = new HarryPotter();
    teamTwo.push(playerTwo[i]);
    cout << teamNameTwo << ": " ;
    teamTwo.displayList();
    }
}
creatureOne = teamOne.pop();//first two craetures to battle 
creatureTwo = teamTwo.pop();

        cout << "\33[2J\033[1;1H" << endl;//refresh the screen
battle(creatureOne, creatureTwo, teamOne, teamTwo, losers, teamNameOne, teamNameTwo);//run simulation and enjoy

delete [] playerOne;
delete [] playerTwo;

return 0;
}

