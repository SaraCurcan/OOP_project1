
#include <iostream>
#include <cstring>
#include <string>
#include<vector>
#include<ctime>
#include<cstdlib>
class Pet{
private:
    char* name;
    const std::string breed;
    float* age;
    char gender;
    int happiness;
    int energy;
    int health;
    int hunger;
    bool isAlive;
    const int id;
    static int noInstance;

    bool CheckDeath();
    void CheckLimits();
    void ShowWarnings();

public:
    Pet();
    Pet(char*,std::string,float*,char);
    Pet(const Pet &obj);
    Pet& operator=(const Pet &obj);
    ~Pet();
    void eat(std::string foodChoice);
    void sleep();
    void cuddle();
    int getHealth() const{return health;}
    void setHealth(int health);
    int getEnergy() const {return energy;}
    void setEnergy(int energy);
    int getHappiness() const{return happiness;}
    void setHappiness(int happiness);
    const char* getName() const{return name;}
    void setName(char* NewName);
    int getHunger() const{return hunger;}
    void setHunger(int hunger);
    static int getnoInstance(){return noInstance;}
    int getId() const{return id;}
    bool getisAlive() const {return isAlive;}
    friend std::ostream& operator<<(std::ostream&, const Pet& obj);
    friend std::istream& operator>>(std::istream&, Pet& obj);
};
int Pet::noInstance=0;
 Pet::Pet() :breed("N/A"), id(++noInstance) {
     this->name = strcpy(new char[4], "N/A");
     isAlive=true;
     this->age=new float(0.0);
     this->gender='X';
     happiness=100;
     energy=100;
     health=100;
     hunger=0;
 }

Pet::Pet(char* name, std::string breed, float* age,char gender): breed(breed), id(++noInstance){
    this -> name = strcpy(new char[strlen(name)+1],name);
     isAlive=true;
     this->age=new float(*age);
     this->gender=gender;
     this->happiness=100;
     this->energy=100;
     this->health=100;
     this->hunger=0;
 }

Pet::Pet(const Pet &obj): breed(obj.breed), id(++noInstance){
     this -> name = strcpy(new char[strlen(obj.name)+1], obj.name);
     this->isAlive=obj.isAlive;
     this->age= new float(*(obj.age));
     this->gender=obj.gender;
     happiness=obj.happiness;
     health=obj.health;
     energy=obj.energy;
     hunger=obj.hunger;
 }

Pet& Pet::operator=(const Pet &obj){
     if (this==&obj) {
         return *this;
     }
     delete[] this -> name;
     this -> name=new char[strlen(obj.name)+1];
     strcpy(this ->name,obj.name);
     delete age;
     this ->age=new float(*(obj.age));
     this->gender=obj.gender;
     this->isAlive=obj.isAlive;
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
     if (age!=nullptr) {
         delete age;
         age=nullptr;
     }
 }
//Pet functions
void Pet::eat(std::string foodChoice) {
     if (foodChoice=="Chicken" || foodChoice=="Turkey" || foodChoice=="Beef" || foodChoice=="Fish") {
         setEnergy(energy+20);
         setHealth(health+20);
         setHunger(hunger-30);
     }
     else if (foodChoice=="Strawberry" || foodChoice=="Banana" || foodChoice=="Blueberry" || foodChoice=="Peach") {
         setEnergy(energy+18);
         setHealth(health+10);
         setHunger(hunger-20);
     }
     else if (foodChoice=="Carrot" || foodChoice=="Tomato" || foodChoice=="Potato" || foodChoice=="Cucumber") {
         setEnergy(energy-25);
         setHealth(health+15);
         setHunger(hunger-25);
     }
     else if (foodChoice=="Jerky" || foodChoice=="Biscuit" || foodChoice=="Dental_Chews" || foodChoice=="Cake") {
         setHappiness(happiness+15);
         setHunger(hunger-15);
     }
     std::cout<<name<<" loved this "<<foodChoice<<"\n";
     CheckLimits();
     ShowWarnings();
     CheckDeath();
 }

