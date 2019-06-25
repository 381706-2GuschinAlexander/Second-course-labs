#include "Line.h"

Line::Line()
{
	
}

Line::Line(const Line & line)
{
	a = line.a;
	b = line.b;
}

Line::Line(Point _a, Point _b)
{
	a = _a;
	b = _b;
}

Line::Line(double x1, double y1, double x2, double y2)
{
	a.SetX(x1);
	a.SetY(y1);
	b.SetX(x2);
	b.SetY(y2);
}

Line::~Line()
{
}

void Line::SetX1(double val)
{
	a.SetX(val);
}

void Line::SetY1(double val)
{
	a.SetY(val);
}

void Line::SetX2(double val)
{
	b.SetX(val);
}

void Line::SetY2(double val)
{
	b.SetY(val);
}

double Line::GetX1()
{
	return a.GetX();
}

double Line::GetY1()
{
	return a.GetY();
}

double Line::GetX2()
{
	return b.GetX();
}

double Line::GetY2()
{
	return b.GetY();
}

Point Line::GetA()
{
	return a;
}

Point Line::GetB()
{
	return b;
}

bool Line::operator==(const Line & line)
{
	if (a == line.a && b == line.b)
		return true;
	else
		return false;
}

bool Line::operator!=(const Line & line)
{
	if (a != line.a || b != line.b)
		return true;
	else
		return false;
}

Line & Line::operator=(const Line & line)
{
	a = line.a;
	b = line.b;
	return *this;
}
