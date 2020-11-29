#include "Rectangle.h"

#include <sstream>

int Rectangle::s_instance_count = 0;

Rectangle::Rectangle()
{
	m_topLeft = new Point(1.0F, 1.0F);
	m_bottomRight = new Point(10.0F, 10.0F);
	++s_instance_count;
}

Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight)
{
	m_topLeft = new Point(topLeft);
	m_bottomRight = new Point(bottomRight);
	++s_instance_count;
}

Rectangle::Rectangle(const Rectangle& r)
{
	m_topLeft = new Point(*r.m_topLeft);
	m_bottomRight = new Point(*r.m_bottomRight);
	++s_instance_count;
}

Rectangle::~Rectangle()
{
	delete m_topLeft;
	delete m_bottomRight;

	m_topLeft = m_bottomRight = nullptr;
	--s_instance_count;
}

Point* Rectangle::top_left()
{
	return m_topLeft;
}

Point* Rectangle::bottom_right()
{
	return m_bottomRight;
}

void Rectangle::set_top_left(const Point& p)
{
	*(m_topLeft) = p;
}

void Rectangle::set_bottom_right(const Point& p)
{
	*(m_bottomRight) = p;
}

float Rectangle::perimeter()
{
	Point topRight(m_topLeft->X(), bottom_right()->Y());
	return 2.0F* (topRight.CalcDistanceTo(*m_topLeft) + topRight.CalcDistanceTo(*m_bottomRight));
}

float Rectangle::area()
{
	Point topRight(m_topLeft->X(), m_bottomRight->Y());
	return topRight.CalcDistanceTo(*m_topLeft) * topRight.CalcDistanceTo(*m_bottomRight);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
	std::cout << "Top left: " << *(r.m_topLeft) << ", bottom right: " << *(r.m_bottomRight);
	return os;
}

std::string Rectangle::ToString() const
{
	std::stringstream ss;
	ss << "top left: " << m_topLeft->ToString() << ", bottom right: " << m_bottomRight->ToString();
	return ss.str();
}