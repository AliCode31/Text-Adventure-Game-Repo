#include "ChestKey.h"

void ChestKey::Description() const
{
	std::cout << "A key that looks like it can open a something...";
}

void ChestKey::Use()
{
	std::cout << "You used the key on the chest";
}
