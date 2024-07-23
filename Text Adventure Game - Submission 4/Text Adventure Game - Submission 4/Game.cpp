#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <cstdlib>
Game::Game()
{
	gameIsRun = true;

	player = new Player();
	dialogue = new DialogueManager(player);

	chestKey = new ChestKey;
	corridorKey = new CorridorKey;
	crystal = new Crystal;

	kobold = new Kobold;
	goblins[0] = new Goblin;
	goblins[1] = new Goblin;
	orc = new Orc;
	redChimera = new RedChimera;


	
	rooms[0] = new Room("You enter this corridor, mold on the walls, bones on the floor with past creatures or humans. The smell unbearable,\nbut you have a mission and this won't stop you");
	rooms[1] = new Room("You enter this big room with doors in all directions, there is this map on the wall but is scratches by who knows what. You try to read it but can't", corridorKey);
	rooms[2] = new Room("You enter the room. What you see is a desk full of papers scratches and all messed up with some fallen on the floor, at the\n very end is a chest.", chestKey, corridorKey);
	rooms[3] = new Room("You enter the room. You see that everything is messed up and broken.", chestKey);
	rooms[4] = new Room("You enter this corridor, more blood on the walls and dead bodies in the distane, smell being unbearable");
	rooms[5] = new Room("You continue down the corridor smell still unbearable");
	rooms[6] = new Room("Template", crystal);

}

Game::~Game()
{
	delete player;
	delete dialogue;	
	delete crystal;
	delete corridorKey;
	delete chestKey;


	delete kobold;
	delete goblins[0];
	delete goblins[1];
	delete orc;
	delete redChimera;

	delete rooms[0];
	delete rooms[1];
	delete rooms[2];
	delete rooms[3];
	delete rooms[4];
	delete rooms[5];
	delete rooms[6];
}

void Game::Run()
{
	while (gameIsRun) {

		player->playerVocation->ChooseVocation();
		player->SetVocation();

		dialogue->Contiunue();
		dialogue->Prologue(1);
		player->ChooseName();
		dialogue->Prologue(2);
		dialogue->ChapterOne();
		dialogue->IntroToDungeon();
		Dungeon(); 
		gameIsRun = false;
	}

}



