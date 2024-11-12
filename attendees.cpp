//Name: Jad Saad
//Purpose: This fiel holds all attendee functions
//Takes care of each scenario whether they are a
//kid, adult or dog
#include "attendees.h"

//Attendees Functions
Attendee::Attendee():name(nullptr), age(0){}
 
Attendee::Attendee(char* copyName, int copyAge):age(copyAge){
     if(copyName == nullptr){
         name = nullptr;
          return;
     }
 
     name = new char[strlen(copyName) + 1];
    strcpy(name, copyName);
}
 
Attendee::~Attendee(){
     if(name != nullptr){
          delete[] name;
         name = nullptr;
    }
}
 
Attendee::Attendee(const Attendee& toCopy)
         : name(nullptr), age(toCopy.age) { // Initialize name to nullptr
 
     if(toCopy.name != nullptr) {
         this->name = new char[strlen(toCopy.name) + 1];
         strcpy(this->name, toCopy.name);
     }
 }
  
Attendee& Attendee::operator=(const Attendee& toCopy) {
      if (this == &toCopy) {
          return *this; // Self-assignment check
      }
  
      delete[] name;
  
     age = toCopy.age;
  
     if (toCopy.name == nullptr) {
          name = nullptr;
     } else {
          name = new char[strlen(toCopy.name) + 1];
          strcpy(name, toCopy.name);
     }
 
     return *this; // Return the current object to allow chaining
}


//Adult Functions


Adult::Adult():Attendee(), sanity(0), worstFear(nullptr){}

Adult::Adult(char* name, int age):Attendee(name, age), sanity(0), worstFear(nullptr){}
    
Adult::Adult(const Adult& toCopy)
        : Attendee(toCopy), sanity(toCopy.sanity), worstFear(nullptr) { // Initialize worstFear to nullptr
        if (toCopy.worstFear != nullptr) {
            this->worstFear = new char[strlen(toCopy.worstFear) + 1];
            strcpy(this->worstFear, toCopy.worstFear);
        }
   
   }

Adult::~Adult(){
    if(worstFear != nullptr){
        delete[] worstFear;
        worstFear = nullptr;
    }
}

Adult& Adult::operator=(const Adult& toCopy){
    Attendee::operator=(toCopy);

    if(this != &toCopy){
        if(this->worstFear != nullptr){
            delete[] worstFear;
        }

        if(toCopy.worstFear == nullptr){
            this->worstFear = nullptr;
        }else{
            this->worstFear = new char[strlen(toCopy.worstFear) + 1];
            strcpy(this->worstFear, toCopy.worstFear);
        }

        this->sanity = toCopy.sanity;
    }

    return *this;
}


void Adult::displayScareMeter() const{
    cout << sanity << endl;
}

bool Adult::incMeter(int fearAdded){
    sanity += fearAdded;

    if(sanity >= 100){
        return true;
    }

    return false;
}

//Kid Functions
Kid::Kid():Attendee(), candyCount(0){}

Kid::Kid(char* copyName,int copyAge, int copyCount):Attendee(copyName, copyAge), candyCount(copyCount){}

void Kid::collectCandy(){
    candyCount++;
}

void Kid::displayCandyCount() const{
    cout << candyCount;
}

//Dog Functions
Dog::Dog():Attendee(), treatCount(0){}

Dog::Dog(char* name, int age): Attendee(name , age), treatCount(0){}

void Dog::collectTreat(){
    treatCount++;
}

void Dog::displayTreatCount() const{
    cout << treatCount << endl;
}

bool Dog::smellTreat(int treatDir){
    bool treat = true;

       switch(treatDir){
          case 0:
            cout << "\nI smell a treat... LEFT!\n";
            break;
          case 1:
            cout << "\nI smell a treat... RIGHT!\n";
            break;
          case 2:
            cout << "\nI smell a treat... FORWARD!\n";
            break;
          default:
            cout << "\nNo treats here :(\n";
            treat = false;
            break;
       };

    return treat;
}

