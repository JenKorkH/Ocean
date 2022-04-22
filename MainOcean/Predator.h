#include "Prey.h"

#pragma once
class Predator : public Prey
{
private:
	virtual Cell* Reproduce(Coordinate anOffset);

protected:
	int timeToFeed;
public:
	Predator(Coordinate aCoord) : Prey(aCoord)
	{
		timeToFeed = TimeToFeed;
		image = DefaultPredImage;
	}

	virtual ~Predator() {}
	void Process();
};