#include "OceanViewer.h"

#pragma once
class OceanViewConsole : public OceanViewer
{
public:
	OceanViewConsole() {};
	void SetSize();
	void InitCells();
	void SetOcean(Ocean*);
	void DisplayCells();
	void DisplayStats(int);
	void DisplayBorder();
	void Run();
	void PrintMessage(string);
};