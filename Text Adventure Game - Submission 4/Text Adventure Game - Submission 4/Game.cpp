#include "Game.h"
#include <iostream>
Game::Game()
{
	gameIsRun = true;

	player = new Player();
	dialogue = new DialogueManager(player);

	chestKey = new ChestKey;
	corridorKey = new CorridorKey;
	crystal = new Crystal;

	
	rooms[0] = new Room("You enter this corridor, mold on the walls, bones on the floor with past creatures or humans. The smell unbearable,\nbut you have a mission and this won't stop you");
	rooms[1] = new Room("You enter this big room with doors in all directions, there is this map on the wall but is scratches by who knows what. You try to read it but can't");
	rooms[2] = new Room("You enter the room. What you see is a desk full of papers scratches and all messed up with some fallen on the floor,\nat the very end is a chest.", chestKey);
	rooms[3] = new Room("You enter the room. You see that everything is messed up and broken. You then find out why everything is destroyed,\nbecause at the corner is a creature you haven't scene in ages... A Kobold", corridorKey);
	rooms[4] = new Room("Template");
	rooms[5] = new Room("Template");
	rooms[6] = new Room("Template", crystal);

}

Game::~Game()
{
	delete player;
	delete dialogue;	
	delete crystal;
	delete corridorKey;
	delete chestKey;
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
		/*dialogue->Prologue(1);
		player->ChooseName();
		dialogue->Prologue(2);
		dialogue->ChapterOne();
		dialogue->IntroToDungeon();
		gameIsRun = false;*/

		/*Dungeon(); */
		player->Hud();
	}

}



void Game::Dungeon()
{
	bool done = false;
	int roomIndex = 0;
	String compass;
	String bufferCompass;
	String north = "NORTH";
	String south = "SOUTH";
	String west = "WEST";
	String neast = "EAST";

	while (!player->Playerisxdead() || !done) {
		
		if (roomIndex == 0) {
			system("cls");
			std::cout << "\n\n";
			rooms[roomIndex]->Description();

			std::cout << "-[Move North]\n\n";
			std::cout << "Type your direction...";
			compass.ReadFromConsole();

			if (compass.Uppercase() == north) {
				roomIndex = 1;
			}			
		}
		if (roomIndex == 1) {
			system("cls");
			std::cout << "\n\n";
			rooms[roomIndex]->Description();

			std::cout << "-[Move North]\n-[Move South]\n-[Move West]\n-[Move East]\n";
			std::cout << "Type your direction...";
			compass.ReadFromConsole();

			if (compass.Uppercase() == north) {
				
			}
			if (compass.Uppercase() == south) {
				roomIndex = 0;
			}

		}










		bufferCompass = compass;
	}
	














	compass = bufferCompass;
}