void Game::Dungeon()
{
	//WIP
	bool done = false;
	bool lockedChest = true;
	bool lockedDoor = true;

	int roomIndex = 0;
	String compass;
	String bufferCompass ="";
	String north = "NORTH";
	String south = "SOUTH";
	String west = "WEST";
	String east = "EAST";

	while (!player->Playerisxdead() && !done) {
		if (roomIndex == 0) {
			system("cls");
			player->Hud();
			rooms[roomIndex]->Description();

			std::cout << "-Move[North]\n\n";
			std::cout << "Type your direction...";
			compass.ReadFromConsole();

			if (compass.Uppercase() == north) {
				roomIndex = 1;
			}			
		}
		if (roomIndex == 1) {
			system("cls");
			player->Hud();
			rooms[roomIndex]->Description();
			if (corridorKey->isOnPlayer) {
				std::cout << "-Move[North]\n-Move[South]\n-Move{West]\n-Move[East]\n\n1 [Open North door]\n\n";
				std::cout << "Type your direction...";
			}
			else {
				std::cout << "-Move[North]\n-Move[South]\n-Move{West]\n-Move[East]\n";
				std::cout << "Type your direction...";
			}
			compass.ReadFromConsole();

			if (compass.Uppercase() == "1") {
				std::cout << "\n\n";
				corridorKey->Use();
				lockedDoor = false;
				dialogue->Contiunue();
			}

			if (compass.Uppercase() == north) {
				if (lockedDoor) {
					std::cout << "Can't go to next room since the door is locked";
					dialogue->Contiunue();
				}
				else roomIndex = 4;
				
			}
			if (compass.Uppercase() == south) {
				roomIndex = 0;
			}

			if (compass.Uppercase() == west) {
				roomIndex = 2;
			}
			if (compass.Uppercase() == east) {
				roomIndex = 3;
			}
		}
		if (roomIndex == 2) {
			
			system("cls");
			player->Hud();
			rooms[roomIndex]->Description();

			std::cout << "-Move[East]\n\n";
			std::cout << "1 [Open Chest]\n\n";
			if (chestKey->onPlayer) {
				std::cout << "2 [Use Key]\n\n";
			}

			std::cout << "Type your input...";
			compass.ReadFromConsole();

			if (compass.Uppercase() == east) {
				roomIndex = 1;
			}
			if (compass.Uppercase() == "1") {
				if (lockedChest) { 
			    std::cout << "\nCAN'T OPEN CHEST ";
				dialogue->Contiunue(); 
				}
				else {
					if (!corridorKey->isOnPlayer) {
						std::cout << "\nYou open the chest and only see some hieroglyphs written on some papers. You look deep into the chest and find\n";
						corridorKey->Description();
						corridorKey->isOnPlayer = true;
						dialogue->Contiunue();
					}
					else {
						std::cout << "\nYou already looked in this chest\n";
						dialogue->Contiunue();
					}
				}
			}
			if (compass.Uppercase() == "2") {
					std::cout << "\n\n";
					chestKey->Use();
					lockedChest = false;
					dialogue->Contiunue();
				
			}
		
		}
		if (roomIndex == 3) {
			system("cls");
			player->Hud();
			rooms[roomIndex]->Description();
			if (!kobold->KoboldIsDead()) {
				std::cout << "You then find out why everything is destroyed, because at the corner\nis a creature you haven't scene in ages... A Kobold\n\n";
				std::cout << "-Move[West]\n\n";
				std::cout << "1 [Fight]\n\n";

			}
			else {
				std::cout << "You see the kobold dead on the ground\n\n";
				std::cout << "-Move[West]\n\n";
			}

		
			std::cout << "Type your direction...";
			compass.ReadFromConsole();

			if (compass.Uppercase() == west) {
				roomIndex = 1;
			}

			if (compass.Uppercase() == "1") {
				FightKobold();
			}
		}
		if (roomIndex == 4) {
			system("cls");
			player->Hud();
			rooms[roomIndex]->Description();
			if (!goblins[0]->GoblinIsDead() && !goblins[1]->GoblinIsDead()) {
				std::cout << "You then See two figures in the distance walking up to you laughing. The laughs you know all two well... Goblins!\n\n";
				std::cout << "-Move[South]\n\n";
				std::cout << "1 [Fight]\n\n";
			}
			else {
				std::cout << "You see the dead goblins on the ground\n\n";

				std::cout << "-Move[East]\n";
				std::cout << "-Move[South]\n\n";
			}

			std::cout << "Type your direction...";
			compass.ReadFromConsole();

			if (compass.Uppercase() == east) {
				roomIndex = 5;
			}
			if (compass.Uppercase() == south) {
				roomIndex = 1;
			}
			if (compass.Uppercase() == "1") {
				FightGoblin();
			}
		}

		if (roomIndex == 5) {
			system("cls");
			player->Hud();
			rooms[roomIndex]->Description();
			if (!orc->OrcIsDead()) {
				std::cout << "You stop of all of a sudden on what you see...a Orc, looking down on you smilling raising its axe\n\n";
				std::cout << "-Move[South]\n\n";
				std::cout << "1 [Fight]\n\n";
			}
			else {
				std::cout << "You see the dead Orc on the ground\n\n";

				std::cout << "-Move[East](To Open Big Door)\n";
				std::cout << "-Move[West]\n\n";
				std::cout << "2 [Use Crystal]\n\n";
			}

			std::cout << "Type your direction...";
			compass.ReadFromConsole();

			if (compass.Uppercase() == east) {
				roomIndex = 6;
			}
			if (compass.Uppercase() == west) {
				roomIndex = 4;
			}
			if (compass.Uppercase() == "1") {
				FightOrc();
			}
			if (compass.Uppercase() == "2") {
				if (!crystal->used) {
					crystal->Use();
					player->SetVocation();
					dialogue->Contiunue();
				}
				else {
					crystal->Use();
					dialogue->Contiunue();
				}			
			}
		}

		if (roomIndex == 6) {
			FightRedChimera();
		}



		bufferCompass = compass;
	}
	
	compass = bufferCompass;
}

