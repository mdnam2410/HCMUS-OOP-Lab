#include "Circle.h"

#include <sstream>

Circle::Circle()
{
    m_center = new Point;
    m_radius = new double(0.0);
}

Circle::Circle(const Point& point, double radius)
{
    m_center = new Point(point);
    m_radius = new double(radius);
}

Circle::Circle(const Circle& other)
{
    m_center = new Point(other.getCenter());
    m_radius = new double(other.getRadius());
}

Circle::~Circle()
{
    delete m_center;
    delete m_radius;
}

Point Circle::getCenter() const
{
    return *m_center;
}

double Circle::getRadius() const
{
    return *m_radius;
}

void Circle::setCenter(const Point& center)
{
    *m_center = center;
}

void Circle::setRadius(double radius)
{
    *m_radius = radius;
}

std::string Circle::ToString() const
{
    std::stringstream ss;
    ss << "Tam: " << m_center->ToString() << ", ban kinh: " << *m_radius;
    return ss.str();
}