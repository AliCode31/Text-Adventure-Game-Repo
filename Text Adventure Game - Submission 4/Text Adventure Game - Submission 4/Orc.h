#pragma once
#include <iostream>
#include <Windows.h>
#include <tchar.h>
class Orc
{
	int health = 300;
	int defense = 120;

	int damage = 130;
public:

	int TakeDamage(float damage) {
		if (health > 0) {
			damage = damage / defense * 20;
			health -= damage;
			std::cout << "\n    Orc takes " << damage << " damage\n";
			if (health <= 0) {
				health = 0;
				std::cout << "    Orc's health is " << health;
			}
			else std::cout << "    Orc's health is " << health;

			PlaySound(_T("EnemyHurt.wav"), NULL, SND_SYNC);
		}




		return damage;
	}

	int Swing() {
		std::cout << "Orc swing his axe";
		return damage;
	}

	bool OrcIsDead() {
		if (health <= 0) {
			return true;
		}
		return false;
	}
};

