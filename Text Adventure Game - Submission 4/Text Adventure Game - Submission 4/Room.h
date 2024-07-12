#pragma once
#include "Item.h"
#include "String.h"

class Room
{
private:
    String description;
    
public:
    Item* item;

public: 
    Room();
    Room(String descript);
    Room(String descript, Item* item);
    Room(String descript, Item* item, Item* itemTwo);

   ~Room();
public:
   const void Description(); 
   const void DescriptionWithItem();


};

