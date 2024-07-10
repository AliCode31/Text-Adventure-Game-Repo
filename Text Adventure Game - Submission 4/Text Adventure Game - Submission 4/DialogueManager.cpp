#include "DialogueManager.h"
#include "String.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>


DialogueManager::DialogueManager(Player* playerptr)
{
	this -> playerPtr = playerptr;

	
}

DialogueManager::~DialogueManager()
{
	
}

void DialogueManager::Contiunue()
{
	//std::cin.ignore();
	std::cout << " - Press SPACEBAR TO Continue\n\n";
	_getch();


}

void DialogueManager::Prologue(int parts)
{
	
	int dialogueNumber = 1;
	String dialogue;
	
	name = playerPtr->playerName;
	if (parts == 1) {
		system("cls");
		String* vocation = playerPtr->vocationName;

		while (dialogueNumber != 15) {
			if (dialogueNumber == 1) {
				dialogue = "You lay on the grass near a tree, lake by your side washing the current down birds chirping, flying past with the wind blowing the leafs.\nYou think about the war 10 years ago, how you nearly lost everything to the orcs.";

			}

			if (dialogueNumber == 2) {

				if (*vocation == "PALADIN") {
					weapon = "Sword";
				}
				if (*vocation == "WARRIOR") {
					weapon = "Axe";
				}

				if (*vocation == "MAGE") {
					weapon = "Grimoire";
				}

				dialogue = "You suddenly hear a branch break near you. Instincts kicking, you grab your {Weapontype} and aim it to whatever broke the branch";
				dialogue.Replace("{Weapontype}", weapon);
			}

			if (dialogueNumber == 3) {
				dialogue = "[???] \"Relax! Relax, I'm not here to hurt you!\"\nSays the stranger";

			}

			if (dialogueNumber == 4) {
				dialogue = "You lower your {Weapontype}";
				dialogue.Replace("{Weapontype}", weapon);

			}

			if (dialogueNumber == 5) {
				dialogue = "[name] \"Careful who you sneak up on\"";
				dialogue.Replace("name", name);

			}

			if (dialogueNumber == 6) {
				dialogue = "[???] \"I know, I won't do it next time\"";


			}

			if (dialogueNumber == 7) {
				dialogue = "[name] \"Why are you here anyway? I thought I told the guild to not disturb me when I'm training\"";
				dialogue.Replace("name", name);

			}

			if (dialogueNumber == 8) {
				dialogue = "[???] \"And is the training where you just sleep by a tree and do nothing?\"";


			}

			if (dialogueNumber == 9) {
				dialogue = "[name] \"You can think what ever you want, again why are you here?\"";
				dialogue.Replace("name", name);

			}

			if (dialogueNumber == 10) {
				dialogue = "[???] \"Reiner wants to discuss somnething with you\"";


			}

			if (dialogueNumber == 11) {
				dialogue = "[name] \"Really Reiner? This must be urgent if he wants to talk\"";
				dialogue.Replace("name", name);

			}

			if (dialogueNumber == 12) {
				dialogue = "[???] \"It is\"";


			}

			if (dialogueNumber == 13) {
				dialogue = "[name] \"alright then give me a few minutes\"";
				dialogue.Replace("name", name);

			}

			if (dialogueNumber == 14) {
				dialogue = "\nYou take a few steps to the river near you sitting down. You start to splash the cold water on your face.\nOnce done you see your reflection in the water face covered with ripples";


			}


			for (int i = 0; dialogue[i] != '\0'; i++) {
				std::cout << dialogue[i];
				Sleep(5);
			}

			Contiunue();
			dialogueNumber++;
		}
	}

	if (parts == 2) {
		while (dialogueNumber != 3) {
			if (dialogueNumber == 1) {
				dialogue = "You get up and walk back to the stranger";
			}

			if (dialogueNumber == 2) {
				dialogue = "[name] \"Let's go\"";
				dialogue.Replace("name", name);

			}

			for (int i = 0; dialogue[i] != '\0'; i++) {
				std::cout << dialogue[i];
				Sleep(5);
			}

			Contiunue();
			dialogueNumber++;
		}

	}
}
