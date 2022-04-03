#include "Predator.h"

void Predator::Process()
{
	Coordinate toCoord;
	if (--timeToFeed <= 0)
	{
		AssignCellAt(offset, nullptr);
		ocean->SetNumPredators(ocean->GetNumPredators() - 1);
		delete this;
	}
	else
	{
		toCoord = GetPreyNeighborCoord();
		if (toCoord != offset)
		{
			ocean->SetNumPrey(ocean->GetNumPrey() - 1);
			timeToFeed = TimeToFeed;
			MoveFrom(offset, toCoord);
		}
		else
		{
			Prey::Process();
		}
	}
}

Cell* Predator::Reproduce(Coordinate anOffset)
{
	Predator* temp = new Predator(anOffset);
	ocean->SetNumPredators(ocean->GetNumPredators());
	return /*(Cell*)*/ temp;
}