#include <iostream>
using std::string;

class Ocean;

#pragma once
class OceanViewer
{
protected:
	Ocean* myOcean;
public:
	virtual void SetOcean(Ocean*) = 0;
	virtual void SetSize() = 0;
	virtual void InitCells() = 0;
	virtual void DisplayCells() = 0;
	virtual void DisplayStats(int) = 0;
	virtual void DisplayBorder() = 0;
	virtual void Run() = 0;
	virtual void PrintMessage(string) = 0;
};
