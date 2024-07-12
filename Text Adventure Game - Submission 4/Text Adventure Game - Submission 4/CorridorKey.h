#pragma once
#include "Item.h"
class CorridorKey : public Item
{
public:
	void Description() const override;
	void Use() override;
};

