#include "Ocean.h"
#include "Cell.h"
#include "Prey.h"
#include "Predator.h"
#include "Obstacle.h"
#include "OceanViewConsole.h"
#include <iostream>
using namespace std;

Ocean::Ocean()
{
	random = new Random();
}

Ocean::Ocean(OceanViewer* oc)
{
	oView = oc;
}

Ocean::~Ocean()
{
	for (int i = 0; i < GetNumRows(); i++)
	{
		for (int j = 0; j < GetNumRows(); j++)
		{
			delete cells[i][j];
		}
	}
	delete random;
}

void Ocean::InitializeDef()
{

	numObstacles = DefaultNumObstacles;
	numPredators = DefaultNumPredators;
	numPrey = DefaultNumPrey;

	Initialize();
}

void Ocean::Initialize()
{
	cells = new Cell * *[numRows];
	for (int i = 0; i < numRows; i++)
	{
		cells[i] = new Cell * [numCols];
	}

	size = numRows * numCols;
	AddEmptyCells();
	AddObstacles();
	AddPrey();
	AddPredators();
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			if (cells[row][col] != nullptr)
			{
				cells[row][col]->SetOcean(this);
			}
		}
	}
	oView->DisplayBorder();
	oView->DisplayCells();
	oView->DisplayBorder();
	oView->Run();
}

void Ocean::SetCols(int col)
{
	numCols = col;
}

void Ocean::SetRows(int row)
{
	numRows = row;
}

void Ocean::AddEmptyCells()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			cells[row][col] = nullptr;
		}
	}
}

void Ocean::AddObstacles()
{
	int x = -1;
	int y = -1;
	Coordinate empty;
	for (int count = 0; count < numObstacles; count++)
	{
		empty = GetEmptyCellCoord();
		cells[empty.GetY()][empty.GetX()] = new Obstacle(empty);
	}
}

void Ocean::AddPrey()
{
	Coordinate empty;
	for (int count = 0; count < numPrey; count++)
	{
		empty = GetEmptyCellCoord();
		cells[empty.GetY()][empty.GetX()] = new Prey(empty);
	}
}

void Ocean::AddPredators()
{
	Coordinate empty;
	for (int count = 0; count < numPredators; count++)
	{
		empty = GetEmptyCellCoord();
		cells[empty.GetY()][empty.GetX()] = new Predator(empty);
	}
}

Coordinate Ocean::GetEmptyCellCoord()
{
	int x = -1;
	int y = -1;
	Coordinate empty;
	do
	{
		x = random->NextIntBetween(0, numCols - 1);
		y = random->NextIntBetween(0, numRows - 1);
	} while (cells[y][x] != nullptr);

	empty.SetX(x);
	empty.SetY(y);

	return empty;
}

Cell*** Ocean::GetCells()
{
	return cells;
}

Random* Ocean::GetRandom()
{
	return random;
}

OceanViewer* Ocean::GetView()
{
	return oView;
}

int Ocean::GetNumPrey()
{
	return numPrey;
}

int Ocean::GetSize()
{
	return size;
}

int Ocean::GetNumRows()
{
	return numRows;
}

int Ocean::GetNumCols()
{
	return numCols;
}

int Ocean::GetNumPredators()
{
	return numPredators;
}

int Ocean::GetNumObstacles()
{
	return numObstacles;
}

void Ocean::SetNumObstacles(int oNumber)
{
	numObstacles = oNumber;
}

void Ocean::SetNumPrey(int aNumber)
{
	numPrey = aNumber;
}

void Ocean::SetNumPredators(int aNumber)
{
	numPredators = aNumber;
}
