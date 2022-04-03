#include "OceanViewConsole.h"
#include "Cell.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void OceanViewConsole::SetSize()
{
	int rows, cols;
	cout << "Enter rows (default - 25): ";
	cin >> rows;
	myOcean->SetRows(rows);
	cout << "Enter cols (default - 70): ";
	cin >> cols;
	myOcean->SetCols(cols);
}

void OceanViewConsole::InitCells()
{
	cout << "1. Default\n2. Custom\n -> ";
	int temp;
	cin >> temp;
	switch (temp)
	{
		//default config
	case 1:
		myOcean->SetNumObstacles(DefaultNumObstacles);
		myOcean->SetNumPredators(DefaultNumPredators);
		myOcean->SetNumPrey(DefaultNumPrey);
		myOcean->InitializeDef();
		break;
		//Custom
	case 2:
		int numObstacles,
			numPrey,
			numPredators;

		//TODO: Add exception for ocean overflow 
		//Enter obstacles number
		cout << "\n\nEnter number of obstacles (default = 75): ";
		cout.flush();
		cin >> numObstacles;
		myOcean->SetNumObstacles(numObstacles);
		cout << "\nNumber obstacles accepted = " << numObstacles;
		cout.flush();

		//Enter predators number
		cout << "\n\nEnter number of predators (default = 20): ";
		cout.flush();
		cin >> numPredators;
		if (numPredators == (myOcean->GetSize() - numObstacles))
		{
			numPredators = myOcean->GetSize() - numObstacles;
		}
		myOcean->SetNumPredators(numPredators);
		cout << "\nNumber predators accepted = " << numPredators;
		cout.flush();

		//Enter preys number
		cout << "\n\nEnter number of prey (default = 150): ";
		cout.flush();
		cin >> numPrey;
		if (numPrey == (myOcean->GetSize() - numObstacles - numPredators))
		{
			numPrey = myOcean->GetSize() - numObstacles - numPredators;
		}
		myOcean->SetNumPrey(numPrey);
		cout << "\nNumber prey accepted = " << numPrey << "\n\n";
		cout.flush();

		myOcean->Initialize();
		break;
	}
}

void OceanViewConsole::SetOcean(Ocean* oc)
{
	myOcean = oc;
}

void OceanViewConsole::DisplayCells()
{
	for (int row = 0; row < myOcean->GetNumRows(); row++)
	{
		for (int col = 0; col < myOcean->GetNumCols(); col++)
		{
			if (myOcean->GetCells()[row][col] != nullptr)
			{
				myOcean->GetCells()[row][col]->SetView(this);
				myOcean->GetCells()[row][col]->Display();
			}
			else
			{
				cout << "-";
			}
		}
		cout << "\n";
	}
}

void OceanViewConsole::DisplayStats(int iteration)
{
	cout << "\n\n";
	cout << "Iteration number: " << ++iteration;
	cout << "Obstacles: " << myOcean->GetNumObstacles();
	cout << "Predators: " << myOcean->GetNumPredators();
	cout << "Prey: " << myOcean->GetNumPrey() << "\n";
	cout.flush();
}

void OceanViewConsole::DisplayBorder()
{
	for (int col = 0; col < myOcean->GetNumCols(); col++)
	{
		cout << "*";
	}
	cout << "\n";
}

void OceanViewConsole::Run()
{
	int numIterations = DefaultNumIterations;

	cout << endl << endl << "Enter number of iterations (default max = 1000): ";
	cout.flush();
	cin >> numIterations;

	if (numIterations > 1000)
	{
		numIterations = 1000;
	}

	cout << endl << "Number iterations = " << numIterations << endl << "begin run..." << endl;
	cout.flush();

	for (int i = 0; i < numIterations; i++)
	{
		if (myOcean->GetNumPredators() > 0 && myOcean->GetNumPrey() > 0)
		{
			for (int row = 0; row < myOcean->GetNumRows(); row++)
			{
				for (int col = 0; col < myOcean->GetNumCols(); col++)
				{
					if (myOcean->GetCells()[row][col] != nullptr)
					{
						myOcean->GetCells()[row][col]->SetOcean(myOcean);
						myOcean->GetCells()[row][col]->Process();
					}
				}
			}
			DisplayStats(i);
			DisplayBorder();
			DisplayCells();
			DisplayBorder();
			cout.flush();
			Sleep(1000);
		}
		else
		{
			break;
		}
		cout << endl << endl << "End of Simulation" << endl;
		cout.flush();
	}
	if (myOcean->GetNumPredators() > 0)
	{
		cout << endl << "Predators won";
	}
	else
	{
		cout << endl << "Preys won";
	}
}

void OceanViewConsole::PrintMessage(string str)
{
	cout << str;
}