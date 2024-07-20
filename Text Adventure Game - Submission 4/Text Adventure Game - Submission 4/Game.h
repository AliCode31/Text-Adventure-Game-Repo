#pragma once
#include "Room.h"
#include "Player.h"
#include "DialogueManager.h"
#include "ChestKey.h"
#include "CorridorKey.h"
#include "Crystal.h"
#include "Kobold.h"
#include "Goblin.h"
class Game
{
private: 
	Room* rooms[7];
	ChestKey* chestKey;
	CorridorKey* corridorKey;
	Crystal* crystal;

	Kobold* kobold;
	Goblin* goblins[2];


	bool gameIsRun;


	Player* player;
	DialogueManager* dialogue;
public:

	Game();
	~Game();
public:
	void Run();
	void Dungeon();
	void FightKobold();
	void FightGoblin();
};

