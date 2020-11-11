#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
public:
	static int s_instance_count;
	
private:
	Point* m_topLeft;
	Point* m_bottomRight;
public:
	Rectangle();

	Rectangle(const Point& topLeft, const Point& bottomRight);

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

#endif