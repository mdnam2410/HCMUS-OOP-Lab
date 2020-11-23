#include "Line.h"

int Line::s_instance_count;

Line::Line()
{
    m_start = new Point(0, 0);
    m_end   = new Point(0, 0);
    ++s_instance_count;
}

Line::Line(const Point& start, const Point& end)
{
    m_start = new Point;
    m_end = new Point;
    *m_start = start;
    *m_end = end;
    ++s_instance_count;
}

Line::Line(const Line& line)
{
    m_start = new Point;
    m_end = new Point;
    *m_start = *line.m_start;
    *m_end = *line.m_end;
    ++s_instance_count;
}

Line::~Line()
{
    --s_instance_count;
    delete m_start;
    delete m_end;
    m_start = m_end = nullptr;
}

float Line::length() const
{
    return Point::CalcDistance(*m_start, *m_end);
}

Line& Line::operator=(const Line& other)
{
    if (this != &other)
    {
        if (m_start)
            delete m_start;
        if (m_end)
            delete m_end;
        m_start = new Point(*other.m_start);
        m_end = new Point(*other.m_end);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Line& line)
{
    os << *line.m_start << " -> " << *line.m_end;
    return os;
}