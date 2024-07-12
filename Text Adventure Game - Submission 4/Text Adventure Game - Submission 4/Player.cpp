#include "Player.h"
#include "Vocation.h"
#include <iostream>
#include <algorithm>
Player::Player() 
{
	playerName = "You";
	
	
	playerVocation = new Vocation;

	vocationName = nullptr;

	health	= 10;

	defense = 10;

	attack = 10;
	magicAttack = 10;

	stamina = 10;
	mana = 10;


	


	spellsLength = 10;
	for (int i = 0; i < spellsLength; i++) {
		if (i == 0) {
			spells[i] = "Swing";
		}

		if (i == 1) {
			spells[i] = "Block";
		}

		if (i == 2) {
			spells[i] = "Blade of Faith";
		}

		if (i == 3) {
			spells[i] = "Blade of Truth";
		}

		if (i == 4) {
			spells[i] = "Whirlwind";
		}

		if (i == 5) {
			spells[i] = "Bloodlust";
		}

		if (i == 6) {
			spells[i] = "Energy Blast";
		}

		if (i == 7) {
			spells[i] = "Magic Shield";
		}

		if (i == 8) {
			spells[i] = "Heal";
		}

		if (i == 9) {
			spells[i] = "Concentrate";
		}

	}
	
	


}

Player::~Player()
{
	
	delete playerVocation;


	
	
}

bool Player::Playerisxdead()
{
	if (health < 0) {
		return true;
	}
	return false;
}

void Player::SetVocation()
{
	vocationName = &playerVocation->vocationName;

	health = playerVocation->health;

	defense = playerVocation->defense;

	attack = playerVocation->attack;
	magicAttack = playerVocation->magicAttack;

	stamina = playerVocation->stamina;
	mana = playerVocation->mana;

	//Spells

}

void Player::Hud()
{
	String paladin = "PALADIN";
	String warrior = "WARRIOR";
	String mage = "MAGE";

	if (*vocationName == paladin) {
		std::cout << "-------------------------------------\n";
		std::cout << "Health:  " << health << "              " << "Attack: " << attack << " " << std::endl;
		std::cout << "Defense: " << defense << "               " << std::endl;
		std::cout << "Stamina: " << stamina << "                 Vocation" << std::endl;
		std::cout << "Mana: " << mana << "                     " << vocationName->CString() << "" << std::endl;
		std::cout << "-------------------------------------\n";
	}
	if (*vocationName == warrior) {
		std::cout << "-------------------------------------\n";
		std::cout << "Health:  " << health << "               " << "Attack: " << attack << " " << std::endl;
		std::cout << "Defense: " << defense << "               " << std::endl;
		std::cout << "Stamina: " << stamina << "                 Vocation" << std::endl;
		std::cout << "                              " << vocationName->CString() << "" << std::endl;
		std::cout << "-------------------------------------\n";
	}
	if (*vocationName == mage) {
		std::cout << "-------------------------------------\n";
		std::cout << "Health:  " << health << "             " << "MAttack: " << magicAttack << " " << std::endl;
		std::cout << "Defense: " << defense << "               " << std::endl;
		std::cout << "mana: " << mana << "                    Vocation" << std::endl;
		std::cout << "                                 " << vocationName->CString() << "" << std::endl;
		std::cout << "-------------------------------------\n";
	}
	
}

void Player::ChooseName()
{
	String bufferName = "";
	String bufferYesNo = "";
	bool areYouSure = true;
	bool typingname = true;
	String consoleYesAndNO;
	String consoleName;

	while (typingname) {

		
		std::cout << "WHAT IS YOUR NAME!!!!\n";
		consoleName.ReadFromConsole();

		
		areYouSure = true;
		while (areYouSure) {
			std::cout << "Your name is [" <<consoleName.CString() << "], are you sure?\nY/N\n";

			consoleYesAndNO.ReadFromConsole();
			bufferName = consoleName;
			
			if (consoleYesAndNO.Uppercase() == "Y") {
				typingname = false;
				areYouSure = false;
				playerName = consoleName;
				bufferYesNo = consoleYesAndNO;
			}
			if (consoleYesAndNO.Uppercase() == "N") {
				areYouSure = false;
			}
		}

	}

	consoleName = bufferName;
	consoleYesAndNO = bufferYesNo;
	

}

namespace StringUtility
{
	//https://www.geeksforgeeks.org/bubble-sort-algorithm/
	/*I had to grab this code because the normal array sorter can't sort my string array. because I don't have a sorter in my string utility class.
	  and if I had a string list I couldn't access[] when doing my binary search*/
	void BubbleSort(String arr[], int n) {
		int i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++) {
			swapped = false;
			for (j = 0; j < n - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					std::swap(arr[j], arr[j + 1]);
					swapped = true;
				}
			}

			// If no two elements were swapped
			// by inner loop, then break
			if (swapped == false)
				break;
		}
	}
}
bool Player::FindSpell(String spell)
{
	
	

	int length = sizeof(spells) / sizeof(String);
	int l = 0;
	int r = length -1;

	StringUtility::BubbleSort(spells, length);

	while (l <= r)
	{

		int m = (int)((l + r) / 2);

		if (spells[m] == spell) {
			return true;
		}
		if (spells[m] < spell) {
			l = m + 1;
		}
		if (spells[m] > spell) {
			r = m - 1;
		}
		
	}
	return false;

}
