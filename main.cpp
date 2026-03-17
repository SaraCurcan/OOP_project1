#include <iostream>
#include <cstring>
#include <string>
class Pet{
private:
    char* name;
    const std::string breed;
    float age;
    const std::string type;
    static int interactions;
    int happiness;
    int energy;
    int health;
    int hunger;
    bool isAlive;

    void CheckDeath();
    void CheckLimits();
    void ShowWarnings();

public:
    Pet();
    Pet(char*,std::string,float,std::string);
    Pet(const Pet &obj);
    Pet& operator=(const Pet &obj);
    ~Pet();
    void eat();
    void sleep();
    void cuddle();
    void ShowStatus();
    int getHealth() const;
    void setHealth(int health);
};

int Pet::interactions=0;

 Pet::Pet() :breed("N/A"),type("N/A") {
     this->name = strcpy(new char[4], "N/A");
     isAlive=true;
     age=0.0;
     happiness=100;
     energy=100;
     health=100;
     hunger=0;
 }

Pet::Pet(char* name, std::string breed, float age, std::string type): breed(breed), type(type){
    this -> name = strcpy(new char[strlen(name)+1],name);
     isAlive=true;
     this->age=age;
     happiness=100;
     energy=100;
     health=100;
     hunger=0;
 }

Pet::Pet(const Pet &obj): breed(obj.breed), type(obj.type){
     this -> name = strcpy(new char[strlen(obj.name)+1], obj.name);
     this->isAlive=obj.isAlive;
     this->age=obj.age;
     happiness=100;
     health=100;
     energy =100;
     hunger=0;
 }

Pet& Pet::operator=(const Pet &obj){
     if (this==&obj) {
         return *this;
     }
     delete[] this -> name;
     this -> name=new char[strlen(obj.name)+1];
     strcpy(this ->name,obj.name);

     this->isAlive=obj.isAlive;
     this->age=obj.age;
     happiness=obj.happiness;
     health=obj.health;
     energy=obj.energy;
     hunger=obj.hunger;

     return *this;
 }

Pet::~Pet() {
     if (name!=nullptr) {
         delete[] name;
         name=nullptr;
     }
 }

void Pet::eat() {
     hunger-=25;
     health+=10;
     energy+=15;
     happiness+=7;
     std::cout<<name<<" has just eaten.  [ HG:-25 , HP:+10 , STAM:+15 , HAPPY:+7 ]\n";
     CheckLimits();
     ShowWarnings();
     CheckDeath();
 }

void Pet::sleep() {
     energy+=25;
     health+=10;
     hunger+=5;
     std::cout<<name<<" is awake now. [ HG:+5 EN:+25 , HP:+10\n";
     CheckLimits();
     ShowWarnings();
     CheckDeath();
 }

void Pet::cuddle() {
    happiness+=20;
    energy-=5;
     std::cout<<"You spent some quality time with "<<name<<"."<<"  [ HAPPY:+20 , EN:-5 ] \n";
     CheckLimits();
     ShowWarnings();
     CheckDeath();
 }

void Pet::CheckDeath() {
    if (health<=0) {
        isAlive=false;
        std::cout<<"I'm sorry, but "<<name<<" is no longer alive. \n";
    }
}

void Pet::CheckLimits() {
     if (happiness>100)
         happiness=100;
     else if (happiness<0)
         happiness=0;

     if (health>100)
         health=100;
     else if (health<0)
         health=0;

     if (energy>100)
         energy=100;
     else if (energy<0)
         energy=0;

     if (hunger>100)
         hunger=100;
     else if (hunger<0)
         hunger=0;
 }

void Pet::ShowWarnings() {
    if (health<=20)
        std::cout<<"WARNING: "<<name<<"'s health is not good"<<std::endl;
     if (hunger>=75) {
         std::cout<<"WARNING: "<<name<<" is starving! Feed it soon."<<std::endl;
         health-=35;
     }
     if (energy<=10) {
         std::cout<<"WARNING: "<<name<<" is really tired"<<std::endl;
         health-=25;
     }
     if (happiness<=20) {
         std::cout<<"WARNING: "<<name<<" is sad. Cuddle or play with him"<<std::endl;
         health-=10;
     }
}

void Pet::ShowStatus() {
     std::cout<<"PET STATUS: "<<name<<std::endl;
     std::cout<<" --------------------"<<std::endl;
     std::cout<<"|  Health  :  "<<health<<"/100 "<<std::endl;
     std::cout<<"|  Hunger  :  "<<hunger<<"/100 "<<std::endl;
     std::cout<<"|  Energy  :  "<<energy<<"/100 "<<std::endl;
     std::cout<<"|  Happy   :  "<<happiness<<"/100 "<<std::endl;
     std::cout<<" --------------------"<<std::endl;
 }

int Pet::getHealth() const {
     return health;
 }
void Pet::setHealth(int health) {
     this->health=health;
     CheckLimits();
 }
class Owner {
 private:
     std::string name;
     int age;
     double coins;
     Pet* myPet;
 public:
     Owner();
     Owner(std::string, int, double,Pet*);
     Owner(const Owner &obj);
     Owner& operator=(const Owner &obj);
     ~Owner();
     void feed();
     void putToSleep();
     void cuddleIt();
     void giveMedicine();

 };

Owner::Owner() {
    this->name="N/A";
    this->age=0;
    this->coins=100.0;
    this->myPet=nullptr;
}

Owner::Owner(std::string name, int age, double coins,Pet* myPet) {
    this->name=name;
    this->age=age;
    this->coins=coins;
    this->myPet=myPet;
}

Owner::Owner(const Owner &obj) {
    this->name=obj.name;
    this->age=obj.age;
    this->coins=obj.coins;
    this->myPet=obj.myPet;
}

Owner& Owner::operator=(const Owner &obj) {
    if (this==&obj) return *this;
    this->name=obj.name;
    this->age=obj.age;
    this->coins=obj.coins;
    this->myPet=obj.myPet;
    return *this;
}

Owner::~Owner() {

}

void Owner::putToSleep() {
    if (myPet!=nullptr) myPet->sleep();
}
void Owner::cuddleIt() {
    if (myPet!=nullptr) myPet->cuddle();

}
void Owner::giveMedicine() {
    if (myPet!=nullptr){
        if (coins>=100.0) {
            coins-=100.0;
            myPet->setHealth(100);
            std::cout<<name<<" is feeling better now."<<std::endl;
        }
        else std::cout<<"not enough money!"<<std::endl;
    }
}
int main() {
    
 }