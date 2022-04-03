#include "Cell.h"
#include <iostream>

Cell::Cell()
{
	image = '-';
	numCols = 0;
	numRows = 0;
	ocean = nullptr;
}

Cell::Cell(Coordinate& aCoord)
	: offset(aCoord)
{
	image = DefaultImage;
}

Cell::~Cell()
{
}

void Cell::Display()
{
	oView->PrintMessage(image);
}

Cell* Cell::North()
{
	int yvalue = (offset.GetY() > 0) ? (offset.GetY() - 1) : (ocean->GetNumRows() - 1);
	if (ocean->GetCells()[yvalue][offset.GetX()] != nullptr)
	{
		return ocean->GetCells()[yvalue][offset.GetX()];
	}
	else
	{
		return nullptr;
	}

}

Cell* Cell::South()
{
	int yvalue = (offset.GetY() + 1) % (ocean->GetNumRows());

	if (ocean->GetCells()[yvalue][offset.GetX()] != nullptr)
	{
		return ocean->GetCells()[yvalue][offset.GetX()];
	}
	else
	{
		return nullptr;
	}
}

Cell* Cell::East()
{
	int xvalue = (offset.GetX() + 1) % (ocean->GetNumCols());
	if (ocean->GetCells()[offset.GetY()][xvalue] != nullptr)
	{
		return ocean->GetCells()[offset.GetY()][xvalue];
	}
	else
	{
		return nullptr;
	}
}

Cell* Cell::West()
{
	int xvalue = (offset.GetX() > 0) ? (offset.GetX() - 1) : (ocean->GetNumCols() - 1);
	if (ocean->GetCells()[offset.GetY()][xvalue] != nullptr)
	{
		return ocean->GetCells()[offset.GetY()][xvalue];
	}
	else
	{
		return nullptr;
	}
}

Cell* Cell::GetNeighborWithImage(string anImage)
{
	Cell* neighbors[4];
	int count = 0;

	if (North() != nullptr)
	{
		if (North()->GetImage() == anImage)
		{
			neighbors[count++] = North();
		}
	}

	if (South() != nullptr)
	{
		if (South()->GetImage() == anImage)
		{
			neighbors[count++] = South();
		}
	}

	if (East() != nullptr)
	{
		if (East()->GetImage() == anImage)
		{
			neighbors[count++] = East();
		}
	}

	if (West() != nullptr)
	{
		if (West()->GetImage() == anImage)
		{
			neighbors[count++] = West();
		}
	}

	if (count == 0)
	{
		return this;
	}
	else
	{
		return neighbors[ocean->GetRandom()->NextIntBetween(0, count - 1)];
	}
}

Coordinate* Cell::GetEmptyCell()
{
	Coordinate* neighbors[4];
	int count = 0;

	if (North() == nullptr)
	{
		int yvalue = (offset.GetY() > 0) ? (offset.GetY() - 1) : (ocean->GetNumRows() - 1);
		neighbors[count++] = new Coordinate(offset.GetX(), yvalue);
	}

	if (South() == nullptr)
	{
		int yvalue = (offset.GetY() + 1) % (ocean->GetNumRows());
		neighbors[count++] = new Coordinate(offset.GetX(), yvalue);
	}

	if (East() == nullptr)
	{
		int xvalue = (offset.GetX() + 1) % (ocean->GetNumCols());
		neighbors[count++] = new Coordinate(xvalue, offset.GetY());
	}

	if (West() == nullptr)
	{
		int xvalue = (offset.GetX() > 0) ? (offset.GetX() - 1) : (ocean->GetNumCols() - 1);
		neighbors[count++] = new Coordinate(xvalue, offset.GetY());
	}

	if (count == 0)
	{
		return new Coordinate(offset.GetX(), offset.GetY());
	}
	else
	{
		return neighbors[ocean->GetRandom()->NextIntBetween(0, count - 1)];
	}
}

Coordinate Cell::GetPreyNeighborCoord()
{
	return GetNeighborWithImage(DefaultPreyImage)->GetOffset();
}

Cell* Cell::GetCellAt(Coordinate aCoord)
{
	return ocean->GetCells()[aCoord.GetY()][aCoord.GetX()];
}

void Cell::AssignCellAt(Coordinate aCoord, Cell* aCell)
{
	ocean->GetCells()[aCoord.GetY()][aCoord.GetX()] = aCell;
}

Coordinate& Cell::GetOffset()
{
	return offset;
}

void Cell::SetOffsetCoord(Coordinate& anOffset)
{
	offset = anOffset;
}

void Cell::SetOffset(int x, int y)
{
	offset.SetX(x); 
	offset.SetY(y);
}

string Cell::GetImage()
{
	return image;
}

Ocean* Cell::GetOcean()
{
	return ocean;
}

void Cell::SetView(OceanViewer* oc)
{
	oView = oc; 
}

void Cell::SetOcean(Ocean* oc)
{
	ocean = oc;
}