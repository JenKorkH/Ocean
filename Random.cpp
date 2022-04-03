#include "Random.h"
#include <iostream>

int Random::NextIntBetween(int low, int high)
{
	return abs(rand() % (++high - low)) + low;
}