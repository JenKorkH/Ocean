#include "Prey.h"

void Prey::MoveFrom(Coordinate from, Coordinate to)
{
	Cell* toCell;
	--timeToReproduce;
	if (to != from)
	{
		toCell = GetCellAt(to);
		delete toCell;
		SetOffsetCoord(to);
		AssignCellAt(to, this);
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			AssignCellAt(from, Reproduce(from));
		}
		else
		{
			Cell* temp = nullptr;
			AssignCellAt(from, temp);
		}
	}
}

Cell* Prey::Reproduce(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset);
	ocean->SetNumPrey(ocean->GetNumPrey() + 1);
	return (Cell*)temp;
}