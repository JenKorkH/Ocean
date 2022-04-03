#include "Coordinate.h"
Coordinate::Coordinate(int aX, int aY) :
	x(aX), 
	y(aY) {}

Coordinate::Coordinate() 
{ 
	x = 0; 
	y = 0; 
}
Coordinate::Coordinate(Coordinate& aCoord)
{
	x = aCoord.x;
	y = aCoord.y;
}

Coordinate::~Coordinate() 
{
}

int Coordinate::GetX() 
{ 
	return x; 
}
int Coordinate::GetY() 
{ 
	return y; 
}
void Coordinate::SetX(int aX) 
{ 
	x = aX; 
}
void Coordinate::SetY(int aY) 
{ 
	y = aY; 
}

void Coordinate::operator= (const Coordinate& aCoord)
{
	x = aCoord.x;
	y = aCoord.y;
}

int Coordinate::operator== (Coordinate& c)
{
	return(x == c.x && y == c.y);
}

int Coordinate::operator!=(Coordinate& c)
{
	return(x != c.x || y != c.y);
}