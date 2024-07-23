#include "DialogueManager.h"
#include "String.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <tchar.h>

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
				dialogue.Replace("{Weapontype}", weapon.Lowercase());
			}

			if (dialogueNumber == 3) {
				dialogue = "[???] \"Relax! Relax, I'm not here to hurt you!\"\nSays the stranger";

			}

			if (dialogueNumber == 4) {
				dialogue = "You lower your {Weapontype}";
				dialogue.Replace("{Weapontype}", weapon.Lowercase());

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
				Sleep(15);
				PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
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
				Sleep(15);
				PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
			}

			Contiunue();
			dialogueNumber++;
		}

	}
}

void DialogueManager::ChapterOne()
{
	system("cls");
	int dialogueNumber = 1;
	String dialogue;

	while (dialogueNumber != 23) {

		if (dialogueNumber == 1) {
			dialogue = "You walk back into the guild house and see Reiner over by the desk writing some papers\n...Reiner for context is the leader of the Adventurer's Guild\n\n";
		}
		if (dialogueNumber == 2) {
			dialogue = "[name] \"You asked for me?\"\n";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 3) {
			dialogue = "[Reiner] \"Yes, sorry I interrupted your traning but this is urgent\"";
		}
		if (dialogueNumber == 4) {
			dialogue = "[name] \"What's the issue\"\n";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 5) {
			dialogue = "[Reiner] \"Remember the dungeon the guild found on one of its bounty hunts?\"";
		}

		if (dialogueNumber == 6) {
			dialogue = "[name] \"Yes, it was one of the ancient dungeons that the ancient architects built\"";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 7) {
			dialogue = "[Reiner] \"Yeah. Basically we sent some guild members to search the dungeon, and they found in the very depths was....\"";
		}
		if (dialogueNumber == 8) {
			dialogue = "[Reiner] \"A Chimera\"";
		}
		if (dialogueNumber == 9) {
			dialogue = "[name] \"That's urgent, but I don't see why you need me. Chimeras are easy to kill with just 4-5 people you can sent\"";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 10) {
			dialogue = "[Reiner] \"That's the thing, we can't\"";
		}
		if (dialogueNumber == 11) {
			dialogue = "[name] \"Why?\"\n";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 12) {
			dialogue = "[Reiner] \"Its a red chimera. Your familiar with them right?\"";
		}
		if (dialogueNumber == 13) {
			dialogue = "[name] \"Your joking, we killed all the red creatures that the orcs made in the war\"";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 14) {
			dialogue = "[Reiner] \"That's what we thought to, but it's not so hard for one to get away\"";
		}
		if (dialogueNumber == 15) {
			dialogue = "[name] \"The thing I don't get is why didn't we hear about this red chimera earlier\"";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 16) {
			dialogue = "[Reiner] \"Because it was locked in the very last room of the dungeon guarding a chest\"";
		}
		if (dialogueNumber == 17) {
			dialogue = "[name] \"I see...Let me guess, you want me to go there and handle it\"";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 18) {
			dialogue = "[Reiner] \"Your {Weapontype} has a special material that can kill the red creatures. Plus we need to know what's in that chest\"";
			dialogue.Replace("{Weapontype}", weapon.Lowercase());
		}
		if (dialogueNumber == 19) {
			dialogue = "[name] \"Alright fine, fine. I'll get get my gear and head out\"";
			dialogue.Replace("name", name);
		}
		if (dialogueNumber == 20) {
			dialogue = "[Reiner] \"Thank you, do you want me to send some guild members to help you\"";
		}
		if (dialogueNumber == 21) {
			dialogue = "[name] \"Better I do it alone, a red creature is something they can't handle\"";
			dialogue.Replace("name", name);
		}

		if (dialogueNumber == 22) {
			dialogue = "[Reiner] \"Okay, Goodluck\"";
		}

		for (int i = 0; dialogue[i] != '\0'; i++) {

			std::cout << dialogue[i];
			Sleep(15);
			PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
		}
		Contiunue();
		dialogueNumber++;
	}
}

void DialogueManager::IntroToDungeon()
{
	system("cls");
	int dialogueNumber = 1;
	String dialogue;


	while (dialogueNumber != 3) {
		if (dialogueNumber == 1) {
			dialogue = "You walk to the entrance to the dungeon preparing for what's to come, {Weapontype} in your hand you step in\n";
			dialogue.Replace("{Weapontype}", weapon.Lowercase());
		}
		if (dialogueNumber == 2) {
			dialogue = "[name] \"Let's do this!\"\n";
			dialogue.Replace("name", name);
		}

		for (int i = 0; dialogue[i] != '\0'; i++) {

			std::cout << dialogue[i];
			Sleep(15);
			PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
		}
		Contiunue();
		dialogueNumber++;
	}
}

void DialogueManager::AboutToFightKobold()
{
	
 	String dialogue = "\nYou pull at your {Weapontype}, and charge right at the Kobold";
	dialogue.Replace("{Weapontype}", weapon); //weapon.Lowercase());

	std::cout << dialogue.CString();
	Contiunue();
}

