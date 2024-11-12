//Name: Jad Saad
//Class: CS302
//Files: dataStructures.cpp
//Usage: Holds all functions of my data structructures
//       This is a bridge between the data and the user


#include "dataStructures.h"

//CLLnode Functions

//Constructors
CLLnode::CLLnode():Kid(),next(nullptr){
    correctChoice = setCorrectChoice();
}

CLLnode::~CLLnode(){
    next = nullptr;
}

//get and set next
CLLnode*& CLLnode::getNext(){
    return next;
}

void CLLnode::setNext(CLLnode* newNext){
    next = newNext;
}

//outputs name
void CLLnode::display(){
    cout << name << endl;
}

//sets the correct choice to one of the three options
int CLLnode::setCorrectChoice(){
    srand(time(0));

    int move = rand() % 3;

    return move;
}

bool CLLnode::checkDirection(int move){
    if(move == correctChoice){
        return true;
    }

    return false;
}


//CLL Implementation
CLL::CLL(){
    srand(time(0));

    int size = (rand() % 6) + 3;

    for(int i = 0; i < size; i++){
        add();
    }
}


CLL::~CLL(){
    removeAll();
}

//Wrapper function for adding, protects data
void CLL::add(){
    if(!rear){
        rear = new CLLnode;
        rear->setNext(rear);
    }

    add(rear->getNext());
}


//Adds node to the list
void  CLL::add(CLLnode* curr){
    if(!curr){
        curr = new CLLnode;
        curr->setNext(rear);
        return;
    }

    if(curr->getNext() == rear){
        CLLnode* newNode = new CLLnode;
        newNode->setNext(curr->getNext());

        curr->setNext(newNode);

        return;
    }

    add(curr->getNext());
}



//remove function, used in removeAll
bool CLL::remove(CLLnode* toRemove, CLLnode* curr){
    if(!rear->getNext()){
        delete rear;
        rear = nullptr;

        return true;
    }

    if(curr->getNext() == toRemove){
        curr->setNext(toRemove->getNext());
        
        if(toRemove == rear){
            rear = curr->getNext();
        }

        delete toRemove;
        toRemove = nullptr;
        
        return true;
    }

    return remove(toRemove, curr->getNext());
}

//removeAll functions, destroys CLL, used in destructor
bool CLL::removeAll(){
    bool removed = false;

    while(rear){
        removed = remove(rear, rear->getNext());
    }

    return removed;
}

//display function
void CLL::display(){
    if(!rear){
        cout << "\nEmpty List!";
    }
    
    CLLnode* curr = rear;

    display(curr);
}

void CLL::display(CLLnode* curr){
    curr->display();

    if(curr->getNext() == rear){
        return;
    }

    display(curr->getNext());
}

//move through the list
bool CLL::moveThrough(int move){
    bool isCorrect = curr->checkDirection(move);
    bool escaped = false;

    if(isCorrect){
        cout << "\nUp to the next section!\n";
        curr = curr->getNext();

        if(curr == rear){
            escaped = true;
        }
    }else{
        getCandy();
    }

    return escaped;
}

//get candy if wrong turn (50% chance)
void CLL::getCandy(){
    bool candy = rand() % 2;

    if(candy){
        cout << "\nYou found a candy!\n";
        curr->collectCandy();
    }else{
        cout << "\nHmmm... no candy here. Try a different direction!\n";
    }
}
/*********************************************************/

//Linked List Node Functions

//constructors
LLLnode::LLLnode():Adult(),next(nullptr){
    correctChoice = setCorrectChoice();
}

LLLnode::LLLnode(const LLLnode* toCopy): Adult(*toCopy), next(nullptr){
        correctChoice = setCorrectChoice();
}

//destructor
LLLnode::~LLLnode(){
    next = nullptr;
}

//get and set next and jumpscare
LLLnode*& LLLnode::getNext(){
    return next;
}

void LLLnode::setNext(LLLnode* newNext){
    next = newNext;
}

//outputs fearmeter at a certain room
void LLLnode::display(){
    displayScareMeter();
}


bool LLLnode::checkDirection(int move){
    cout << correctChoice;

    if(move == correctChoice){
        return true;
    }else{
        return false;
    }
}

int LLLnode::setCorrectChoice(){
    int random = rand() % 3;
    
    return random;
}

//Linked List Array Functions

//constructor
LLArray::LLArray(): size(setSize()), index(0){
    LLLnode** path = new LLLnode*[size];

    for(int i = 0; i < size; i++){
        path[i] = new LLLnode;
    }

    curr = path[0];
}

LLArray::~LLArray(){
    removeAll();
    delete[] path;
}

//sets the size of the array (how many rooms)
int LLArray::setSize(){
    int random = rand() % 6;

    if(random < 3){
        random += 3;
    }

    return random;
}

//iterates through array and removes recursively
bool LLArray::removeAll(){
    bool isRemoved = false;

    for(int i = 0; i < size; i++){
        isRemoved = removeLLL(path[i]);
    }

    return isRemoved;
    
}

//removes linked list from desired slot in array
bool LLArray::removeLLL(LLLnode*& head){
    if(!head){
        return false;
    }
    
    removeLLL(head->getNext());

    head = nullptr;
    
    return true;
}

//adds a node to the end of curr index
void LLArray::addNode(){
    LLLnode* newNode = new LLLnode(curr);

    curr->setNext(newNode);

    curr->setNext(curr->getNext());
}

//displays sanity
void LLArray::displayCurrSanity(){
    curr->displayScareMeter();
}

//wrapper for display function
void LLArray::display(){
    for(int i = 0; i < size; i ++){
        display(path[i]);
        cout << endl;
    }
}

//displays how sanity changed throughout the list
void LLArray::display(LLLnode* head){
    if(!head){
        return;
    }

    cout << "\nFear Meter: ";
    head->display();
    cout << " -> ";

    display(head->getNext());
}


//checks if the user has inputted the correct move
bool LLArray::checkDirection(int move){
    bool isCorrect = curr->checkDirection(move);

    if(isCorrect){
        index++;// move forward in array

        if(index < size){
            curr = path[index];
        }

   }else{
        addNode();//create new room in linked list
    }

    return isCorrect;
}

//checks if the user has exited the maze
bool LLArray::checkIfFinished(){
    if(index > size){
        return true;
    }else{
        return false;
    }
}

//Increases sanity, outputs true if sanity <100
bool LLArray::increaseSanity(int scareLevel){
    bool isSane = true;
    isSane = curr->incMeter(scareLevel);

    return isSane;
}

//TreatHunt Functions

