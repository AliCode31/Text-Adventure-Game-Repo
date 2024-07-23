#include "Crystal.h"

void Crystal::Description() const
{

	std::cout << "A crystal that has some aura around it. It looks like it can do something";
}

void Crystal::Use()
{
	if (!used) {
		std::cout << "You start inspecting the crystal and you start seeing it start to glow bright, it looks like its reacting to your soul\nYou suddenly feel more better and the crystal shatters in a million pieces";
		used = true;
	}
	else std::cout << "Crystal shattered in a million piece, can't do nothing with it";
}
