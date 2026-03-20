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

    void CheckDeath();
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
    void ShowStatus();
    int getHealth() const;
    void setHealth(int health);
    int getEnergy() const;
    void setEnergy(int energy);
    int getHappiness() const;
    void setHappiness(int happiness);
    const char* getName() const;
    int getHunger() const;
    void setHunger(int hunger);
    static int getnoInstance();
    int getId() const;
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
         hunger-=30;
         health+=20;
         energy+=20;
     }
     else if (foodChoice=="Strawberry" || foodChoice=="Banana" || foodChoice=="Blueberry" || foodChoice=="Peach") {
         hunger-=18;
         health+=10;
         energy+=20;
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
     (*age)+=0.1;
     std::cout<<name<<" is awake now";
     CheckLimits();
     ShowWarnings();
     CheckDeath();
 }

void Pet::cuddle() {
    happiness+=20;
    energy-=5;
     std::cout<<"You spent some quality time with "<<name;
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
     std::cout<<"PET STATUS: "<<name<<" "<<(*age)<<" years "<<std::endl;
     std::cout<<"|HP :"<<health<<"/100 "<<"| EN :"<<energy<<"/100 "<<"| HG :"<<hunger<<"/100 "<<"| HAPPY"<<happiness<<"/100 "<<std::endl;;

 }
//setters and getters
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
int Pet::getHunger() const{
     return hunger;
}
void Pet::setHunger(int hunger) {
     this->hunger=hunger;
     CheckLimits();
 }

const char* Pet::getName() const{
    return name;
}

int Pet::getnoInstance() {
    return noInstance;
}

int Pet::getId() const {
    return id;
}

class Owner {
 private:
     std::string name;
     int age;
     double coins;
     Pet* myPet;
     std::vector<std::string> inventory;
     const int id;
     static int noInstance;
 public:
     Owner();
     Owner(std::string, int, double,Pet*,std::vector<std::string>);
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
     static int getnoInstance();
     int getId() const;

 };

int Owner::noInstance=0;

Owner::Owner(): id(++noInstance) {
    this->name="N/A";
    this->age=0;
    this->coins=100.0;
    this->myPet=nullptr;
}

Owner::Owner(std::string name, int age, double coins,Pet* myPet,std::vector<std::string> inventory): id(++noInstance) {
    this->name=name;
    this->age=age;
    this->coins=coins;
    this->myPet=myPet;
    this->inventory=inventory;
}

Owner::Owner(const Owner &obj):id(++noInstance) {
    this->name=obj.name;
    this->age=obj.age;
    this->coins=obj.coins;
    this->inventory=obj.inventory;
    if (obj.myPet!=nullptr) {
        this->myPet=new Pet(*(obj.myPet));
    }
    else this->myPet=nullptr;
}

Owner& Owner::operator=(const Owner &obj) {
    if (this==&obj) return *this;
    delete this->myPet;
    this->name=obj.name;
    this->age=obj.age;
    this->coins=obj.coins;
    this->inventory=obj.inventory;
    if (obj.myPet!=nullptr) {
        this->myPet=new Pet(*(obj.myPet));
    }
    else this->myPet=nullptr;
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
//setters and getters
double Owner::getCoins() const {
    return coins;
}
void Owner::setCoins(double coins) {
    this->coins=coins;
}
//Owner functions
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
    const int id;
    static int noInstance;
public:
    Shop();
    Shop(double);
    Shop(const Shop &obj);
    Shop& operator=(const Shop &obj);
    ~Shop();
    void goShopping(Owner& owner);
};
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

struct questionsArray {
    std::string question;
    std::string answer;
};
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
};

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

void Games::selectQuestions() {
    questions={
        {"How many eyerbows does Mona Lisa have?", "0"},
        {"What is the national animal of India?", "bengal tiger"},
        {"What color is a polar bear skin?", "black"},
        {"What does Hakuna matata means?", "bo worries"},
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
    std::cout<<"Current income score is "<<Highscore<<"\n";
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
    std::cout<<"Current highest income is "<<Highscore<<"\n";
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
                        gameReward=this->reward*4 - i*4;
                        if (gameReward<0) gameReward=0;
                        std::cout<<"Congratulations! You won"<<gameReward<<" coins\n";
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
                        gameReward=this->reward*15 - i*8;
                        if (gameReward<0) gameReward=0;
                        std::cout<<"Congratulations! You won"<<gameReward<<" coins\n";
                        owner.setCoins(owner.getCoins()+gameReward);
                        break;
                    }
                    else if (guess<randomNo) std::cout<<"The number is higher than"<<guess<<"\n";
                    else if (guess>randomNo) std::cout<<"The number is lower than"<<guess<<"\n";
                }
                if (gameReward==0) std::cout<<"You ran out of chances. Better luck next time!\n";
                break;
            }
            case 3: {
                std::cout<<"Guess the number between 1 and 150\nYou have 6 chances\n";
                int randomNo=rand() % 150 +1;
                for (int i=0;i<6;i++) {
                    int guess;
                    std::cin>>guess;
                    if (guess==randomNo) {
                        gameReward=this->reward*30 - i*10;
                        if (gameReward<0) gameReward=0;
                        std::cout<<"Congratulations! You won"<<gameReward<<" coins\n";
                        owner.setCoins(owner.getCoins()+gameReward);
                        break;
                    }
                    else if (guess<randomNo) std::cout<<"The number is higher than"<<guess<<"\n";
                    else if (guess>randomNo) std::cout<<"The number is lower than"<<guess<<"\n";
                }
                if (gameReward==0) std::cout<<"You ran out of chances. Better luck next time!\n";
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
int main() {

}