void Pet::sleep() {
     setEnergy(energy+25);
     setHealth(health+10);
     setHunger(hunger+5);
     (*age)+=0.1;
     std::cout<<name<<" is awake now";
     CheckLimits();
     ShowWarnings();
     CheckDeath();
 }

void Pet::cuddle() {
     setHappiness(happiness+20);
     setEnergy(energy-5);
     std::cout<<"You spent some quality time with \n"<<name;
     CheckLimits();
     ShowWarnings();
     CheckDeath();
 }

bool Pet::CheckDeath() {
    if (health<=0) {
        isAlive=false;
        std::cout<<name<<" IS DEAD [HP : 0].\n";
        return false;
    }
     return true;
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
     }
     if (energy<=10) {
         std::cout<<"WARNING: "<<name<<" is really tired"<<std::endl;
     }
     if (happiness<=10) {
         std::cout<<"WARNING: "<<name<<" is sad. Cuddle or play with him"<<std::endl;
     }
}
//setters
void Pet::setHealth(int health) {
     this->health=health;
     CheckLimits();
     CheckDeath();
 }
void Pet::setEnergy(int energy) {
     this->energy=energy;
     if (this->energy<=10 )
         this->health-=30;
     CheckLimits();
 }
void Pet::setHappiness(int happiness) {
     this->happiness=happiness;
     if (this->happiness<=10)
         this->health-=10;
     CheckLimits();
}
void Pet::setHunger(int hunger) {
     this->hunger=hunger;
     if (this->hunger>=80)
         this->health-=25;
     CheckLimits();
 }


void Pet::setName(char *NewName) {
    if (this->name!=nullptr)
        delete[] this->name;
    this->name=new char[strlen(NewName)+1];
     strcpy(this->name, NewName);
}
std::ostream& operator<<(std::ostream& os, const Pet& obj) {
     os<<std::endl;
     os<<"======================================================\n";
     os<<"|PET STATUS: "<<obj.name<<" , "<<obj.gender<<" , "<<*obj.age<<" years \n";
     os<<"|HP: "<<obj.health<<"/100 "<<"| EN: "<<obj.energy<<"/100 "<<"| HG:"<<obj.hunger<<"/100 "<<"| HAPPY: "<<obj.happiness<<"/100\n";
     os<<"======================================================\n";
     return os;
 }

std::istream& operator>>(std::istream& is, Pet& obj) {
     char name[50];
     std::cout<<"Pet name (max 25 characters): ";
     is>>name;
     if (obj.name!=nullptr) delete[] obj.name;
     obj.name=new char[strlen(name)+1];
     strcpy(obj.name,name);
     return is;
 }
class Owner {
 private:
     std::string name;
     double coins;
     Pet* myPet;
     std::string* inventory;
     int noItems;
     int size;
     const int id;
     static int noInstance;
     void removeFood(std::string item);
 public:
     Owner();
     Owner(std::string, double,Pet*,std::string*,int,int);
     Owner(const Owner &obj);
     Owner& operator=(const Owner &obj);
     ~Owner();
     void feed();
     void putToSleep();
     void cuddleIt();
     void giveMedicine();
     double getCoins() const {return coins;}
     void setCoins(double coins);
    void addToInventory(const std::vector<std::string>& items);
     void ShowInventory() const;
     static int getnoInstance(){return noInstance;}
     int getId() const{return id;}
     const std::string getName() const {return name;}
     void setName(std::string name);
    Pet* getPet() const {return this->myPet;}
     void setPet(Pet* pet);
     friend std::ostream& operator<<(std::ostream&, const Owner& obj);
     friend std::istream& operator>>(std::istream&, Owner& obj);
 };

int Owner::noInstance=0;

Owner::Owner(): id(++noInstance) {
    this->name="N/A";
    this->coins=100.0;
    this->myPet=nullptr;
    this->noItems=0;
    this->size=4;
    this->inventory=new std::string[this->size];
}

