#include "Point.h"

#include <math.h>

using namespace std;

Point::Point()
{
	this->_x = 0.0F;
	this->_y = 0.0F;
}

Point::Point(float x, float y)
{
	this->_x = x;
	this->_y = y;
}

Point::Point(const Point& p)
{
	this->_x = p._x;
	this->_y = p._y;
}

Point::~Point()
{
}

float Point::X()
{
	return this->_x;
}

float Point::Y()
{
	return this->_y;
}

void Point::SetX(float value)
{
	this->_x = value;
}

void Point::SetY(float value)
{
	this->_y = value;
}

float Point::CalcDistanceTo(const Point& other)
{
	float dx = this->_x - other._x;
	float dy = this->_y - other._y;

	return sqrt(dx * dx + dy * dy);
}

Point& Point::operator=(const Point& other)
{
	this->_x = other._x;
	this->_y = other._y;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << '(' << point._x << ", " << point._y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& point)
{
	char separator;
	is >> point._x;
	is.get(separator);
	std::cin >> point._y;
	return is;
}