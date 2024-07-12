#pragma once
#include "Item.h"
class Crystal : public Item
{
public:
	void Description() const override;
	void Use() override;
};

