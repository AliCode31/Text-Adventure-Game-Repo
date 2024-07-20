#pragma once
#include <iostream>
class Goblin{
	int health = 200;
	int defense = 30;

	int damage = 50;
public:

	int TakeDamage(float damage) {
		if (health > 0) {
			damage = damage / defense * 20;
			health -= damage;
			std::cout << "\n    Goblin takes " << damage << " damage\n";
			if (health <= 0) {
				health = 0;
				std::cout << "    Goblin's health is " << health;
			} else std::cout << "    Goblin's health is " << health;
				 
			PlaySound(_T("EnemyHurt.wav"), NULL, SND_SYNC);
		}
		

		

		return damage;
	}

	int Swing() {
		std::cout << "Goblin swing his falchion";
		return damage;
	}

	bool GoblinIsDead() {
		if (health <= 0) {
			return true;
		}
		return false;
	}
};

