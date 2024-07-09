#include "String.h"
#include "Vocation.h"
#pragma once
class Player
{
public:
	String* vocationName;
	Vocation* playerVocation;


private:
	int* health;
	int* defense;

	int* attack;
	int* magicAttack;

	int* stamina;
	int* mana;

public: 

	Player();

   ~Player();

public:

	void SetVocation();


     


};

