#include <iostream>
#include <cstring>
#include <string>
#include<vector>
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
    void eat(std::string foodChoice);
    void sleep();
    void cuddle();
    void ShowStatus();
    int getHealth() const;
    void setHealth(int health);
    int getEnergy() const;
    void setEnergy(int energy);
    int getHappiness() const;
    void setHappiness(int happiness);
    const char* getName() const;

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

void Pet::eat(std::string foodChoice) {
     if (foodChoice=="Chicken" || foodChoice=="Turkey" || foodChoice=="Beef" || foodChoice=="Fish") {
         hunger-=30;
         health+=20;
         energy+=15;
     }
     else if (foodChoice=="Strawberry" || foodChoice=="Banana" || foodChoice=="Blueberry" || foodChoice=="Peach") {
         hunger-=15;
         health+=10;
         energy+=15;
     }
     else if (foodChoice=="Carrot" || foodChoice=="Tomato" || foodChoice=="Potato" || foodChoice=="Cucumber") {
         hunger-=25;
         health+=15;
         energy+=15;
     }
     else if (foodChoice=="Jerky" || foodChoice=="Biscuit" || foodChoice=="Dental_Chews" || foodChoice=="Cake") {
         hunger-=15;
         happiness+=15;
     }
     std::cout<<name<<" loved this "<<foodChoice<<"\n";
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
         health-=40;
     }
     if (energy<=10) {
         std::cout<<"WARNING: "<<name<<" is really tired"<<std::endl;
         health-=40;
     }
     if (happiness<=10) {
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
int Pet::getEnergy() const {
     return energy;
 }
void Pet::setEnergy(int energy) {
     this->energy=energy;
     CheckLimits();
 }

int Pet::getHappiness() const {
    return happiness;
}

void Pet::setHappiness(int happiness) {
    this->happiness=happiness;
     CheckLimits();
}

const char* Pet::getName() const{
    return name;
}
class Owner {
 private:
     std::string name;
     int age;
     double coins;
     Pet* myPet;
     std::vector<std::string> inventory;
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
     double getCoins() const;
     void setCoins(double coins);
    void addToInventory(const std::vector<std::string>& items);
     void ShowInventory() const;
     void removeFood(std::string item);

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
    delete myPet;
}

void Owner::putToSleep() {
    if (myPet!=nullptr) myPet->sleep();
}
void Owner::cuddleIt() {
    if (myPet!=nullptr) myPet->cuddle();

}
void Owner::giveMedicine() {
    if (myPet!=nullptr){
        if (myPet->getHealth()<50) {
            if (coins>=500) {
                coins-=500;
                myPet->setHealth(100);
                myPet->setEnergy(100);
                myPet->setHappiness(100);
                std::cout<<"Health, Energy and Happiness are back to 100%.\n";
            }
            else std::cout<<"not enough money!"<<std::endl;
        }
        else std::cout<<myPet->getName()<<" is heakthy enough, doesn't need medicine\n";
    }
}

double Owner::getCoins() const {
    return coins;
}
void Owner::setCoins(double coins) {
    this->coins=coins;
}

void Owner::addToInventory(const std::vector<std::string>& items) {
    inventory.insert(inventory.end(),items.begin(),items.end());
}

void Owner::ShowInventory() const {
    if (inventory.empty()) {
        std::cout<<"Inventory is empty\n";
        return;
    }
    for (int i=0; i<inventory.size();i++) {
        std::cout<<inventory[i]<<",  ";
    }
    std::cout<<"\n";
}

void Owner::feed() {
    if (myPet==nullptr)
        return;
    bool found=false;
    std::cout<<"Your items:\n";
    ShowInventory();
    std::cout<<"Write your choice\n";
    std::string foodChoice;
    std::cin>>foodChoice;
    for (int i=0;i<inventory.size();i++) {
        if (inventory[i]==foodChoice) {
            found=true;
            break;
        }

    }
    if (found) {
        removeFood(foodChoice);
        myPet->eat(foodChoice);
    }
    else std::cout<<"Choose a valid item\n";
}

void Owner::removeFood(std::string item) {
    for (int i=0;i<inventory.size();i++) {
        if (item==inventory[i]) {
            inventory.erase(inventory.begin()+i);
            break;
        }
    }
}

class Shop{
private:
    double income;
    const std::string vegetables;
    const std::string fruits;
    const std::string meat;
    const std::string treats;
    std::vector<std::string> shoppingCart;
    static const int meat_price=20;
    static const int fruits_price=13;
    static const int vegetables_price=15;
    static const int treats_price=25;
    void addToCart(std::string item,int price, double &totalPrice);
public:
    Shop();
    Shop(double);
    Shop(const Shop &obj);
    Shop& operator=(const Shop &obj);
    void goShopping(Owner& owner);
};
Shop::Shop():meat("Meat"), fruits("Fruits"), vegetables("Vegetables"), treats("Treats"){
    this->income=0.0;
}
Shop::Shop(double income):meat("Meat"), fruits("Fruits"),vegetables("Vegetables"), treats("Treats") {
    this->income=income;
}
Shop::Shop(const Shop &obj):meat("Meat"), fruits("Fruits"),vegetables("Vegetables"), treats("Treats"){
    this->income=obj.income;
}
Shop& Shop::operator=(const Shop &obj) {
    if (this==&obj) return *this;
    this->income=obj.income;
    return *this;
}

void Shop::goShopping(Owner& owner) {
    double price=0;
    int choice=-1;
    while (choice!=5) {
        std::cout<<"WELCOME! What do you eant to buy?\n";
        std::cout<<"1"<<meat<<"\n";
        std::cout<<"2"<<fruits<<"\n";
        std::cout<<"3"<<vegetables<<"\n";
        std::cout<<"4"<<treats<<"\n";
        std::cout<<"5 Abandon cart and exit\n";
        std::cout<<"6 Buy\n";
        std::cout<<"Select your action\n";
        std::cin>>choice;

        switch (choice) {
            case 1: {
                std::cout<<"Choose meat type\n";
                std::cout<<"1. Chicken   "<<"2. Beef   "<<"3. Fish   "<<"4. Turkey\n";
                int meatChoice;
                std::cin>>meatChoice;
                switch (meatChoice){
                    case 1: addToCart("Chicken",meat_price,price); break;
                    case 2: addToCart("Beef",meat_price,price); break;
                    case 3: addToCart("Fish",meat_price,price); break;
                    case 4: addToCart("Turkey",meat_price,price); break;
                    default: std::cout<<"Invalid choice\n"; break;
                }
                break;
            }
            case 2: {
                std::cout<<"Select fruit:\n";
                std::cout<<"1. Blueberry   "<<"2. Banana   "<<"3. Strawberry   "<<"4. Peach\n";
                int fruitChoice;
                std::cin>>fruitChoice;
                switch (fruitChoice){
                    case 1: addToCart("Blueberry",fruits_price,price); break;
                    case 2: addToCart("Banana",fruits_price,price); break;
                    case 3: addToCart("Strawberry",fruits_price,price); break;
                    case 4: addToCart("Peach",fruits_price,price); break;
                    default: std::cout<<"Invalid choice\n"; break;
                }
                break;
            }
            case 3:{
                std::cout<<"Choose your veggies\n";
                std::cout<<"1. Tomato   "<<"2. Cucumber   "<<"3. Carrot   "<<"4. Potato\n";
                int veggieChoice;
                std::cin>>veggieChoice;
                switch (veggieChoice){
                    case 1: addToCart("Tomato",vegetables_price,price); break;
                    case 2: addToCart("Cucumber",vegetables_price,price); break;
                    case 3: addToCart("Carrot",vegetables_price,price); break;
                    case 4: addToCart("Potato",vegetables_price,price); break;
                    default: std::cout<<"Invalid choice\n"; break;
                }
                break;
            }
            case 4: {
                std::cout<<"Buy some treats\n";
                std::cout<<"1. Biscuit   "<<"2. Dental_Chews   "<<"3. Jerky   "<<"4. Cake\n";
                int treatsChoice;
                std::cin>>treatsChoice;
                switch (treatsChoice){
                    case 1: addToCart("Biscuit",treats_price,price); break;
                    case 2: addToCart("Dental_Chews",treats_price,price); break;
                    case 3: addToCart("Jerky",treats_price,price); break;
                    case 4: addToCart("Cake",treats_price,price); break;
                    default: std::cout<<"Invalid choice\n"; break;
                }
                break;
            }
            case 5: {
                std::cout<<"Exiting shop..\n";
                shoppingCart.clear();
                price=0;
                break;
            }
            case 6: {
                if(owner.getCoins()<price)
                    std::cout<<"Not enough money\n";
                else {
                    this->income+=price;
                    owner.setCoins(owner.getCoins()-price);
                    owner.addToInventory(shoppingCart);
                    std::cout<<"Thank you! Remaining:"<<owner.getCoins()<<"\n";
                    price=0;
                    shoppingCart.clear();
                    choice=-1;
                }
                break;
            }
            default: {
                std::cout<<"Invalid choice\n";
                break;
            }
        }
    }
}

void Shop::addToCart(std::string item, int price,double &totalPrice) {
    shoppingCart.push_back(item);
    totalPrice+=price;
}

int main() {
}