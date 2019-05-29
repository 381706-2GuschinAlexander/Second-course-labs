#pragma once
#include "Point.h"

class Line
{
protected:
	Point a;
	Point b;
public:
	Line();
	Line(const Line& line);
	Line(Point _a, Point _b);
	Line(double x1, double y1, double x2, double y2);
	~Line();
	void SetX1(double val);
	void SetY1(double val);
	void SetX2(double val);
	void SetY2(double val);
	double GetX1();
	double GetY1();
	double GetX2();
	double GetY2();
	Point GetA();
	Point GetB();
	bool operator==(const Line& line);
	bool operator!=(const Line& line);
	Line& operator=(const Line& line);
};