void Game::FightKobold()
{
	dialogue->AboutToFightKobold();
	String action;
	String bufferAction = "";
	while (!player->Playerisxdead() && !kobold->KoboldIsDead()) {
		
		system("cls");
		player->Hud();

		std::cout << "\n\n\n\n\n\n";

		if (*player->vocationName == "PALADIN") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"         4:Blade of Faith        \"Increases attack damage\"          |\n";
			std::cout << "| 2: Block \"Blocks the attack\"    5:Blade of Truth \"Summons a bunch of swords, then attacks\" |\n";      
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Clemency \"Uses your Paladin oath to heal yourself\"                                      |\n";
         	std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "WARRIOR") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"              4:Whirlwind \"you swing your axe around in a circle\"   |\n";
			std::cout << "| 2: Block \"Blocks the attack\"                                                               |\n";
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Bloodlust \"Resets stamina back to normal and increases attack damage while healing\"     |\n";
			std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "MAGE") {
			std::cout << "__________________________________________________________________________________________\n";
			std::cout << "| 1: Energy Blast \"Basic attack\"                                                         |\n";
			std::cout << "| 2: Magic Shield \"Blocks the attack\"                                                    |\n";
			std::cout << "| 3: Heal \"Heal Yourself\"                                                                |\n";
			std::cout << "| 4: Concentrate \"Increases the magic attack damage\"                                     |\n";
			std::cout << "------------------------------------------------------------------------------------------\n\n";
		}

		std::cout << "The Kobold's eyes lock on you getting ready to attack\n\n";
		
		std::cout << "Type your Action...";
		action.ReadFromConsole();
		
		//Swing
		std::cout << "\n";
		if (*player->vocationName == "PALADIN") {
			if (action == "1") {
				kobold->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}
			if (action == "3") {
				player->CastSpell("Clemency");
			}
			if (action == "4") {
				player->CastSpell("Blade of Faith");
			}
			if (action == "5") {
				kobold->TakeDamage(player->CastSpell("Blade of Truth"));
			}
		}

		if (*player->vocationName == "WARRIOR") {
			if (action == "1") {
				kobold->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}	
			if (action == "3") {
				player->CastSpell("Bloodlust");
			}
			if (action == "4") {
				kobold->TakeDamage(player->CastSpell("Whirlwind"));
			}
		}

		if (*player->vocationName == "MAGE") {
			if (action == "1") {
				kobold->TakeDamage(player->CastSpell("Energy Blast"));
			}
			if (action == "2") {
				player->CastSpell("Magic Shield");
			}
			if (action == "3") {
				player->CastSpell("Heal");
			}
			if (action == "4") {
				player->CastSpell("Concentrate");
			}
		}

		std::cout << "\n\n";
		//_____________________________________________________________
		Sleep(500);
		player->TakeDamage(kobold->Swing());
		//--------------------------------------------------------------
		
		player->Buffs();
		dialogue->Contiunue();

		if (player->Playerisxdead()) {
			system("cls");
			std::cout << "(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n\n";
			dialogue->Contiunue();
			exit(0);
		}


		if (kobold->KoboldIsDead()) {
			system("cls");
			std::cout << "(========KOBOLD IS DEAD========)";
			dialogue->Contiunue();
		}

		bufferAction = action;
		action = bufferAction;
	}

	
	std::cout <<"\n\nYou killed the kobol and looted it you found\n";  
	chestKey->Description();
	dialogue->Contiunue();
	chestKey->onPlayer = true;
	system("cls");
}


