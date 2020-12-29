#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle
{
public:
    static Triangle* Parse(const std::string &input);
private:
    Point* _a;
    Point* _b;
    Point* _c;
public:
    Triangle();

    Triangle(Point a, Point b, Point c);

    Triangle(const Triangle& t);

    ~Triangle();

    Point* A();
    
    Point* B();
    
    Point* C();

    void SetA(const Point& p);
    
    void SetB(const Point& p);
    
    void SetC(const Point& p);

    float AB();

    float BC();

    float AC();

    float Perimeter();

    float Area();

    void Info();

    std::string ToString() const;
};

#endif
