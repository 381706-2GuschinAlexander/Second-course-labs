#include "Circle.h"

Circle::Circle()
{
	r = 0;
}

Circle::Circle(Point _c, double _r)
{
	c = _c;
	r = _r;
}

Circle::Circle(const Circle & circle)
{
	r = circle.r;
	c = circle.c;
}

Circle::~Circle()
{
}

void Circle::SetC(double x, double y)
{
	c.SetX(x);
	c.SetY(y);
}

void Circle::SetR(double _r)
{
	r = _r;
}

double Circle::GetR()
{
	return r;
}

double Circle::GetX()
{
	return c.GetX();
}

double Circle::GetY()
{
	return c.GetY();
}
