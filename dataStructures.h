#pragma once
#include "myutil.h"
#include "attendees.h"


class LLLnode: public Adult{
    private:
        LLLnode* next;
        int correctChoice;
        
        int setCorrectChoice();

    public:
        LLLnode();
        LLLnode(const LLLnode* toCopy);
        ~LLLnode();

        LLLnode*& getNext();
        void setNext(LLLnode* newNext);
        void display();
        bool checkDirection(int move);
};

class CLLnode: public Kid{
    private:
        int index;
        CLLnode* next;
        int correctChoice;
       
        int setCorrectChoice();

    public:
        CLLnode();
        CLLnode(char*, int);
        ~CLLnode();

        CLLnode*& getNext();
        void setNext(CLLnode* newNext);
        bool checkDirection(int move);
        void display();
};

class CLL{
    private:
        CLLnode* rear;
        CLLnode* curr;

        bool removeAll();
        bool remove(CLLnode* toRemove, CLLnode* curr);
        void add(CLLnode* curr);
        void display(CLLnode* curr);

    public:
        CLL();
        ~CLL();
        CLL(const CLL&);
        CLL& operator=(const CLL&);

        void add();
        void display();
        bool moveThrough(int move);
        void getCandy();
        
};

class LLArray{
    private:
        LLLnode** path;
        LLLnode* curr;
        int size;
        int index;
        
        bool removeAll();
        int setSize(); 
        bool removeLLL(LLLnode*& head);
        void addNode(LLLnode*& curr);
        void display(LLLnode* head);

    public:
        LLArray();
        LLArray(LLLnode** path);
        ~LLArray();
        LLArray(const LLArray&);
        LLArray& operator=(const LLArray&);
        
        void addNode();
        void display();
        bool checkDirection(int move);
        bool checkIfFinished();
        bool increaseSanity(int scareLevel);
        void displayCurrSanity();
};