void Game::FightGoblin()
{
	dialogue->AboutToFightGoblins();
	String action;
	String bufferAction = "";
	while (!player->Playerisxdead() && !goblins[0]->GoblinIsDead() && !goblins[1]->GoblinIsDead()) {

		system("cls");
		player->Hud();

		std::cout << "\n\n\n\n\n\n";

		if (*player->vocationName == "PALADIN") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"         4:Blade of Faith        \"Increases attack damage\"          |\n";
			std::cout << "| 2: Block \"Blocks the attack\"    5:Blade of Truth \"Summons a bunch of swords, then attacks\" |\n";
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Clemency \"Uses your Paladin oath to heal yourself\"                                      |\n";
			std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "WARRIOR") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"              4:Whirlwind \"you swing your axe around in a circle\"   |\n";
			std::cout << "| 2: Block \"Blocks the attack\"                                                               |\n";
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Bloodlust \"Resets stamina back to normal and increases attack damage while healing\"     |\n";
			std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "MAGE") {
			std::cout << "__________________________________________________________________________________________\n";
			std::cout << "| 1: Energy Blast \"Basic attack\"                                                         |\n";
			std::cout << "| 2: Magic Shield \"Blocks the attack\"                                                    |\n";
			std::cout << "| 3: Heal \"Heal Yourself\"                                                                |\n";
			std::cout << "| 4: Concentrate \"Increases the magic attack damage\"                                     |\n";
			std::cout << "------------------------------------------------------------------------------------------\n\n";
		}

		std::cout << "The see Goblins laughing playing with their Falchion \n\n";

		std::cout << "Type your Action...";
		action.ReadFromConsole();

		//Swing
		std::cout << "\n";
		if (*player->vocationName == "PALADIN") {
			if (action == "1") {
				goblins[0]->TakeDamage(player->CastSpell("Swing"));
				std::cout << "\n";
				goblins[1]->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}
			if (action == "3") {
				player->CastSpell("Clemency");
			}
			if (action == "4") {
				player->CastSpell("Blade of Faith");
			}
			if (action == "5") {
				goblins[0]->TakeDamage(player->CastSpell("Blade of Truth"));
				std::cout << "\n";
				goblins[1]->TakeDamage(player->CastSpell("Blade of Truth"));
			}
		}

		if (*player->vocationName == "WARRIOR") {
			if (action == "1") {
				goblins[0]->TakeDamage(player->CastSpell("Swing"));
				std::cout << "\n";
				goblins[1]->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}
			if (action == "3") {
				player->CastSpell("Bloodlust");
			}
			if (action == "4") {
				goblins[0]->TakeDamage(player->CastSpell("Whirlwind"));
				std::cout << "\n";
				goblins[1]->TakeDamage(player->CastSpell("Whirlwind"));
			}
		}

		if (*player->vocationName == "MAGE") {
			if (action == "1") {
				goblins[0]->TakeDamage(player->CastSpell("Energy Blast"));
				std::cout << "\n";
				goblins[1]->TakeDamage(player->CastSpell("Energy Blast"));
			}
			if (action == "2") {
				player->CastSpell("Magic Shield");
			}
			if (action == "3") {
				player->CastSpell("Heal");
			}
			if (action == "4") {
				player->CastSpell("Concentrate");
			}
		}

		std::cout << "\n\n";
		//_____________________________________________________________
		Sleep(500);
		player->TakeDamage(goblins[0]->Swing() + goblins[1]->Swing());
		//--------------------------------------------------------------

		player->Buffs();
		dialogue->Contiunue();

		if (player->Playerisxdead()) {
			system("cls");
			std::cout << "(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n\n";
			dialogue->Contiunue();
			exit(0);
		}

		if (goblins[0]->GoblinIsDead() && goblins[1]->GoblinIsDead()) {
			system("cls");
			std::cout << "(========GOBLIN IS DEAD========) (========GOBLIN IS DEAD========) ";
			dialogue->Contiunue();
		}

		bufferAction = action;
		action = bufferAction;
	}


	std::cout << "\n\nYou killed the Goblins then make your way to the end on the corridor\n";
	dialogue->Contiunue();
	chestKey->onPlayer = true;
	system("cls");
}

