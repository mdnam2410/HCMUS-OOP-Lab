#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

#include <string>

class Circle
{
private:
    Point* m_center;
    double* m_radius;

public:
    Circle();

    Circle(const Point& point, double radius);

    Circle(const Circle& other);

    ~Circle();

    Point getCenter() const;

    double getRadius() const;

    void setCenter(const Point& center);

    void setRadius(double radius);

    std::string ToString() const;
};

#endif
