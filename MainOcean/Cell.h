#include "Ocean.h"

#pragma once
class Cell
{
protected:
	Ocean* ocean;
	OceanViewer* oView;
	Coordinate offset;
	string image;
	int numRows;
	int numCols;
	int finish = 0;

	Cell* GetCellAt(Coordinate);
	void AssignCellAt(Coordinate, Cell*);
	Cell* GetNeighborWithImage(string);
	Coordinate* GetEmptyCell();
	Coordinate GetPreyNeighborCoord();

	Cell* North();
	Cell* South();
	Cell* East();
	Cell* West();
public:
	Cell();
	Cell(Coordinate&);
	virtual ~Cell();

	Coordinate& GetOffset();
	void SetOffsetCoord(Coordinate&);
	void SetOffset(int, int);

	string GetImage();
	Ocean* GetOcean();
	int GetFinish();
	void SetView(OceanViewer*);
	void SetOcean(Ocean*);
	void SetFinish(int);
	virtual void Display();
	virtual void Process() = 0;
};