void Game::FightOrc()
{
	dialogue->AboutToFightOrc();
	String action;
	String bufferAction = "";
	while (!player->Playerisxdead() && !orc->OrcIsDead()) {

		system("cls");
		player->Hud();

		std::cout << "\n\n\n\n\n\n";

		if (*player->vocationName == "PALADIN") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"         4:Blade of Faith        \"Increases attack damage\"          |\n";
			std::cout << "| 2: Block \"Blocks the attack\"    5:Blade of Truth \"Summons a bunch of swords, then attacks\" |\n";
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Clemency \"Uses your Paladin oath to heal yourself\"                                      |\n";
			std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "WARRIOR") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"              4:Whirlwind \"you swing your axe around in a circle\"   |\n";
			std::cout << "| 2: Block \"Blocks the attack\"                                                               |\n";
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Bloodlust \"Resets stamina back to normal and increases attack damage while healing\"     |\n";
			std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "MAGE") {
			std::cout << "__________________________________________________________________________________________\n";
			std::cout << "| 1: Energy Blast \"Basic attack\"                                                         |\n";
			std::cout << "| 2: Magic Shield \"Blocks the attack\"                                                    |\n";
			std::cout << "| 3: Heal \"Heal Yourself\"                                                                |\n";
			std::cout << "| 4: Concentrate \"Increases the magic attack damage\"                                     |\n";
			std::cout << "------------------------------------------------------------------------------------------\n\n";
		}

		std::cout << "You see the Orc looking down on you getting ready to swing their axe \n\n";

		std::cout << "Type your Action...";
		action.ReadFromConsole();

		//Swing
		std::cout << "\n";
		if (*player->vocationName == "PALADIN") {
			if (action == "1") {
				orc->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}
			if (action == "3") {
				player->CastSpell("Clemency");
			}
			if (action == "4") {
				player->CastSpell("Blade of Faith");
			}
			if (action == "5") {
				orc->TakeDamage(player->CastSpell("Blade of Truth"));
			}
		}

		if (*player->vocationName == "WARRIOR") {
			if (action == "1") {
				orc->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}
			if (action == "3") {
				player->CastSpell("Bloodlust");
			}
			if (action == "4") {
				orc->TakeDamage(player->CastSpell("Whirlwind"));
			}
		}

		if (*player->vocationName == "MAGE") {
			if (action == "1") {
				orc->TakeDamage(player->CastSpell("Energy Blast"));
			}
			if (action == "2") {
				player->CastSpell("Magic Shield");
			}
			if (action == "3") {
				player->CastSpell("Heal");
			}
			if (action == "4") {
				player->CastSpell("Concentrate");
			}
			
		}
			std::cout << "\n\n";
			//_____________________________________________________________
			Sleep(500);
			player->TakeDamage(orc->Swing());
			//--------------------------------------------------------------

			player->Buffs();
			dialogue->Contiunue();

			if (player->Playerisxdead()) {
				system("cls");
				std::cout << "(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n\n";
				dialogue->Contiunue();
				exit(0);
			}

			if (orc->OrcIsDead()) {
				system("cls");
				std::cout << "(========ORC IS DEAD========)";
				dialogue->Contiunue();
			}

			bufferAction = action;
			action = bufferAction;
		
	}
	std::cout << "\n\nYou killed the Orc and looted it you found\n";
	dialogue->Contiunue();
	crystal->Description();
	crystal->onPlayer = true;
	dialogue->Contiunue();
	system("cls");
}

