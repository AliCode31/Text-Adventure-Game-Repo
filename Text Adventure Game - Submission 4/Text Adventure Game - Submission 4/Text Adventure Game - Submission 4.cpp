#include <iostream>
#include "String.h"
#include "player.h"
#include "DialogueManager.h"

int main()
{
  
	Player* player = new Player() ;
	DialogueManager dialogue(player);

	/*player->ChooseName();*/
	//player->playerVocation->ChooseVocation();

	player->SetVocation();

	

	


	if (player->FindSpell("Heal")) {
		std::cout << "It has been found";
	}
	else std::cout << "You don't have that spell";





	/*dialogue.Contiunue();
	dialogue.Prologue(1);
	player->ChooseName();
	dialogue.Prologue(2);*/



	system("pause");

	delete player;


































}

