#pragma once
#include <iostream>
#include <Windows.h>
#include <tchar.h>
class RedChimera
{
private:
	int health = 1500;
	int defense = 200;

	int damage = 100;

	int attackIndex = 1;
	int subIndex = 1;

public:

	int TakeDamage(float damage);

	int ChimeraMoveSet();

	bool RedChimeraIsDead();
	bool StageOne();
	bool StageTwo();
	bool StageThird();
};

