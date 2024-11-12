#pragma once
#include "myutil.h"

//base class for all attendees
class Attendee{
    public:
        Attendee();
        ~Attendee();
        Attendee(char* copyName,int copyAge);
        Attendee(const Attendee&);
        Attendee& operator=(const Attendee&);

    protected:
        char* name;
        int age;

};

//class for all kids, will handle candy count and maze
class Kid: public Attendee{
    private:
        int candyCount;

    public:
        Kid();
        Kid(char* copyName, int copyAge, int copyCount);


        void collectCandy();
        void displayCandyCount() const;
};

//class for all adults, will handle scare meter and haunted house
class Adult: public Attendee{
    private:
        int sanity;
        char* worstFear;

    public:
        Adult();
        Adult(char* name, int age);
        ~Adult();
        Adult(const Adult&);
        Adult& operator=(const Adult&);

        bool incMeter(int fearAdded);
        void displayScareMeter() const;
};


//class for all dogs, will handle 
class Dog: public Attendee{
    private:
        int treatCount;

    public:
        Dog();
        Dog(char* name, int age);


        bool smellTreat(int treatDir);
        void collectTreat();
        void displayTreatCount() const;
        bool moveThrough(int move);
};
