#include "ChestKey.h"

void ChestKey::Description() const
{
	std::cout << "A key that looks like it can open a something...";
}

void ChestKey::Use()
{
	if (!used) {
		std::cout << "You used the key";
		used = true;
	} else std::cout << "You already used the key";
	
}
