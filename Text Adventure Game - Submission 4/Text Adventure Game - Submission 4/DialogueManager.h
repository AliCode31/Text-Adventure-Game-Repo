#pragma once
#include "Player.h"
class DialogueManager 
{
    Player* playerPtr;
   
public:
    String weapon;
    String name;

public:
    DialogueManager(Player* playerptr);
    ~DialogueManager();

public:

    void Contiunue();
    void Prologue(int parts);
    void ChapterOne();
    void IntroToDungeon();
    void AboutToFight();



};

