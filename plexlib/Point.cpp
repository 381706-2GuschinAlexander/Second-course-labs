#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double _x, double _y)
{
	x = _x;
	y = _y;
}

Point::Point(const Point & point)
{
	x = point.x;
	y = point.y;
}

Point::~Point()
{
}

void Point::SetX(double _x)
{
	x = _x;
}

void Point::SetY(double _y)
{
	y = _y;
}

double Point::GetX()
{
	return x;
}

double Point::GetY()
{
	return y;
}

bool Point::operator==(const Point & point)
{
	if (x == point.x && y == point.y)
		return true;
	else
		return false;
}

bool Point::operator!=(const Point & point)
{
	if (x != point.x || y != point.y)
		return true;
	else
		return false;
}

Point & Point::operator=(const Point & point)
{
	x = point.x;
	y = point.y;
	return *this;
}

