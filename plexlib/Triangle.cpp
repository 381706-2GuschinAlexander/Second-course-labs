#include "Triangle.h"
#include <math.h>

Triangle::Triangle()
{

}

Triangle::Triangle(Point _a, Point _b, Point _c)
{
	a = _a;
	b = _b;
	c = _c;
}

Triangle::Triangle(const Triangle & tri)
{
	a = tri.a;
	b = tri.b;
	c = tri.c;
}

void Triangle::SetA(double x, double y)
{
	a.SetX(x);
	a.SetY(y);
}

void Triangle::SetB(double x, double y)
{
	b.SetX(x);
	b.SetY(y);
}

void Triangle::SetC(double x, double y)
{
	c.SetX(x);
	c.SetY(y);
}

double Triangle::GetX1()
{
	return a.GetX();
}

double Triangle::GetY1()
{
	return a.GetY();
}

double Triangle::GetX2()
{
	return b.GetX();
}

double Triangle::GetY2()
{
	return b.GetY();
}

double Triangle::GetX3()
{
	return c.GetX();
}

double Triangle::GetY3()
{
	return c.GetY();
}

double Triangle::LenAB()
{
	return sqrt( pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
}

double Triangle::LenAC()
{
	return sqrt(pow(a.GetX() - c.GetX(), 2) + pow(a.GetY() - c.GetY(), 2));
}

double Triangle::LenBC()
{
	return sqrt(pow(c.GetX() - b.GetX(), 2) + pow(c.GetY() - b.GetY(), 2));
}
