#include "Player.h"
#include "Vocation.h"
#include <iostream>
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


	



}

Player::~Player()
{
	
	delete playerVocation;


	
	
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
