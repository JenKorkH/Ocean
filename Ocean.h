#include "constants.h"
#include "Random.h"
#include "Coordinate.h"
#include "OceanViewer.h"
#include <iostream>
using std::string;

class Cell;
#pragma once
class Ocean
{

private:
	OceanViewer* oView;
	Random* random;
	int size;
	int numPrey;
	int numPredators;
	int numObstacles;
	int numRows;
	int numCols;
	Cell*** cells;

	void AddEmptyCells();
	void AddObstacles();
	void AddPredators();
	void AddPrey();
	Coordinate GetEmptyCellCoord();
public:
	Ocean();
	Ocean(OceanViewer*);
	~Ocean();

	OceanViewer* GetView();
	void SetOcean();
	int GetNumPrey();
	int GetSize();
	int GetNumRows();
	int GetNumCols();
	int GetNumPredators();
	int GetNumObstacles();
	void SetNumObstacles(int);
	void SetNumPrey(int);
	void SetNumPredators(int);
	Cell*** GetCells();
	Random* GetRandom();
	void Initialize();
	void InitializeDef();

	void SetRows(int);
	void SetCols(int);
};