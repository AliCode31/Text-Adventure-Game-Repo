#pragma once
#include <iostream>
class Item
{
public:
	virtual void Description() const = 0;
	virtual void Use() = 0;
};

