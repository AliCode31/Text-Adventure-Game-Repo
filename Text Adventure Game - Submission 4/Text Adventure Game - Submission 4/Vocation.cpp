#include "iostream"
#include "Vocation.h"
#include "String.h"


void Vocation::ChooseVocation()
{
	String paladin = "PALADIN";
	String warrior = "WARRIOR";
	String mage = "MAGE";
	String bufferVocation = "";
	String bufferYesNo = "";
	bool typingVocation = true;
	bool areYouSure = false;
	String consoleVocation;
	String consoleYesAndNO;
	 
	std::cout << "\n\n";
	std::cout << "_________________________________________________________________________________________________________________________________________________\n";
	std::cout << " [PALADIN]  |\"Paladins are holy knights that stick to the oath and never break it. You swore to uphold justice and be righteous, you protect the/\n____________| people from danger. [you are a beacon of hope] You use a {sword and a shield} and can cast {spells} fuelled by your oath\"        /\n";
	std::cout << "Health:  100|-------------------------------------------------------------------------------------------------------------------------------- /\nDefense: 100|\nStamina: 50 |\nMana:    50 |\nAttack:  15 |\n------------|\n\n\n";
	
	std::cout << "_______________________________________________________________________________________________________________________________________________\n";
	std::cout << " [WARRIOR]  |\"Warriors are highly trained in the arts of weaponary but mainly uses a {axe} for there main weapon. There can be different types|\n____________| of Warriors, a soldier, a beast handler, a guard, you name it. Basically [a terminator that destroys what it wants]\"            |\n";
	std::cout << "Health:  100|----------------------------------------------------------------------------------------------------------------------------------\nDefense: 80 |\nStamina: 100|\nAttack:  30 |\n------------|\n\n\n";

	std::cout << "______________________________________________________________________________________________________________________________________________\n";
	std::cout << "   [MAGE]   |\"Mages have studied for a long time in the supernatural, they have a lot of knowledge on different creatures potion making, and |\n____________| magical prowess on spellcasting with their {grimoire}, Anything nature related that can disturb the supernatural. Basically    |\n";
	std::cout << "Health:  100|[A person seeking knowledge to break the limits of what a human can do]\" /-------------------------------------------------------\nDefense: 50 |------------------------------------------------------------------------/\nMana: 100   |\nMAttack: 15 |\n------------|\n\n\n\n";

	


	while (typingVocation) {

		std::cout << "[PALADIN]\n[WARRIOR]\n[MAGE]\n\n";

		std::cout << "Choose your class by typing in the [KEYWORDS] at the top\n";

		consoleVocation.ReadFromConsole();

		if (consoleVocation.Uppercase() == paladin) {
			vocationName = paladin;

			 health = 100;
			 defense = 100;
			 stamina = 50;
			 mana = 50;

			 attack = 15;

			areYouSure = true;		
			bufferVocation = consoleVocation.Uppercase();
			bufferYesNo = consoleYesAndNO.Uppercase();
		}
		else if (consoleVocation.Uppercase() == warrior) {
			vocationName = warrior;

			health = 100;
			defense = 80;
			stamina = 100;
			
			attack = 30;

			areYouSure = true;
			bufferVocation = consoleVocation.Uppercase();
			bufferYesNo = consoleYesAndNO.Uppercase();
		}
		else if (consoleVocation.Uppercase() == mage) {
			vocationName = mage;

			health = 100;
			defense = 50;
			
			mana = 100;

			magicAttack = 50;


			areYouSure = true;
			bufferVocation = consoleVocation.Uppercase();
			bufferYesNo = consoleYesAndNO.Uppercase();
		}
		else std::cout << "YOU INPUTED THE WRONG KEYWORDS PLEASE TRY AGAIN\n";

		while (areYouSure) {
			std::cout << "You have chosen " << consoleVocation.CString() << " ...are yu sure?\n";
			std::cout << "Y/N\n";

			consoleYesAndNO.ReadFromConsole();
			if (consoleYesAndNO.Uppercase() == "Y") {
				typingVocation = false;
				areYouSure = false;
			}
			else if (consoleYesAndNO.Uppercase() == "N") {
				areYouSure = false;
			}
		}
		

		
		

	}

	
	consoleVocation = bufferVocation;
	consoleYesAndNO = bufferYesNo;
	std::cout << consoleVocation.CString() << " HAS BEEN SELECTED";
	
    
}
