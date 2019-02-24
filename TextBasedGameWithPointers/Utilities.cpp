#include "Utilities.h"

Utilities::Utilities()
{
}

Utilities::~Utilities()
{
}

int Utilities::chooseRandom(int numberOfOptions)
{
	srand(time(NULL));
	return (rand() * 5009) % numberOfOptions;
}