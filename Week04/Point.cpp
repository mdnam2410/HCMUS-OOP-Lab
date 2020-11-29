#include "Point.h"

#include <math.h>
#include <sstream>

int Point::s_instance_count = 0;

Point::Point()
{
	m_x = 0.0F;
	m_y = 0.0F;

	++s_instance_count;
}

Point::Point(float x, float y)
{
	m_x = x;
	m_y = y;

	++s_instance_count;
}

Point::Point(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
}

Point::~Point()
{
	--s_instance_count;
}

float Point::X() const
{
	return m_x;
}

float Point::Y() const
{
	return m_y;
}

void Point::SetX(float value)
{
	m_x = value;
}

void Point::SetY(float value)
{
	m_y = value;
}

float Point::CalcDistanceTo(const Point& other) const
{
	float dx = m_x - other.m_x;
	float dy = m_y - other.m_y;

	return sqrt(dx * dx + dy * dy);
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << '(' << point.m_x << ", " << point.m_y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& point)
{
	char separator;
	is >> point.m_x;
	is.get(separator);
	std::cin >> point.m_y;
	return is;
}

float Point::CalcDistance(const Point& a, const Point& b)
{
	return a.CalcDistanceTo(b);
}

std::string Point::ToString() const
{
	std::stringstream ss;
	ss << "(" << m_x << ", " << m_y << ")";
	return ss.str();
}