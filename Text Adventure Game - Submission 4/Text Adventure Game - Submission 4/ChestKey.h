#pragma once
#include "Item.h"
class ChestKey : public Item
{
public:
	void Description() const override;
	void Use() override;
};

