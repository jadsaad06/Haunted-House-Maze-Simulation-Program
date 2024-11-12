#pragma once
#include "myutil.h"
#include "attendees.h"
#include "dataStructures.h"


//A haunted hosue for adults that implements
//an array of linked lists
class HauntedHouse{
    private:
        vector<string> jumpscares;
        vector<int> scareLevels;
        LLArray hauntedHouse;
        
        string chooseJumpscare();
        bool readFromFile();

    public:
        HauntedHouse();
        bool checkIfCorrect();
        bool begin();
        bool checkIfValidMove();
        bool moveThrough(int move);        
        
};

//corn maze made for children that implements
//a circular linked list
class CornMaze{
    private:
        CLL cornMaze;

        int* checkChoice = new int[3]; //if value == 1, cannot go direction
        bool checkIfCorrect(); //checking process will be different
        bool checkIfValid(int userMove); //check if direction has been entered previously
        void resetChoiceCheck();//put all values back to 0

    public:
        CornMaze();
        ~CornMaze();
        
        bool moveThroughMaze(int move);
};

class TreatHunt{
    private:
        vector<int> treatPath;
        int sniffCount;
        int currIndex;
        Dog dog;

        void createTreatPath();

    public:
        TreatHunt();
        bool sniffTreats();
        bool moveThrough(int move);        
};


