#include "pch.h"
#include "../MainOcean/Coordinate.cpp"

TEST(CoorGetX, GetX1) {
	Coordinate c(4, 5);
	EXPECT_EQ(4, c.GetX());
}

TEST(CoorGetX, GetX2) {
	Coordinate c(-3, 5);
	EXPECT_EQ(3, c.GetX());
}

TEST(CoorGetY, GetY1) {
	Coordinate c(4, 5);
	EXPECT_EQ(5, c.GetY());
	EXPECT_TRUE(true);
}

TEST(CoorGetY, GetY2) {
	Coordinate c(-3, 0);
	EXPECT_EQ(0, c.GetY());
}

TEST(CoordSetX, SetX){
	Coordinate c;
	c.SetX(10);
	c.SetY(20);
	EXPECT_EQ(10, c.GetX());
}

TEST(CoordSetY, SetY) {
	Coordinate c;
	c.SetX(10);
	c.SetY(20);
	EXPECT_EQ(20, c.GetY());
}

TEST(CoordCtorCopy, CtorCopy) {
	Coordinate c(14, 19);
	Coordinate d(c);
	EXPECT_EQ(c.GetX(), d.GetX());
	EXPECT_EQ(c.GetY(), d.GetY());
}

TEST(CoordCtorSet, CtorSet) {
	Coordinate c(20, 19);
	EXPECT_EQ(20, c.GetX());
	EXPECT_EQ(19, c.GetY());
}

TEST(CoordOperatorAs, OpAs) {
	Coordinate c(20, 19);
	Coordinate d = c;
	EXPECT_EQ(20, c.GetX());
	EXPECT_EQ(19, c.GetY());
}

TEST(CoordOperatorEqual, OpEqual) {
	Coordinate b(5, 10);
	Coordinate l(b);
	EXPECT_EQ(b.GetX(), l.GetX());
	EXPECT_EQ(b.GetY(), l.GetY());
}
