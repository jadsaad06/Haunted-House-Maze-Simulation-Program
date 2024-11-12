//Name: Jad Saad
//Purpose: Holds all base classes of every possible haunted house
//Helps protect the data and data structures from the user
#include "attractions.h"

//Haunted House Functions
HauntedHouse::HauntedHouse():jumpscares(50), scareLevels(50){
    srand(time(0));
}


//reads from file while protecting from the user
bool HauntedHouse::begin(){
    return readFromFile();
}

//takes in jumpscares and corresponding scare levels
bool HauntedHouse::readFromFile(){
    ifstream inFile;

    bool loaded = true;
    
    inFile.open("jumpscareList.txt");

    if(inFile.is_open()){
        string jumpscare;
        int scareLevel;
        int i = 0;

        getline(inFile, jumpscare, ';');

        while(!inFile.eof()){
            inFile >> scareLevel;

            jumpscares[i] = jumpscare;
            scareLevels[i] = scareLevel;

            inFile.ignore();
            getline(inFile, jumpscare, ';');
            i++;
        }
    }else{
        loaded = false;
    }

    
    return loaded;
}

    
//move through the array of linked lists
bool HauntedHouse::moveThrough(int move){
    bool isCorrect = hauntedHouse.checkDirection(move);
    bool isCrazy = true;
    int random = rand() % 50;

    string jumpscare = jumpscares[random];
    int sanityInc = scareLevels[random]; 
    
    //jumpscares and increases sanity
    if(!isCorrect){
        cout << jumpscare << endl;
        cout << "Current Sanity: "; 
        isCrazy = hauntedHouse.increaseSanity(sanityInc);
        hauntedHouse.displayCurrSanity();

        return isCrazy;//if sanity over 100 return true
    }else{
        cout << "\nCorrect move, entering the next room...\n";
    }

    bool isFinished = hauntedHouse.checkIfFinished();

    return isFinished;
}



//Corn Maze Function
CornMaze::CornMaze(){
    for(int i = 0; i < 3; i++){
        checkChoice[i] = i;
    }
}


CornMaze::~CornMaze(){
    delete[] checkChoice;
}

void CornMaze::resetChoiceCheck(){
    for(int i = 0; i < 3; i++){
        checkChoice[i] = 0;
    }
}

bool CornMaze::checkIfValid(int userMove){
    if(checkChoice[userMove]){
        return true;
    }

    return false;
}

bool CornMaze::moveThroughMaze(int move){
    return cornMaze.moveThrough(move);
}

//TreatHunt 

//constructor
TreatHunt::TreatHunt():treatPath(8), sniffCount(5), currIndex(0){
    createTreatPath();
}

bool TreatHunt::moveThrough(int move){
    if(move == treatPath[currIndex]){
        cout << "\nTreat Collected!\n";
        dog.collectTreat();
    }else{
        cout << "\nNo treat here :(\n";
    }

    currIndex++;

    if(currIndex == 8){
        cout << "\nYou've made it through!\n";
        cout << "Final Treat Count: ";
        dog.displayTreatCount();
        return true;
    }
    
    return false;
}

    

//choosed 1,2, or 3 for path, number = direction
void TreatHunt::createTreatPath(){
    for(int& i : treatPath){
        i = rand() % 4;
    }
}

//tells them where the treat is
bool TreatHunt::sniffTreats(){
    bool isTreat = false;

    if(sniffCount == 0){
        cout << "\nNo more sniffs left!\n";
    }else{
        isTreat = dog.smellTreat(treatPath[currIndex]);

        if(!isTreat){
            sniffCount++;
        }else{
            sniffCount--;
        }
    }
    
    return isTreat;
}

