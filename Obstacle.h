#pragma once
#include "Cell.h"
class Obstacle : public Cell
{
public:
	Obstacle(Coordinate& aCoord) : Cell(aCoord)
	{
		image = ObstacleImage;
	}

	virtual ~Obstacle() {}

	void Process()
	{

	}
};

