#include "String.h"
#include "Vocation.h"
#include <list>
#include <vector>
#pragma once
class Player
{
public:

	String playerName;

	String* vocationName;
	Vocation* playerVocation;
	
private:
	int health;
	int defense;

	int attack;
	int magicAttack;

	int stamina;
	int mana;
	int spellsLength;
	String spells[10];
	
	
public: 
	
	Player();

   ~Player();

public:
	bool Playerisxdead();
	void SetVocation();
	void Hud();

	void ChooseName();
	bool FindSpell(String* spell);
	int CastSpell(String castSpell);
	int TakeDamage(float damage);
};

