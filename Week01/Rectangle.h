#pragma once

#include "Point.h"

class Rectangle
{
private:
	Point* _topLeft;
	Point* _bottomRight;
public:
	Rectangle();

	Rectangle(Point topLeft, Point bottomRight);

	Rectangle(const Rectangle& r);

	~Rectangle();

	Point* TopLeft();

	Point* BottomRight();

	void SetTopLeft(const Point& p);
	
	void SetBottomRight(const Point& p);

	float Perimeter();

	float Area();

	void Info();
};

