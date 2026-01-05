//TextFighter
#include <time.h>	//Use this for our random number
#include <iostream> //Use this for cout
using namespace std;

/* Create a class called Fighter with public and private members*/
class Fighter
{

private:
	int Health;
public:
	Fighter(int);			//The Constructor definition

	//mutator
	void setHealth(int);	//Allows us to set the health
	//accessor
	int getHealth();		//Allows us to get the health

	//other methods
	int attack();			//Creates an attack from a random number
	void takeDamage(int);	//Receives Damage

	~Fighter();				//Destructor: This gets called when the object goes out of scope
};



/*
The next section that follows is the implementation of our class functions.
Notice that they have the "ClassName::Function" format.
*/
// Start Class implementation
Fighter::Fighter(int theHealth) //This is the constructor
{
	Health = theHealth;
}

Fighter::~Fighter() //The destructor
{
	//You dont have to create a destructor but it helps to do clean up
	//when an object is destroyed by going out of scope.
	cout << "[Object destroyed due to out of scope]" << endl;
}
//This function is a mutator or setter, meaning it just changes a private member
void Fighter::setHealth(int theHealth)
{
	Health = theHealth;
}

//This function is an accessor or getter, it just gets a private member
int Fighter::getHealth()
{
	return Health;
}

//Our attack function returns an attack value
int Fighter::attack()
{
	//returns a random number from 10 (low end) to 35 (high end)
	int upper = 35;
	int lower = 10;
	return (rand() % (upper - lower + 1)) + lower;
}

//Our take damage function changes the fighter's health
void Fighter::takeDamage(int damage)
{
	Health = Health - damage;
}
//end Class implementation

void  playerFight(int); //Function prototype

//Here we wil use our objects
int main()
{
	//We need the following to set up our randomizer correctly (C++ random function)
	srand(time(NULL));
	//Round 1...Fight!
	playerFight(1);
	//Round 2...Fight!
	playerFight(2);
	//Round 3..Fight
	playerFight(3);
	return 0;
}

void playerFight(int round) {
	//Lets instantiate 2 objects from our player class. Both are individual objects!
	Fighter ryu(100); //this instantiates a ryu fighter object and calls the constructor
	Fighter ken(100); //this instantiates a ken fighter object and calls the constructor

	cout << endl << endl << "Starting round" << endl;
	bool fightIsOver = false;
	while (!fightIsOver)
	{
		int ryuAttack = ryu.attack();
		cout << "Ryu attacks with a hadouken! Attack:" << ryuAttack << endl;
		int kenAttack = ken.attack();
		cout << "Ken attacks with shoryuken! Attack:" << kenAttack << endl;

		ryu.takeDamage(kenAttack);
		ken.takeDamage(ryuAttack);

		//TODO Implement a superAttack()
		//Create a function thats part of the class called superAttack() that creates a damage from 30 to 50
		//and can only be executed  by a player whose health is less than 15 

		if (ryu.getHealth() <= 0 || ken.getHealth() <= 0)
		{
			fightIsOver = true;
			cout << "Round " << round << " is over " << endl;
			if (ryu.getHealth() > 0)
			{
				cout << "Ryu Wins! " << endl;
			}
			else
				cout << "Ken Wins! " << endl;
		}
	}
}

