#include "CorridorKey.h"

void CorridorKey::Description() const
{
	std::cout << "A silver key that has some writing on it, it looks like it can open something";
}

void CorridorKey::Use()
{
	if (!used) {
		std::cout << "You used the silver key";
		used = true;
	} else std::cout << "You already used the silver key";
	
}
