#pragma once
#include "Item.h"
class CorridorKey : public Item
{
	bool used = false;
public: 
	bool isOnPlayer = false;
public:
	void Description() const override;
	void Use() override;
};

