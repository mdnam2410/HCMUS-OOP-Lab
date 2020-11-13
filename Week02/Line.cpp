#include "Line.h"

int Line::s_instance_count;

Line::Line()
{
    m_start = m_end = Point(0, 0);
    ++s_instance_count;
}

Line::Line(const Point& start, const Point& end)
{
    m_start = start;
    m_end = end;
    ++s_instance_count;
}

Line::Line(const Line& line)
{
    if (this != &line)
    {
        m_start = line.m_start;
        m_end = line.m_end;
        ++s_instance_count;
    }
}

Line::~Line()
{
    --s_instance_count;
}

float Line::length() const
{
    return Point::CalcDistance(m_start, m_end);
}

Line& Line::operator=(const Line& other)
{
    if (this != &other)
    {
        m_start = other.m_start;
        m_end = other.m_end;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Line& line)
{
    os << line.m_start << " -> " << line.m_end;
    return os;
}