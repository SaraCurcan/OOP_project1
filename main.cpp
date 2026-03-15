#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
class Pet{
private:
    char* name;
    const char* breed;
    const int birthday;
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
    Pet(char*, const char*, const int);
    Pet(const Pet &obj);
    Pet& operator=(const Pet &obj);
    ~Pet();
    void eat();
    void sleep();
    void cuddle();
};

int Pet::interactions=0;

 Pet::Pet() : birthday(2026), breed("N/A"), isAlive(true) {
     this -> name = strcpy(new char[4], "N/A");
     this -> happiness=100;
     this -> energy=100;
     this -> health=100;
     this -> hunger=0;
 }

Pet::Pet(char* name, const char* breed, int birthday): breed(breed), birthday(birthday),isAlive(true){
    this -> name = strcpy(new char[strlen(name)+1],name);
     this -> happiness=100;
     this -> energy=100;
     this -> health=100;
     this -> hunger=0;
 }

Pet::Pet(const Pet &obj): breed(obj.breed), birthday(obj.birthday), isAlive(obj.isAlive){
     this -> name = strcpy(new char[strlen(obj.name)+1], obj.name);
     this -> happiness=100;
     this -> health=100;
     this -> energy =100;
     this -> hunger=0;
 }

Pet& Pet::operator=(const Pet &obj){
     if (this==&obj) {
         return *this;
     }
     delete[] this -> name;
     this -> name=new char[strlen(obj.name)+1];
     strcpy(this ->name,obj.name);

     this -> happiness=obj.happiness;
     this -> health=obj.health;
     this -> energy=obj.energy;
     this -> hunger=obj.hunger;

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
     std::cout<<name<<" has just eaten.  [ HG:-25 , HP:+10 , STAM:+15 , HAPPY:+7 ]";
     CheckLimits();
     CheckDeath();
     ShowWarnings();
 }

void Pet::sleep() {
     energy+=25;
     health+=10;
     hunger+=5;
     std::cout<<name<<" is awake now. [ HG:+5 EN:+25 , HP:+10";
     CheckLimits();
     CheckDeath();
     ShowWarnings();
 }

void Pet::cuddle() {
    happiness+=20;
    energy-=5;
     std::cout<<"You spent some quality time with "<<name<<"."<<"  [ HAPPY:+20 , EN:-5 ]";
     CheckLimits();
     CheckDeath();
     ShowWarnings();
 }

void Pet::CheckDeath() {
    if (health<=0) {
        isAlive=false;
        std::cout<<"I'm sorry, but "<<name<<" is no longer alive.";
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
     if (hunger>=75)
         std::cout<<"WARNING: "<<name<<" is starving! Feed it soon."<<std::endl;
     if (energy<=20)
         std::cout<<"WARNING: "<<name<<" is really tired"<<std::endl;
     if (happiness<=20)
         std::cout<<"WARNING: "<<name<<" is sad. Cuddle or play with him"<<std::endl;
}



int main() {

 }