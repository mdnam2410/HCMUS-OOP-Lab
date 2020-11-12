#include "Rectangle.h"

int Rectangle::s_instance_count = 0;

Rectangle::Rectangle()
{
	m_top_left = new Point(1.0F, 1.0F);
	m_bottom_right = new Point(10.0F, 10.0F);
	++s_instance_count;
}

Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight)
{
	m_top_left = new Point(topLeft.X(), topLeft.Y());
	m_bottom_right = new Point(bottomRight.X(), bottomRight.Y());
	++s_instance_count;
}

Rectangle::Rectangle(const Rectangle& r)
{
	m_top_left = new Point;
	m_bottom_right = new Point;

	*(m_top_left) = *(r.m_top_left);
	*(m_bottom_right) = *(r.m_bottom_right);
	
	++s_instance_count;
}

Rectangle::~Rectangle()
{
	delete m_top_left;
	delete m_bottom_right;

	m_top_left = m_bottom_right = nullptr;
	--s_instance_count;
}

Point* Rectangle::top_left()
{
	return m_top_left;
}

Point* Rectangle::bottom_right()
{
	return m_bottom_right;
}

void Rectangle::set_top_left(const Point& p)
{
	*(m_top_left) = p;
}

void Rectangle::set_bottom_right(const Point& p)
{
	*(m_bottom_right) = p;
}

float Rectangle::perimeter()
{
	Point topRight(m_top_left->X(), bottom_right()->Y());
	return 2.0F* (topRight.CalcDistanceTo(*m_top_left) + topRight.CalcDistanceTo(*m_bottom_right));
}

float Rectangle::area()
{
	Point topRight(m_top_left->X(), bottom_right()->Y());
	return topRight.CalcDistanceTo(*m_top_left) * topRight.CalcDistanceTo(*m_bottom_right);
}