#include "Utilities.h"
#include <ctime>
#include <cstdlib>    

Utilities::Utilities()
{
}

Utilities::~Utilities()
{
}

int Utilities::chooseRandom(int numberOfOptions)
{
	srand(time(NULL));
	return uint32_t(rand() *5009) % numberOfOptions;
}
