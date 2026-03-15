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
    int mood;
    int energy;
    int health;
    int hunger;
    bool isAlive;

public:
    Pet();
    Pet(char*, const char*, const int);
    Pet(const Pet &obj);
    Pet& operator=(const Pet &obj);
    ~Pet();
};

int Pet::interactions=0;

 Pet::Pet() : birthday(2026), breed("N/A"), isAlive(true) {
     this -> name = strcpy(new char[4], "N/A");
     this -> mood=100;
     this -> energy=100;
     this -> health=100;
     this -> hunger=0;
 }

Pet::Pet(char* name, const char* breed, int birthday): breed(breed), birthday(birthday),isAlive(true){
    this -> name = strcpy(new char[strlen(name)+1],name);
     this -> mood=100;
     this -> energy=100;
     this -> health=100;
     this -> hunger=0;
 }

Pet::Pet(const Pet &obj): breed(obj.breed), birthday(obj.birthday), isAlive(obj.isAlive){
     this -> name = strcpy(new char[strlen(obj.name)+1], obj.name);
     this -> mood=100;
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

     this -> mood=obj.mood;
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

int main() {

 }
