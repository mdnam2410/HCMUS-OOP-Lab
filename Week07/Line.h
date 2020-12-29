#ifndef LINE_H
#define LINE_H

#include "Point.h"

#include <iostream>

class Line
{
public:
    static int s_instance_count;

    static Line* Parse(const std::string &input);

private:
    Point* m_start;
    Point* m_end;

public:
    Line();

    Line(const Point& start, const Point& end);

    Line(const Line& line);

    ~Line();

    float length() const;

    Line& operator=(const Line& other);

    friend std::ostream& operator<<(std::ostream& os, const Line& line);

    std::string ToString() const;
};

#endif