Owner::Owner(std::string name,double coins,Pet* myPet,std::string* inventory,int noItems,int size): id(++noInstance) {
    this->name=name;
    this->coins=coins;
    if (myPet!=nullptr) {
        this->myPet=new Pet(*myPet);
    }
    else this->myPet=nullptr;
    this->noItems=noItems;
    this->size=size;
    this->inventory=new std::string[this->size];
    for (int i=0;i<noItems;i++)
        this->inventory[i]=inventory[i];
}

Owner::Owner(const Owner &obj):id(++noInstance) {
    this->name=obj.name;
    this->coins=obj.coins;
    this->noItems=obj.noItems;
    this->size=obj.size;
    if (obj.myPet!=nullptr) {
        this->myPet=new Pet(*(obj.myPet));
    }
    else this->myPet=nullptr;
   if (obj.inventory!=nullptr) {
       this->inventory=new std::string[this->size];
       for (int i=0;i<noItems;i++) {
           this->inventory[i]=obj.inventory[i];
       }
   }
    else this->inventory=nullptr;
}

Owner& Owner::operator=(const Owner &obj) {
    if (this==&obj) return *this;
    delete this->myPet;
    delete[] this->inventory;
    this->name=obj.name;
    this->coins=obj.coins;
    this->noItems=obj.noItems;
    this->size=obj.size;
    if (obj.myPet!=nullptr) {
        this->myPet=new Pet(*(obj.myPet));
    }
    else this->myPet=nullptr;
    if (obj.inventory!=nullptr) {
        this->inventory=new std::string[this->size];
        for (int i=0;i<noItems;i++) {
            this->inventory[i]=obj.inventory[i];
        }
    }
    return *this;
}

Owner::~Owner() {
    delete myPet;
    delete[] inventory;
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
            if (coins>=1000) {
                coins-=1000;
                myPet->setHealth(100);
                myPet->setEnergy(100);
                myPet->setHappiness(100);
                std::cout<<"Health, Energy and Happiness are back to 100%.\n";
            }
            else std::cout<<"not enough money!"<<std::endl;
        }
        else std::cout<<myPet->getName()<<" is healthy enough, doesn't need medicine\n";
    }
}
void Owner::setCoins(double coins) {
    this->coins=coins;
}
//Owner functions
void Owner::addToInventory(const std::vector<std::string>& items) {
    for (int i=0;i<items.size();i++) {
        if (noItems>=size) {
            int doubleSize;
            if (size==0)
                doubleSize=4;
            else
                doubleSize=size*2;
            std::string* copyInventory=new std::string[doubleSize];
            for (int j=0;j<noItems;j++)
                copyInventory[j]=inventory[j];
            delete[] inventory;
            inventory=copyInventory;
            size=doubleSize;
        }
        inventory[noItems]=items[i];
        noItems++;
    }
}

void Owner::ShowInventory() const {
    std::cout<<"===================\n";
    if (noItems==0) {
        std::cout<<"Inventory is empty\n";
        return;
    }
   for(int i=0;i<noItems;i++) {
       std::cout<<"| "<<inventory[i]<<"\n";
   }
    std::cout<<"|------------------\n";
}

void Owner::feed() {
    if (myPet==nullptr)
        return;
    bool found=false;
    std::cout<<"Your items:\n";
    ShowInventory();
    std::cout<<"Write your choice\n";
    std::string foodChoice;
    int foodIndex=0;
    std::string actualItem;
    std::cin>>foodChoice;
    for (int i=0;i<foodChoice.length();i++) {
        foodChoice[i]=std::tolower(foodChoice[i]);
    }
    for (int i=0;i<noItems;i++) {
        std::string smallItem=inventory[i];
        for (int j=0;j<smallItem.length();j++)
            smallItem[j]=std::tolower(smallItem[j]);
        if (smallItem==foodChoice) {
            found=true;
            foodIndex=i;
            break;
        }
    }
    if (found) {
        std::string food=inventory[foodIndex];
        myPet->eat(food);
        removeFood(food);
    }
    else std::cout<<"Invalid item";
}