void Game::FightRedChimera()
{
	dialogue->AboutToFightBossStageOne();
	String action;
	String bufferAction = "";
	bool stageTwoDialogue = true;
	bool stageThirdDialogue = true;
	while (!player->Playerisxdead() && !redChimera->RedChimeraIsDead()) {

		system("cls");
		player->Hud();

		std::cout << "\n\n\n\n\n\n";

		if (*player->vocationName == "PALADIN") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"         4:Blade of Faith        \"Increases attack damage\"          |\n";
			std::cout << "| 2: Block \"Blocks the attack\"    5:Blade of Truth \"Summons a bunch of swords, then attacks\" |\n";
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Clemency \"Uses your Paladin oath to heal yourself\"                                      |\n";
			std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "WARRIOR") {
			std::cout << "______________________________________________________________________________________________\n";
			std::cout << "| 1: Swing \"Basic attack\"              4:Whirlwind \"you swing your axe around in a circle\"   |\n";
			std::cout << "| 2: Block \"Blocks the attack\"                                                               |\n";
			std::cout << "|                                                                                            |\n";
			std::cout << "| 3: Bloodlust \"Resets stamina back to normal and increases attack damage while healing\"     |\n";
			std::cout << "----------------------------------------------------------------------------------------------\n\n";
		}

		if (*player->vocationName == "MAGE") {
			std::cout << "__________________________________________________________________________________________\n";
			std::cout << "| 1: Energy Blast \"Basic attack\"                                                         |\n";
			std::cout << "| 2: Magic Shield \"Blocks the attack\"                                                    |\n";
			std::cout << "| 3: Heal \"Heal Yourself\"                                                                |\n";
			std::cout << "| 4: Concentrate \"Increases the magic attack damage\"                                     |\n";
			std::cout << "------------------------------------------------------------------------------------------\n\n";
		}
		if (redChimera->StageOne()) {
			std::cout << "You see the Chimera's eyes on you, getting ready to pounce\n\n";
		}
		else if (redChimera->StageTwo()) {
			if (stageTwoDialogue) {
				stageTwoDialogue = false;
				dialogue->BossStageTwo();
				std::cout << "\n\n";
			}
			else {
				std::cout << "You see the Chimera without its tail still strong\n\n";
			}
			
		}
		else if (redChimera->StageThird()) {
			if (stageThirdDialogue) {			
				stageThirdDialogue = false;
				dialogue->BossStageThird();		
				std::cout << "\n\n";
			}
			else {
				std::cout << "You see The Chimera battered, with the Snake and Goat dead, its grows significantly weak.\n\n";
			}
			
		}



		std::cout << "Type your Action...";
		action.ReadFromConsole();

		//Swing
		std::cout << "\n";
		if (*player->vocationName == "PALADIN") {
			if (action == "1") {
				redChimera->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}
			if (action == "3") {
				player->CastSpell("Clemency");
			}
			if (action == "4") {
				player->CastSpell("Blade of Faith");
			}
			if (action == "5") {
				redChimera->TakeDamage(player->CastSpell("Blade of Truth"));
			}
		}

		if (*player->vocationName == "WARRIOR") {
			if (action == "1") {
				redChimera->TakeDamage(player->CastSpell("Swing"));
			}
			if (action == "2") {
				player->CastSpell("Block");
			}
			if (action == "3") {
				player->CastSpell("Bloodlust");
			}
			if (action == "4") {
				redChimera->TakeDamage(player->CastSpell("Whirlwind"));
			}
		}

		if (*player->vocationName == "MAGE") {
			if (action == "1") {
				redChimera->TakeDamage(player->CastSpell("Energy Blast"));
			}
			if (action == "2") {
				player->CastSpell("Magic Shield");
			}
			if (action == "3") {
				player->CastSpell("Heal");
			}
			if (action == "4") {
				player->CastSpell("Concentrate");
			}

		}
		std::cout << "\n\n";
		//_____________________________________________________________
		Sleep(500);
		player->TakeDamage(redChimera->ChimeraMoveSet());
		//--------------------------------------------------------------

		player->Buffs();
		dialogue->Contiunue();

		if (player->Playerisxdead()) {
			system("cls");
			std::cout << "(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n(========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========) (========YOU ARE DEAD!!!!!========)\n\n";
			dialogue->Contiunue();
			exit(0);
		}

		if (redChimera->RedChimeraIsDead()) {
			system("cls");
			std::cout << "(========CHIMERA IS DEAD========) (========CHIMERA IS DEAD========) (========CHIMERA IS DEAD========)\n(========CHIMERA IS DEAD========) (========CHIMERA IS DEAD========) (========CHIMERA IS DEAD========)\n(========CHIMERA IS DEAD========) (========CHIMERA IS DEAD========) (========CHIMERA IS DEAD========) ";
			dialogue->Contiunue();
		}

		bufferAction = action;
		action = bufferAction;
	}

	dialogue->FinalBossIsDead();
	std::cout << "\n\n(TO BE CONTINUED!!!)";
	dialogue->Contiunue();
	exit(0);
	
}