void DialogueManager::AboutToFightGoblins()
{

	String dialogue = "\nYou pull at your {Weapontype}, and charge right at the Goblins";
	dialogue.Replace("{Weapontype}", weapon); //weapon.Lowercase());

	std::cout << dialogue.CString();
	Contiunue();
}
void DialogueManager::AboutToFightOrc()
{

	String dialogue = "\nYou pull at your {Weapontype}, and charge right at the Orc";
	dialogue.Replace("{Weapontype}", weapon); //weapon.Lowercase());

	std::cout << dialogue.CString();
	Contiunue();
}
void DialogueManager::FinalBossIsDead()
{
	system("cls");
	int dialogueNumber = 1;
	String dialogue;


	while (dialogueNumber != 6) {
		if (dialogueNumber == 1) {
			dialogue = "You finally kill it, the Chimera drops dead on the ground\n";
		}
		if (dialogueNumber == 2) {
			dialogue = "You stuggle to stand with the amount of fatigue you have, your breathing fast paced\n";
		}
		if (dialogueNumber == 3) {
			dialogue = "You see the Chest that Reiner was talking about and go up to it\n";
		}
		if (dialogueNumber == 4) {
			dialogue = "You then open it....\n";
		}
		if (dialogueNumber == 5) {
			dialogue = "You then become massively shocked on what's in there, what the ancients have been hiding\n";
		}

		for (int i = 0; dialogue[i] != '\0'; i++) {

			std::cout << dialogue[i];
			Sleep(15);
			PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
		}
		Contiunue();
		dialogueNumber++;
	}
}
void DialogueManager::BossStageTwo()
{
	int dialogueNumber = 1;
	String dialogue;


	while (dialogueNumber != 2) {

		if (dialogueNumber == 1) {
			if (*playerPtr->vocationName == "PALADIN") {
				 dialogue = "You sliced of the Chimera's tail, Snake flying of. You see the lion and Goat still alive but the Chimera is still strong\n";
			}
			else if (*playerPtr->vocationName == "WARRIOR") {
				 dialogue = "You chopped of the Chimera's tail, Snake flying of. You see the lion and Goat still alive but the Chimera is still strong\n";

			}
			else if (*playerPtr->vocationName == "MAGE") {
				 dialogue = "You blown of the Chimera's tail, Snake flying of. You see the lion and Goat still alive but the Chimera is still strong\n";
				 dialogue.Replace("{Weapontype}", weapon.Lowercase());
			} 
		}

		for (int i = 0; dialogue[i] != '\0'; i++) {

			std::cout << dialogue[i];
			Sleep(15);
			PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
		}
		Contiunue();
		dialogueNumber++;
	}
}
void DialogueManager::BossStageThird()
{
	int dialogueNumber = 1;
	String dialogue;

	while (dialogueNumber != 3) {
	
		if (dialogueNumber == 1) {
			if (*playerPtr->vocationName == "PALADIN") {
				 dialogue = "You sliced of the Goat's head, Goats head fallen to the ground. With the Snake and Goat dead, its only the Lion left\nYou clench your {Weapontype} more firm\n";
				 dialogue.Replace("{Weapontype}", weapon.Lowercase());
			}
			else if (*playerPtr->vocationName == "WARRIOR") {
				 dialogue = "You chopped of the Goat's head, Goats head fallen to the ground. With the Snake and Goat dead, its only the Lion left\nYou clench your {Weapontype} more firm\n";
				 dialogue.Replace("{Weapontype}", weapon.Lowercase());
			}
			else if (*playerPtr->vocationName == "MAGE") {
				 dialogue = "You Blown of the Goat's head, Goats head fallen to the ground. With the Snake and Goat dead, its only the Lion left\nYou clench your {Weapontype} more firm\n";
				 dialogue.Replace("{Weapontype}", weapon.Lowercase());
			}
		}
		if (dialogueNumber == 2) {
			dialogue = "[name] \"Why are you so stubborn...JUST DIE!\"\n";
			dialogue.Replace("name", name);
		}

		for (int i = 0; dialogue[i] != '\0'; i++) {

			std::cout << dialogue[i];
			Sleep(15);
			PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
		}
		Contiunue();
		dialogueNumber++;
	}
}
void DialogueManager::AboutToFightBossStageOne()
{
	system("cls");
	int dialogueNumber = 1;
	String dialogue;


	while (dialogueNumber != 7) {
		if (dialogueNumber == 1) {
			dialogue = "You open the big doors and walk into this big room. Pitch black, not being able to see nothing\n";
		}
		if (dialogueNumber == 2) {
			dialogue = "Then suddenly the lights turn on in the room and you see it...\n";
		}
		if (dialogueNumber == 3) {
			dialogue = "What Reiner was telling you about, what you fought in the war years ago, The Red Chimera\n";
		}
		if (dialogueNumber == 4) {
			dialogue = "A Lion as the base of the body with a Goat head sticking out and with the tail as a Snake, with the Snake head at the end of the tail\ngetting ready to bite\n";
		}
		if (dialogueNumber == 5) {
			dialogue = "You know what you gotta do..\n";
		}
		if (dialogueNumber == 6) {
			dialogue = "[name] \"We meet again...\"\n";
			dialogue.Replace("name", name);
		}

		for (int i = 0; dialogue[i] != '\0'; i++) {

			std::cout << dialogue[i];
			Sleep(15);
			PlaySound(_T("Typewriter.wav"), NULL, SND_ASYNC);
		}
		Contiunue();
		dialogueNumber++;
	}
}
