#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
public:
	static int s_instance_count;
	
private:
	Point* m_top_left;
	Point* m_bottom_right;
	
public:
	Rectangle();

	Rectangle(const Point& topLeft, const Point& bottomRight);

	Rectangle(const Rectangle& r);

	~Rectangle();

	Point* top_left();

	Point* bottom_right();

	void set_top_left(const Point& p);
	
	void set_bottom_right(const Point& p);

	float perimeter();

	float area();
};

#endif