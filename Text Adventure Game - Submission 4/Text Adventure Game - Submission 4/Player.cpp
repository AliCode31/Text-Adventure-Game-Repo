#include "Player.h"
#include "Vocation.h"
Player::Player() 
{

	
	
	playerVocation = new Vocation;

	vocationName = new String();

	health	= new int(10);

	defense = new int(19);

	attack = new int(10);
	magicAttack = new int(10);

	stamina = new int(10);
	mana = new int(10);


	



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

void Player::SetVocation()
{
	vocationName = new String(playerVocation->vocationName);

	health = new int(playerVocation->health);

	defense = new int(playerVocation->defense);

	attack = new int(playerVocation->attack);
	magicAttack = new int(playerVocation->magicAttack);

	stamina = new int(playerVocation->stamina);
	mana = new int(playerVocation->mana);
}
