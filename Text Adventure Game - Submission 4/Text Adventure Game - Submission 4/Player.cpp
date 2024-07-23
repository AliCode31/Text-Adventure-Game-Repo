#include "Player.h"
#include "Vocation.h"
#include <iostream>
#include <algorithm>
#include <tchar.h>
#include <Windows.h>
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


	


	spellsLength = 11;
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
			spells[i] = "Clemency";
		}

		if (i == 10) {
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
	if (health <= 0) {
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
		std::cout << "\n-------------------------------------\n";
		std::cout << "Health:  " << health << "              " << "Attack: " << attack << " " << std::endl;
		std::cout << "Defense: " << defense << "               " << std::endl;
		std::cout << "Stamina: " << stamina << "                 Vocation" << std::endl;
		std::cout << "Mana: " << mana << "                     " << vocationName->CString() << "" << std::endl;
		std::cout << "-------------------------------------\n";

		std::cout << "Skills:              Spells:        |\n";
		std::cout << "Swing                Clemency       |\nBlock                Blade of Faith |\n                     Blade of Truth |\n";
		std::cout << "-------------------------------------\n\n\n";
	}
	if (*vocationName == warrior) {
		std::cout << "\n-------------------------------------\n";
		std::cout << "Health:  " << health << "               " << "Attack: " << attack << " " << std::endl;
		std::cout << "Defense: " << defense << "               " << std::endl;
		std::cout << "Stamina: " << stamina << "                 Vocation" << std::endl;
		std::cout << "                              " << vocationName->CString() << "" << std::endl;
		std::cout << "-------------------------------------\n";
		std::cout << "Skills:                         |\n";
		std::cout << "Swing                 Bloodlust |\nBlock                 Whirlwind |\n";
		std::cout << "---------------------------------\n\n\n";

	}
	if (*vocationName == mage) {
		std::cout << "\n------------------------------------\n";
		std::cout << "Health:  " << health << "             " << "MAttack: " << magicAttack << " " << std::endl;
		std::cout << "Defense: " << defense << "               " << std::endl;
		std::cout << "mana: " << mana << "                   Vocation" << std::endl;
		std::cout << "                                " << vocationName->CString() << "" << std::endl;
		std::cout << "------------------------------------\n";
		std::cout << "Spells:                            |\n";
		std::cout << "Energy Blast           Concentrate |\nMagic Shield                  Heal |\n";
		std::cout << "------------------------------------\n\n\n";
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
bool Player::FindSpell(String* spell)
{
	
	

	int length = sizeof(spells) / sizeof(String);
	int l = 0;
	int r = length -1;

	StringUtility::BubbleSort(spells, length);

	while (l <= r)
	{

		int m = (int)((l + r) / 2);

		if (spells[m] == *spell) {
			return true;
		}
		if (spells[m] < *spell) {
			l = m + 1;
		}
		if (spells[m] > *spell) {
			r = m - 1;
		}
		
	}
	return false;

}

int Player::CastSpell(String castSpells)
{
	if (FindSpell(&castSpells)) {

		if (*vocationName == "PALADIN") {

			if (castSpells == "Swing") {
				if (stamina > 0) {
					std::cout << "You swing your sword";
					stamina -= 2;
					return attack;
				}
				else { std::cout << "Your to tired to swing your sword"; return 0; }

			}

			if (castSpells == "Block") {
				std::cout << "You raise your shield getting ready to block";
				defense = 200;
				return defense;
			}
			if (castSpells == "Clemency") {
				if (mana > 0) {
					std::cout << "You raise your sword high in the sky and channel your oath to heal any wounds on you";
					mana -= 1;
					health += 100;
					PlaySound(_T("Power.wav"), NULL, SND_ASYNC);
				}
				else { std::cout << "You have no mana left"; return 0; }
				if (health > 130) {
					health = 120;
				}
				return health;
			}
			if (castSpells == "Blade of Faith") {
				if (paladinBuff) {std::cout <<"Buff already active!"; }	
				else {
					if (mana > 0) {
						std::cout << "You pierce your sword to the ground channeling your oath to succeed, you feel stronger";
						attack = 135;
						mana -= 1;
						paladinBuff = true;
						PlaySound(_T("Power.wav"), NULL, SND_ASYNC);

						return defense;
					}
					else { std::cout << "You have no mana left"; return 0; }
				}
			}
			if (castSpells == "Blade of Truth") {

				if (mana > 0) {
					std::cout << "You plunge your sword to the ground and let go of your shield, you close your eyes and start channeling your oath, swords around you start to summon.\nYou then open your eyes and lift your sword to point it at the enemy, the swords around you fly past and stab the enemy dealing a lot of damage";
					mana -= 1;
					int newDamage = attack * 5;
					return newDamage;

				}
				else {
					std::cout << "You have no mana left";
					return 0;
				}
			}


		}
		if (*vocationName == "WARRIOR") {

			if (castSpells == "Swing") {
				if (stamina > 0) {
					std::cout << "You swing your Axe";
					stamina -= 2;
					return attack;
				}
				else { std::cout << "Your to tired to swing your axer"; return 0; }
			}

			if (castSpells == "Block") {
				std::cout << "You block with your axe";
				defense = 200;
				return defense;
			}
			if (castSpells == "Whirlwind") {
				if (stamina > 0) {
					std::cout << "You start to spin around with your axe out attacking whoever goes near it";
					int newDamage = attack * 5;
					stamina -= 2;
					return newDamage;
				}
				else { std::cout << "You are to tired!"; return 0; }
			}
			if (castSpells == "Bloodlust") {
				if (warriiorBuff) { std::cout << "Buff already active!"; }
				else {
					if (stamina > 0) {
						stamina -= 5;
						std::cout << "You start to smile and laugh at the enemy, you lower your axe and get in a trance. A red aura around you starts to appear. You have the urge to kill anything in your way";
						warriiorBuff = true;
						PlaySound(_T("Power.wav"), NULL, SND_ASYNC);
					}
					else { std::cout << "Your are to tried!"; }
					return 0;
				}
			}
		}
		if (*vocationName == "MAGE") {

			if (castSpells == "Energy Blast") {
				std::cout << "You put your hands together and suck up all the aether to create a ball of enerfy then launched it the enemy";
				return magicAttack;
			}

			if (castSpells == "Magic Shield") {
				std::cout << "You raise both of your hands and make a shield of energy, blocking an attack";
				defense = 200;
				PlaySound(_T("Power.wav"), NULL, SND_ASYNC);
				return defense;
			}
			if (castSpells == "Heal") {
				if (mana > 0) {
					std::cout << "You open your grimoire and recite one of the pages, your whole body is surrounded in blue aura. You then feel your wounds go away";
					mana -= 2;
					health += 120;
					PlaySound(_T("Power.wav"), NULL, SND_ASYNC);
				}
				else { std::cout << "You have no mana left"; return 0; }
			}
			if (castSpells == "Concentrate") {
				if (mageBuff) { std::cout << "Buff already active!"; }
				else {
					if (mana > 0) {
						std::cout << "You open your grimoire and recite two pages in the book out loud, a white Aura around you starts to form. You feel more focused ";
						mana -= 5;
						mageBuff = true;
						PlaySound(_T("Power.wav"), NULL, SND_ASYNC);
					}
					else { std::cout << "You have no mana left"; return 0; }
				}
			}
		}
	}
}

int Player::TakeDamage(float damage)
{
	damage = damage / defense * 20;
	health -= damage;

	if (*vocationName == "PALADIN") {
		defense = 100;
	}
	if (*vocationName == "WARRIOR") {
		defense = 80;
	}
	if (*vocationName == "MAGE") {
		defense = 50;
	}
	std::cout << "\n    You take " << damage << " damage\n\n";
	PlaySound(_T("PlayerHurt.wav"), NULL, SND_ASYNC);
	if (health <= 0) {
		health = 0;
		std::cout << "\n    You are at " << health << " health\n\n";
	}

		
	return damage;
}

void Player::Buffs()
{ 
;
	if (paladinBuff) {
		countdown-=1;
		if (countdown > 0) {
			std::cout << "\n\nYou have " << countdown << " of buff left\n\n";
		}
		if (countdown == 0) {
			std::cout << "\n\nYour buff has ran out\n\n";
			attack = 15;
			countdown = 4;
			paladinBuff = false;
		}
	}
	if (warriiorBuff) {
		countdown -= 1;
		stamina = 100;
		attack = 150;
		if (countdown > 0) {
			health += 50;
			std::cout << "\n\n\You start to soak in the blood of your enemy, you recover from your battle wounds\n";
			std::cout << "      You have " << countdown << " of buff left\n\n";
		}
		if (countdown == 0) {
			std::cout << "\n\nYour buff has ran out\n\n";
			attack = 30;
			countdown = 4;
			warriiorBuff = false;
		}
	}
	if (mageBuff) {
		countdown -= 1;
		magicAttack = 500;
		if (countdown > 0) {
			std::cout << "\n\n You have " << countdown << " of buff left\n\n";
		}
		if (countdown == 0) {
			std::cout << "\n\nYour buff has ran out\n\n";
			magicAttack = 50;;
			countdown = 4;
			mageBuff = false;
		}
	}



}
