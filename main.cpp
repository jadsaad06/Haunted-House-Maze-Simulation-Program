//Name: Jad Saad
//Class: CS302
//Date: 10/21/2024
//Program: 1
//Purpose: This program is a Haunted House program that 
//traverses through either an array of LL, CLL, or vector
//treating each node/slot as a room

//The purpose of this file is to connect the frontend to the backend

#include "myutil.h"
#include "attractions.h"
#include "main.h"
int main(){
    int option = 0;

    cout << "Welcome to Jad's Spooookyyyy Haunted House/Maze Program!";
    cout << "\n\nWhich experience would you like?";
    cout << "\n(1) Adult\n(2) Child\n(3) Dog\n(4) Quit";
    cout << "\nEnter Here: ";
    cin >> option;
    while(!cin || option > 4 || option < 1){ 
        cin.clear();
        cin.ignore(100,'\n');
        cout << "\nInvalid Input!\n";
        cout << "\nEnter Here: ";
        cin >> option;
   }

   switch(option){
        case 1:
            hauntedHousePrompt();
            beginHauntedHouse();
            break;
        case 2:
            cornMazePrompt();
            beginCornMaze();
            break;
        case 3:
            treatHuntPrompt(); 
            beginTreatHunt();
            break; 
        case 4:
            break;
   }

    return 0;
}

void hauntedHousePrompt(){
    cout << "\nWelcome to the Haunted House Experience!";
    cout << "\n\nRules: ";
    cout << "\n\tYou have a fear meter, when the meter reaches 100... YOU LOSE\n";
    cout << "\n\tTake the wrong turn and you'll get jumpscared, the scarier\n\tthe jumpscare "
         << "the more your fear meter will increase\n";
    cout << "\n\tTake the right turn and your fear meter will be cut in half and you will proceed"
         << "\n\tto the next room.\n";
    cout << "\n\nThat's it for the main rules but most importantly, have fun!\n";
}

void cornMazePrompt(){
    cout << "\nWelcome to the Corn Maze Experience!"
         << "\n\nRules: "
         << "\n\tYou have a candy count! This candy can be found in the nooks and crannies"
         << "\n\tof the corn maze, so going the wrong direction isn't so bad!"
         << "\n\tTry to collect as much candy as you can and escape the maze"
         << "\n\nDon't get too lost and have fun!\n";
}

void treatHuntPrompt(){
    cout << "\nWelcome to the Treat Hunt Experience!"
         << "\n\nRules: "
         << "\n\tYou have a treat count, just like the corn maze, maneuver through the"
         << "\n\ttreat hunt and look for treats around you! Unlike the other attractions,"
         << "\n\tyou can use your doggy powers to sniff out treats and find out where they are!"
         << "\n\nEnjoy your trip!\n";
}

//initializes and runs haunted house
void beginHauntedHouse(){
    HauntedHouse hauntedHouse;
    int direc;

    if(!hauntedHouse.begin()){
        cout << "\nFailed to load files";
        return;
    }

    
   bool escaped = false;

    do{
        direc = move();
        escaped = hauntedHouse.moveThrough(direc);
    }while(!escaped);

}

//initializes and runs corn maze
void beginCornMaze(){
    CornMaze cornMaze;
    int direc;
    bool escaped = false;

    do{
        direc = move();
        escaped = cornMaze.moveThroughMaze(direc);
    }while(!escaped);
}

//initializes and runs treat hunt
void beginTreatHunt(){
    TreatHunt treatHunt;
    bool escaped;
    int direc;
    int sniff;

    do{
        cout << "Would you like to sniff for a treat?\nYes(1)/No(2): ";
        cin >> sniff;
        while(!cin || sniff > 2 || sniff < 1){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nInvalid Input\n";
            cout << "\nTry Again: ";
            cin >> sniff;
        }

        if(sniff == 1){
            treatHunt.sniffTreats();
        }
        
        direc = move();
        escaped = treatHunt.moveThrough(direc);
    }while(!escaped);
}

//generic move function
int move(){
    int move{0};

    cout << "\nYou're presented with three options, left(0), right(1), or forward(2)"
         << "\nTake your pick...: ";
    
    cin >> move; 

    while(!cin || move > 2){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nInvalid Input!\nTake your pick...: ";
        cin >> move;
    }


    return move;
}


