#include "Cell.h"

#pragma once
class Prey : public Cell
{
protected:
	int timeToReproduce;

	void MoveFrom(Coordinate from, Coordinate to);
	virtual Cell* Reproduce(Coordinate anOffset);

public:
	Prey() {}
	Prey(Coordinate& aCoord) :Cell(aCoord)
	{
		timeToReproduce = TimeToReproduce;
		image = DefaultPreyImage;
	}

	virtual ~Prey() {}

	void Process()
	{
		Ocean* temp = ocean;
		Coordinate* toCoord;
		toCoord = GetEmptyCell();
		MoveFrom(offset, *toCoord);
	}
};
