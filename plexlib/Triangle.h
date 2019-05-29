#pragma once
#include "Point.h"
class Triangle
{
protected:
	Point a;
	Point b;
	Point c;
public:
	Triangle();
	Triangle(Point _a, Point _b, Point _c);
	Triangle(const Triangle& tri);
	void SetA(double x, double y);
	void SetB(double x, double y);
	void SetC(double x, double y);
	double GetX1();
	double GetY1();
	double GetX2();
	double GetY2();
	double GetX3();
	double GetY3();
	double LenAB();
	double LenAC();
	double LenBC();
};