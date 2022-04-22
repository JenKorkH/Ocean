#pragma once
class Coordinate
{
private:
	int x;
	int y;

public:
	Coordinate(int, int);
	Coordinate();
	Coordinate(Coordinate&);

	~Coordinate();

	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);

	void operator= (const Coordinate&);

	int operator== (Coordinate&);

	int operator!=(Coordinate&);
};

