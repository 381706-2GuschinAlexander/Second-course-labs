#pragma once

class Point
{
protected:
	double x;
	double y;
public:
	Point();
	Point(double _x, double _y);
	Point(const Point& point);
	~Point();
	void SetX(double _x);
	void SetY(double _y);
	double GetX();
	double GetY();
	bool operator==(const Point& point);
	bool operator!=(const Point& point);
	Point& operator=(const Point& point);
};