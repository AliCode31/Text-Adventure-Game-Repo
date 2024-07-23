#pragma once
#include "Item.h"
class Crystal : public Item
{
public:
	bool onPlayer = false;
	bool used = false;
public:
	void Description() const override;
	void Use() override;
};

