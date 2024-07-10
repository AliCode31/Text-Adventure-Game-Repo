#include <iostream>
#include "String.h"
#include "player.h"
#include "DialogueManager.h"

int main()
{
  
	Player* player = new Player() ;
	DialogueManager dialogue(player);

	/*player->ChooseName();*/
	player->playerVocation->ChooseVocation();

	player->SetVocation();

	
	dialogue.Contiunue();
	dialogue.Prologue(1);
	player->ChooseName();
	dialogue.Prologue(2);



	system("pause");

	delete player;


































}

