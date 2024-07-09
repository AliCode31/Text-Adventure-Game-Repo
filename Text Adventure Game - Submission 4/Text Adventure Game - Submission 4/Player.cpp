#include "Player.h"
#include "Vocation.h"
Player::Player() 
{


	vocationName = new String("Unknown");
	playerVocation = new Vocation;



	health = new int(100);
	defense = new int(100);

	attack = new int(100);
	magicAttack = new int(100);

	stamina = new int(100);
	mana = new int(100);


	



}

Player::~Player()
{
	delete[] vocationName;
	delete playerVocation;

	delete health;
	delete defense;

	delete attack;
	delete magicAttack;

	delete stamina;
	delete mana;

	
}
