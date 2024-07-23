#include "String.h"
#include "Vocation.h"
#include <list>
#include <vector>
#pragma once
class Player
{
	bool paladinBuff = false;
	bool warriiorBuff = false;
	bool mageBuff = false;
	int countdown = 4;
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
	String spells[11];
	
	
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
	void Buffs();
};