void Owner::removeFood(std::string item) {
    int foodIndex=-1;
    for (int i=0;i<noItems;i++) {
        if (item==inventory[i]) {
            foodIndex=i;
            break;
        }
    }
    if (foodIndex!=-1) {
        for (int i=foodIndex;i<noItems-1;i++) {
            inventory[i]=inventory[i+1];
        }
        noItems--;
    }
}

void Owner::setName(std::string name) {
    this->name=name;
}
void Owner::setPet(Pet* newPet) {
    if (this->myPet!=nullptr) delete this->myPet;
    if (newPet!=nullptr) this->myPet= new Pet(*newPet);
    else this->myPet=nullptr;
}
std::ostream& operator<<(std::ostream& os, const Owner& obj) {
    os<<"==========================================\n";
    os<<"[ OWNER PROFILE ]\n";
    os<<"NAME: "<<obj.name<<" | ID: "<<obj.id<<"\n";
    os<<"COINS: "<<obj.coins<<" | NUMBER OF ITEMS: "<<obj.noItems<<"\n";
    if (obj.myPet!=nullptr) {
        os<<"PET: "<<obj.myPet->getName()<<"\n";
    }
    os<<"==========================================\n";
    return os;
}
std::istream& operator>>(std::istream& is, Owner& obj) {
    std::string name;
    std::cout<<"New name: ";
    is>>name;
    obj.setName(name);
    return is;
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
    const int id;
    static int noInstance;
public:
    Shop();
    Shop(double);
    Shop(const Shop &obj);
    Shop& operator=(const Shop &obj);
    ~Shop();
    void goShopping(Owner& owner);
    friend std::ostream& operator<<(std::ostream& , const Shop& obj);
    friend std::istream& operator>>(std::istream&, Shop& obj);
};
int Shop::noInstance=0;
Shop::Shop():meat("Meat"), fruits("Fruits"), vegetables("Vegetables"), treats("Treats"), id(++noInstance){
    this->income=0.0;
}
Shop::Shop(double income):meat("Meat"), fruits("Fruits"),vegetables("Vegetables"), treats("Treats"), id(++noInstance) {
    this->income=income;
}
Shop::Shop(const Shop &obj):meat("Meat"), fruits("Fruits"),vegetables("Vegetables"), treats("Treats"), id(++noInstance){
    this->income=obj.income;
}
Shop& Shop::operator=(const Shop &obj) {
    if (this==&obj) return *this;
    this->income=obj.income;
    return *this;
}
Shop::~Shop() {

}
void Shop::goShopping(Owner& owner) {
    double price=0;
    int choice=-1;
    std::cout<<*this;
    while (choice!=5) {
        std::cout<<"WELCOME! What do you eant to buy?\n";
        std::cout<<"1. "<<meat<<"\n";
        std::cout<<"2. "<<fruits<<"\n";
        std::cout<<"3. "<<vegetables<<"\n";
        std::cout<<"4. "<<treats<<"\n";
        std::cout<<"5. Back to menu\n";
        std::cout<<"6. Buy\n";
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

struct questionsArray {
    std::string question;
    std::string answer;
};

std::ostream& operator<<(std::ostream& os, const Shop& obj) {
    os<<"==========================================================================\n";
    os<<"STORE ID: "<<obj.id<<"\n";
    os<<"TOTAL INCOME "<<obj.income<<" coins\n";
    os<<"PRICES: Meat: "<<Shop::meat_price<<" coins | Fruit: "<<Shop::fruits_price<<" coins | Vegetables: "<<Shop::vegetables_price<<" coins | Treats: "<<Shop::treats_price<<" coims\n";
    os<<"==========================================================================\n";
    return os;
}

std::istream& operator>>(std::istream& is, Shop& obj) {
    std::cout<<"Enter shop income: \n";
    is>>obj.income;
    if (obj.income<0) {
        std::cout<<"Income must be positive\n";
        obj.income=0;
    }
    return is;
}
class Games{
private:
    double reward;
    static long Highscore;
    int energyCost;
    std::vector<questionsArray> questions;
    const int id;
    static int noInstance;

public:
    Games();
    Games(double, int,std::vector<questionsArray>);
    Games(const Games &obj);
    Games& operator=(const Games &obj);
    ~Games();
    bool CheckEnergy(Pet&);
    void selectQuestions();
    void GuessTheNumber(Owner&, Pet&);
    void playTrivia(Owner&, Pet&);
    friend std::ostream& operator<<(std::ostream&, const Games& obj);
    friend std::istream& operator>>(std::istream&, Games& obj);
};
 int Games::noInstance=0;
Games::Games():id(++noInstance) {
    this->reward=0.0;
    this->energyCost=0;
    this->questions={};
}
Games::Games(double reward, int energyCost,std::vector<questionsArray> questions): id(++noInstance) {
    this->reward=reward;
    this->energyCost=energyCost;
    this->questions=questions;
}
Games::Games(const Games &obj): id(++noInstance) {
    this->reward=obj.reward;
    this->energyCost=obj.energyCost;
    this->questions=obj.questions;
}
Games& Games::operator=(const Games &obj) {
    if(this==&obj) return *this;
    this->reward=obj.reward;
    this->energyCost=obj.energyCost;
    this->questions=obj.questions;
    return *this;
}
Games::~Games() {

}
long Games::Highscore=0;

bool Games::CheckEnergy(Pet& myPet) {
    if (myPet.getEnergy()<this->energyCost) {
        std::cout<<myPet.getName()<<" is too tired"<<"(Energy < "<<energyCost<<" )\n";
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Games& obj) {
    os<<"=========================================\n";
    os<<"[ GAMES CENTER ]\n";
    os<<"CURRENT HIGHSCORE "<<Games::Highscore<<" coins\n";
    os<<"ENERGY REQUIRED TO PLAY "<<obj.energyCost<<"\n";
    os<<"=========================================\n";
    return os;
}
std::istream& operator>>(std::istream& is,Games& obj) {
    return is;
}

void Games::selectQuestions() {
    questions={
        {"How many eyerbows does Mona Lisa have?", "0"},
        {"What is the national animal of India?", "bengal tiger"},
        {"What color is a polar bear skin?", "black"},
        {"What does Hakuna matata means?", "no worries"},
        {"How many layers of skin does a cameleon have?","4"},
        {"Where did christmas originate?", "rome"},
        {"What year was the first Grammy Awards held?","1959"},
        {"What is the capital of Australia?","canberra"},
        {"Which ancient civilization is credited with creating the first known writing system?","sumerians"},
        {"Which Greek philosopher is known for his method of questioning as a form of teaching?", "socrates"},
        {"What is the only U.S state that does not have a sales tax?","alaska"},

    };
}

void Games::playTrivia(Owner& owner, Pet& myPet) {
    if (!CheckEnergy(myPet)) return;
    std::cout<<"game id "<< this->id<<"\n";
    std::cout<<"Welcome to trivia!\n";
    std::cout<<"Press 1 to start the game or 0 to exit\n";
    int choice=-1;
    std::cin>>choice;
    while (choice!=0 and choice==1) {
        myPet.setEnergy(myPet.getEnergy()-this->energyCost);
        myPet.setHappiness(myPet.getHappiness()+this->energyCost/2);
        myPet.setHunger(myPet.getHunger()+this->energyCost*2);
        int score=0;
        for (int i=0;i<3;i++) {
            int randomIndex=rand() % questions.size();
            std::cout<<i+1<<". "<<questions[randomIndex].question<<"\n";
            std::cout<<"Write your answer:\n";
            std::string userAnswer;
            std::cin>>userAnswer;
            for (int c=0;c<userAnswer.length();c++) {
                userAnswer[c]=std::tolower(userAnswer[c]);
            }
            if (userAnswer==questions[randomIndex].answer) {
                score++;
                std::cout<<"Correct!\n";
            }
            else std::cout<<"Wrong!\n";
        }
        double gameReward=0;
        gameReward=score*this->reward;
        owner.setCoins(owner.getCoins() + gameReward);
        if (gameReward>0) std::cout<<"You won "<<gameReward<<" coins\n";
        else std::cout<<"Your score is 0. Better luck next time!\n";
        if (gameReward>Highscore) {
            Highscore=gameReward;
        }
        if (!CheckEnergy(myPet)) break;
        std::cout<<"Press 1 to play again or 0 to exit\n";
        std::cin>>choice;
    }
    std::cout<<"Exiting trivia\n";
}

void Games::GuessTheNumber(Owner& owner, Pet& myPet) {
    if (!CheckEnergy(myPet)) return;
    std::cout<<"game id "<< this->id<<"\n";
    std::cout<<"Welcome to Guess the number!\n";
    std::cout<<"Press 1 to start the game or 0 to exit\n";
    int choice=-1;
    int lastChoice=-1;
    std::cin>>choice;
    while (choice!=0 && choice==1) {
        myPet.setEnergy(myPet.getEnergy()-this->energyCost);
        myPet.setHappiness(myPet.getHappiness()+this->energyCost/2);
        myPet.setHunger(myPet.getHunger()+this->energyCost*2);
        int gameReward=0;
        std::cout<<"Choose your level of difficulty\n";
        std::cout<<"|  1. Easy  |  "<<"|  2. Medium  |  "<<"|  3. Hard  |\n";
        int difficultyLevel;
        std::cin>>difficultyLevel;
        switch (difficultyLevel) {
            case 1: {
                std::cout<<"Guess the number between 1 and 10. You have 10 chances\n";
                int randomNo=rand() % 10 +1;
                for (int i=0;i<10;i++) {
                    int guess;
                    std::cin>>guess;
                    if (guess==randomNo) {
                        gameReward=this->reward*4 - i*20;
                        if (gameReward<0) gameReward=0;
                        std::cout<<"Congratulations! You won "<<gameReward<<" coins\n";
                        owner.setCoins(owner.getCoins()+gameReward);
                        break;
                    }
                }
                break;
            }
            case 2: {
                std::cout<<"Guess the number between 1 and 50\nYou have 12 chances\n";
                int randomNo=rand() % 50 +1;
                for (int i=0;i<12;i++) {
                    int guess;
                    std::cin>>guess;
                    if (guess==randomNo) {
                        gameReward=this->reward*15 - i*50;
                        if (gameReward<0) gameReward=0;
                        std::cout<<"Congratulations! You won "<<gameReward<<" coins\n";
                        owner.setCoins(owner.getCoins()+gameReward);
                        break;
                    }
                    else if (guess<randomNo) std::cout<<"The number is higher than "<<guess<<"\n";
                    else if (guess>randomNo) std::cout<<"The number is lower than "<<guess<<"\n";
                }
                if (gameReward==0) {
                    std::cout<<"You ran out of chances. Better luck next time!\n";
                    std::cout<<randomNo<<" was the correct answer\n";
                }
                break;
            }
            case 3: {
                std::cout<<"Guess the number between 1 and 150\nYou have 6 chances\n";
                int randomNo=rand() % 150 +1;
                for (int i=0;i<6;i++) {
                    int guess;
                    std::cin>>guess;
                    if (guess==randomNo) {
                        gameReward=this->reward*30 - i*100;
                        if (gameReward<0) gameReward=0;
                        std::cout<<"Congratulations! You won "<<gameReward<<" coins\n";
                        owner.setCoins(owner.getCoins()+gameReward);
                        break;
                    }
                    else if (guess<randomNo) std::cout<<"The number is higher than "<<guess<<"\n";
                    else if (guess>randomNo) std::cout<<"The number is lower than "<<guess<<"\n";
                }
                if (gameReward==0) {
                    std::cout<<"You ran out of chances. Better luck next time!\n";
                    std::cout<<randomNo<<" was the correct answer\n";
                }
                break;
            }
        }
        if (!CheckEnergy(myPet)) break;
        if (gameReward>Highscore) {
            Highscore=gameReward;
        }
        std::cout<<"Press 1 to play again or 0 to exit\n";
        std::cin>>lastChoice;
        choice=lastChoice;
        if (choice==0) std::cout<<"Exiting game\n";
    }
}
class Menu {
private:
    Owner* owner;
    Shop store;
    Games trivia;
    Games GuessTheNumber;
public:
    Menu();
    Menu(Owner* owner, Shop store, Games trivia, Games GuesstheNumber);
    Menu (const Menu& obj);
    Menu& operator=(const Menu& obj);
    ~Menu();
    void InteractiveMenu();
    void startGame();
    void interact();
    void ownerItems();
    void GoToShop();
    void GoToGames();
    void CreatePet();
};
Menu::Menu():owner(nullptr), store(0.0), trivia(30.0,30,{}), GuessTheNumber(50.0,30,{}) {
    trivia.selectQuestions();
}
Menu::Menu(Owner* owner, Shop store, Games trivia, Games GuesstheNumber):owner(owner),store(store),trivia(trivia),GuessTheNumber(GuesstheNumber) {
    this->trivia.selectQuestions();
}
Menu::Menu(const Menu& obj):store(obj.store),trivia(obj.trivia),GuessTheNumber(obj.GuessTheNumber) {
    if (obj.owner!=nullptr) {
        this->owner=new Owner(*(obj.owner));
    }
    else this->owner=nullptr;
    this->trivia.selectQuestions();
}
Menu& Menu::operator=(const Menu& obj){
    if (this==&obj) return *this;
    if (this->owner!=nullptr)
        delete this->owner;
    this->store=obj.store;
    this->trivia=obj.trivia;
    this->GuessTheNumber=obj.GuessTheNumber;
    if (obj.owner!=nullptr) {
        this->owner=new Owner(*(obj.owner));
    }
    else this->owner=nullptr;
    return *this;
}
Menu::~Menu() {
    if (this->owner!=nullptr)
    delete this->owner;
    else this->owner=nullptr;
}

void Menu::interact() {
    while (true) {
        if (this->owner->getPet()->getHealth()<=0)
            return;
        std::cout<<*(this->owner->getPet()); std::cout<<std::endl;
        std::cout<<"1. Feed "<<this->owner->getPet()->getName()<<"\n";
        std::cout<<"2. Cuddle "<<this->owner->getPet()->getName()<<"\n";
        std::cout<<"3. Give medicine\n";
        std::cout<<"4. "<<this->owner->getPet()->getName()<<" nap time\n";
        std::cout<<"5. Back to menu\n";
        int choice;
        std::cin>>choice;
        switch (choice) {
            case 1: this->owner->feed(); break;
            case 2: this->owner->cuddleIt(); break;
            case 3: this->owner->giveMedicine(); break;
            case 4: this->owner->putToSleep(); break;
            case 5: return;
            default: std::cout<<"Invalid option.\n";break;
        }
    }
}
void Menu::ownerItems() {
    std::cout<<this->owner->getName()<<"'s inventory:\n";
    this->owner->ShowInventory();
    std::cout<<"|"<<owner->getCoins()<<" coins\n";
    std::cout<<"===================\n";
    std::cout<<std::endl;
}

void Menu::GoToShop() {
    this->store.goShopping(*(this->owner));
}

void Menu::GoToGames() {
    std::cout<<this->trivia;
    while (true) {
        if (this->owner->getPet()->getHealth()<=0)
            return;
        std::cout<<*(this->owner->getPet()); std::cout<<std::endl;
        std::cout<<"1. Play trivia\n";
        std::cout<<"2. Play Guess the number\n";
        std::cout<<"3. Back to menu\n";
        int choice;
        std::cin>>choice;
        switch (choice) {
            case 1: this->trivia.playTrivia(*(this->owner), *(this->owner->getPet())); break;
            case 2: this->GuessTheNumber.GuessTheNumber(*(this->owner),*(this->owner->getPet())); break;
            case 3: return;
            default: std::cout<<"Invalid choice\n";break;
        }
    }
}

void Menu::CreatePet() {
    if (this->owner!=nullptr) {
        std::string petBreed;
        char gender='x';
        char petName[25];
        float age =0.0;
        std::cout<<"CREATE YOUR NEW PET AND BE A BETTER OWNER\n";
        std::cout<<"Pet name: [max 25 characters] \n";
        std::cin>>petName;
        std::cout<<"Pet breed\n";
        std::cin>>petBreed;
        while (gender!='M' and gender!='F' and gender!='m' and gender!='f') {
            std::cout<<"Pet gender(M/F): ";
            std::cin>>gender;
            if (gender!='M' and gender!='F')
                std::cout<<"Choose between M or F\n";
        }
        Pet* newPet=new Pet(petName, petBreed, &age,gender);
        this->owner->setPet(newPet);

    }
}

void Menu::startGame() {
    if (this->owner!=nullptr) {
        delete this->owner;
    }
   std::string ownerName, petBreed;
    char gender='x';
    char petName[25];
    float age=0.0;
    std::cout<<"Enter your datas \n";
    std::cout<<"Enter you name: ";
    std::cin>>ownerName;
    std::cout<<"Pet name (max 25 characters): ";
    std::cin>>petName;
    std::cout<<"Pet breed: ";
    std::cin>>petBreed;
    while (gender!='M' and gender!='F' and gender!='m' and gender!='f') {
        std::cout<<"Pet gender(M/F): ";
        std::cin>>gender;
        if (gender!='M' and gender!='F')
            std::cout<<"Choose between M or F\n";
    }

    Pet* secPet=new Pet(petName,petBreed,&age,gender);
    std::string* inventory=new std::string[2];
    inventory[0]="Biscuit";
    inventory[1]="Strawberry";
    this->owner=new Owner(ownerName,100.0,secPet,inventory,2,4);
    delete[] inventory;
    std::cin>>store;
    std::cout<<"WElCOME "<<ownerName<<"!\n";
    std::cout<<*(this->owner);
}

void Menu::InteractiveMenu() {
    int mainChoice=-1;
        std::cout<<"[MAIN MENU]\n";
        std::cout<<"1.Start Game\n";
        std::cout<<"Press anything else to exit\n";
        std::cin>>mainChoice;
        if (mainChoice==1) {
            startGame();
                while(true) {
                    if (this->owner!=nullptr && this->owner->getPet()!=nullptr && this->owner->getPet()->getisAlive()){
                        std::cout<<*(this->owner->getPet());
                        std::cout<<"1. CHANGE YOUR NAME\n";
                        std::cout<<"2. CHANGE PETS'S NAME\n";
                        std::cout<<"3. INTERRACT WITH "<< this->owner->getPet()->getName()<<"\n";
                        std::cout<<"4. SHOW MY ITEMS\n";
                        std::cout<<"5. SHOP\n";
                        std::cout<<"6. GAMES\n";
                        std::cout<<"7. Exit\n";
                        int choice;
                        std::cin>>choice;
                        switch (choice) {
                            case 1: {
                                std::cin>>*(this->owner);
                                std::cout<<*(this->owner);
                                break;
                            };
                            case 2: {
                                std::cin>>*(this->owner->getPet());
                                break;
                            };
                            case 3: {
                                interact();
                                break;
                            };
                            case 4: {
                                ownerItems();
                                break;
                            };
                            case 5: {
                                GoToShop();
                                break;
                            };
                            case 6: {
                                GoToGames();
                                break;
                            };
                            case 7: std::cout<<"ByeBye\n"; return;
                            default: std::cout<<"Invalid choice\n";
                        }
                    }
                    else {
                        std::cout<<"1. Start new game\n";
                        std::cout<<"2. Continue this session and create new pet\n";
                        std::cout<<"3. Exit\n";
                        int choice;
                        std::cin>>choice;
                        switch (choice) {
                            case 1: startGame(); break;
                            case 2: CreatePet(); break;
                            case 3: return;
                            default: std::cout<<"Invalid choice\n";
                        }
                    }
            }
        }
    else {
        std::cout<<"ByeBye\n";
        return;
    }
}

int main() {
    srand(time(0));
    Menu game;
    game.InteractiveMenu();
    return 0;

}