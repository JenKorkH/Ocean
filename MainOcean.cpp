
#include <iostream>
#include "OceanViewConsole.h"
#include "Ocean.h"
using std::cout;

int main()
{ 
    OceanViewConsole* viewOcean = new OceanViewConsole();
    Ocean* myOcean = new Ocean(viewOcean);
    viewOcean->SetOcean(myOcean);
    viewOcean->SetSize();
    viewOcean->InitCells();

    delete myOcean;
    delete viewOcean;
}
