#pragma once
#include "Creature.h"
#include <iostream>
class Kobold
{
	int health = 100;
	int defense = 10;

	int damage = 25;
public:
	int TakeDamage(float damage) {
		
		damage = damage / defense * 20;
		health -= damage;
		return damage;
	}

	int Swing() {
		std::cout << "Kobold swing his sword";
		return damage;
	}

	bool KoboldIsDead() {
		if (health <= 0) {
			return true;
		}
		return false;
	}
};

