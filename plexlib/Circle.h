#pragma once
#include "Point.h"

class Circle
{
protected:
	Point c;
	double r;
public:
	Circle();
	Circle(Point _c, double _r);
	Circle(const Circle& circle);
	~Circle();
	void SetC(double x, double y);
	void SetR(double _r);
	double GetR();
	double GetX();
	double GetY();
};