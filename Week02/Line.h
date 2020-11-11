#ifndef LINE_H
#define LINE_H

#include "Point.h"

#include <iostream>

class Line
{
public:
    static int s_instance_count;

private:
    Point m_start;
    Point m_end;
public:
    Line();

    Line(Point start, Point end);

    Line(const Line& line);

    ~Line();

    float length() const;

    Line& operator=(const Line& other);

    friend std::ostream& operator<<(std::ostream& os, const Line& line);
};

#endif