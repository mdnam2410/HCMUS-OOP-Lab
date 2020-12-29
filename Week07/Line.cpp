#include "Line.h"
#include "Utils.h"

#include <sstream>

int Line::s_instance_count;

Line* Line::Parse(const std::string &input)
{
    // auto n_pos = std::string::npos;
    // size_t comma = 0;
    // Point *points[2]{};
    // int i = 0;
    // do {
    //     size_t open_paren = input.find('(', comma);
    //     size_t close_paren = input.find(')', open_paren);
    //     comma = input.find(',', close_paren);
    //     if (open_paren != n_pos && close_paren != n_pos)
    //         points[i] = Point::Parse(input.substr(open_paren, close_paren - open_paren + 1));
    //     ++i;
    // } while (i < 2);

    // if (points[0] && points[1]) {
    //     Line *l = new Line(*points[0], *points[1]);
    //     delete points[0];
    //     delete points[1];
    //     return l;
    // }
    // else
    //     return nullptr;
    Point *points = ParsePoint(input, 2, ',');
    if (!points)
        return nullptr;
    Line *line = new Line(points[0], points[1]);
    /// No longer used
    delete[] points;
    return line;
}

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

std::string Line::ToString() const
{
    std::stringstream ss;
    ss << "Bat dau: " << m_start->ToString() << ", ket thuc: " << m_end->ToString();
    return ss.str();
}
