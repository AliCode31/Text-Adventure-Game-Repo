#pragma once
#include "Creature.h"
#include <iostream>
#include <tchar.h>
#include <Windows.h>

class Kobold
{
	int health = 250;
	int defense = 30;

	int damage = 25;
public:
	int TakeDamage(float damage) {
		
		damage = damage / defense * 20;
		health -= damage;
		std::cout << "\n    Kobold takes "  << damage << " damage\n";
		if (health <= 0) {
			health = 0;
			std::cout << "    Kobold's health is " << health;
		} else std::cout << "    Kobold's health is " << health;
		PlaySound(_T("EnemyHurt.wav"), NULL, SND_ASYNC);

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

