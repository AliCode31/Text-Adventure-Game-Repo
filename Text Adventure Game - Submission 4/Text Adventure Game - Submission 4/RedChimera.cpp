#include "RedChimera.h"

int RedChimera::TakeDamage(float damage) {
	if (health > 0) {
		damage = damage / defense * 20;
		health -= damage;
		std::cout << "\n    Chimera takes " << damage << " damage\n";
		if (health <= 0) {
			health = 0;
			std::cout << "    Chimera's health is " << health;
		}
		else std::cout << "    Chimera's health is " << health;

		PlaySound(_T("EnemyHurt.wav"), NULL, SND_SYNC);
	}

	return damage;
}

 int RedChimera::ChimeraMoveSet() {

	 if (health >= 1000) {
		 defense = 200;
		 if (attackIndex < 5 || attackIndex > 5 && attackIndex < 10 || attackIndex > 10 && attackIndex < 15) {

			 if (subIndex == 1 || subIndex == 6) {
				 damage = 115;
				 std::cout << "Chimera goes for a bite";
				 subIndex++;

			 }
			 else if (subIndex == 2 || subIndex == 7) {
				 damage = 100;
				 std::cout << "Chimera whips you with its tail";
				 subIndex++;
			 }
			 else if (subIndex == 3 || subIndex == 8) {
				 damage = 130;
				 std::cout << "Chimera charges at you";
				 subIndex++;
			 }
			 else if (subIndex == 4) {
				 if (attackIndex == 14) {
					 damage = 130;

					 std::cout << "Chimera scratches you with its claws and is charging up a big attack ";
					 subIndex = 1;
				 }
				 else {
					 damage = 130;
					 std::cout << "Chimera sctratches you with its claws";
					 subIndex = 1;
				 }
			 }

			 attackIndex++;
			 return damage;
		 }
		 else if (attackIndex == 5) {
			 damage = 150;
			 attackIndex++;
			 std::cout << "The snake on the Chimera bites you";
			 return damage;
		 }
		 else if (attackIndex == 10) {
			 damage = 200;
			 attackIndex++;
			 std::cout << "The goat on the Chimera uses a magic spells and summons a ball of energy and sends it right at you";
			 return damage;
		 }
		 else if (attackIndex == 15) {
			 damage = 350;
			 attackIndex = 1;
			 std::cout << "The Chimera stops attacking you. Then you see a red aura surround the Chimera, it starts to growl heavily, then in a blink of your eyes it launches straight at you with a big slash with its claws";
			 return damage;
		 }
	 }
	 if (health >= 500) {
		 defense = 150;
		 if (attackIndex < 5 || attackIndex > 5 && attackIndex < 10 || attackIndex > 10 && attackIndex < 15) {

			 if (subIndex == 1 || subIndex == 6) {
				 damage = 115;
				 std::cout << "Chimera goes for a bite";
				 subIndex++;

			 }
			 else if (subIndex == 2 || subIndex == 7) {
				 damage = 0;
				 std::cout << "The Chimera's tail is gone it can't whip you";
				 subIndex++;
			 }
			 else if (subIndex == 3 || subIndex == 8) {
				 damage = 130;
				 std::cout << "Chimera charges at you";
				 subIndex++;
			 }
			 else if (subIndex == 4) {
				 if (attackIndex == 14) {
					 damage = 130;

					 std::cout << "Chimera scratches you with its claws and is charging up a big attack ";
					 subIndex = 1;
				 }
				 else {
					 damage = 130;
					 std::cout << "Chimera sctratches you with its claws";
					 subIndex = 1;
				 }
			 }

			 attackIndex++;
			 return damage;
		 }
		 else if (attackIndex == 5) {
			 damage = 0;
			 attackIndex++;
			 std::cout << "The Snake is dead, it can't bite you";
			 return damage;
		 }
		 else if (attackIndex == 10) {
			 damage = 200;
			 attackIndex++;
			 std::cout << "The Goat on the Chimera uses a magic spells and summons a ball of energy and sends it right at you";
			 return damage;
		 }
		 else if (attackIndex == 15) {
			 damage = 350;
			 attackIndex = 1;
			 std::cout << "The Chimera stops attacking you. Then you see a red aura surround the Chimera, it starts to growl heavily, then in a blink of your eyes it launches straight at you with a big slash with its claws";
			 return damage;
		 }
	 }
	 if (health <= 500) {
		 defense = 80;
		 if (attackIndex < 5 || attackIndex > 5 && attackIndex < 10 || attackIndex > 10 && attackIndex < 15) {

			 if (subIndex == 1 || subIndex == 6) {
				 damage = 115;
				 std::cout << "Chimera goes for a bite";
				 subIndex++;

			 }
			 else if (subIndex == 2 || subIndex == 7) {
				 damage = 0;
				 std::cout << "The Chimera's tail is gone it can't whip you";
				 subIndex++;
			 }
			 else if (subIndex == 3 || subIndex == 8) {
				 damage = 130;
				 std::cout << "Chimera charges at you";
				 subIndex++;
			 }
			 else if (subIndex == 4) {
				 if (attackIndex == 14) {
					 damage = 130;

					 std::cout << "Chimera scratches you with its claws and is charging up a big attack ";
					 subIndex = 1;
				 }
				 else {
					 damage = 130;
					 std::cout << "Chimera sctratches you with its claws";
					 subIndex = 1;
				 }
			 }

			 attackIndex++;
			 return damage;
		 }
		 else if (attackIndex == 5) {
			 damage = 0;
			 attackIndex++;
			 std::cout << "The Snake is dead, it can't bite you";
			 return damage;
		 }
		 else if (attackIndex == 10) {
			 damage = 200;
			 attackIndex++;
			 std::cout << "The Goat is dead, The Chimera can't do magic spells anymore";
			 return damage;
		 }
		 else if (attackIndex == 15) {
			 damage = 350;
			 attackIndex = 1;
			 std::cout << "The Chimera stops attacking you. Then you see a red aura surround the Chimera, it starts to growl heavily, then in a blink of your eyes it launches straight at you with a big slash with its claws";
			 return damage;
		 }
	 }
}




 bool RedChimera::RedChimeraIsDead() {
	if (health <= 0) {
		return true;
	}
	return false;
}

 bool RedChimera::StageOne()
 {
	 if (health <= 1000) {
		 return false;
	 }
	 else return true;
 }

 bool RedChimera::StageTwo()
 {
	 if (health <= 500) {
		 return false;
	 }
	 else return true;
 }

 bool RedChimera::StageThird()
 {
	 if (health <= 500) {
		 return true;
	 }
	 else return false;
 }

 
