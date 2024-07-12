#pragma once
#include "Item.h"
class ChestKey : public Item
{
public:
	bool onPlayer = false;
public:
	void Description() const override;
	void Use() override;
};

