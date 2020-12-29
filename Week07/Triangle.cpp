#include "Triangle.h"
#include "Utils.h"

#include <math.h>
#include <sstream>

Triangle* Triangle::Parse(const std::string &input)
{
    Point *points = ParsePoint(input, 3, ',');
    if (!points)
        return nullptr;
    Triangle *triangle = new Triangle(points[0], points[1], points[2]);
    delete[] points;
    return triangle;
}

Triangle::Triangle()
{
    this->_a = new Point(1.0F, 1.0F);
    this->_b = new Point(1.0F, 2.0F);
    this->_c = new Point(4.0F, 2.0F);
}

Triangle::Triangle(Point a, Point b, Point c)
{
    this->_a = new Point(a);
    this->_b = new Point(b);
    this->_c = new Point(c);
}

Triangle::Triangle(const Triangle& t)
{
    this->_a = new Point;
    this->_b = new Point;
    this->_c = new Point;

    SetA(*t._a);
    SetB(*t._b);
    SetC(*t._c);
}

Triangle::~Triangle()
{
    delete this->_a;
    delete this->_b;
    delete this->_c;
    
    this->_a = this->_b = this->_c = nullptr;
}

Point* Triangle::A()
{
    return this->_a;
}

Point* Triangle::B()
{
    return this->_b;
}

Point* Triangle::C()
{
    return this->_c;
}

void Triangle::SetA(const Point& p)
{
    *_a = p;
}

void Triangle::SetB(const Point& p)
{
    *_b = p;
}

void Triangle::SetC(const Point& p)
{
    *_c = p;
}

float Triangle::AB()
{
    return (this->_a)->CalcDistanceTo(*(this->_b));
}

float Triangle::BC()
{
    return (this->_b)->CalcDistanceTo(*(this->_c));
}

float Triangle::AC()
{
    return (this->_a)->CalcDistanceTo(*(this->_c));
}

float Triangle::Perimeter()
{
    return AB() + BC() + AC();
}

float Triangle::Area()
{
    float p = Perimeter() / 2;
    return sqrt(p * (p - AB()) * (p - BC()) * (p - AC()));
}

void Triangle::Info()
{
    std::cout << "\tDiem A: " << *(this->A()) << '\n'
              << "\tDiem B: " << *(this->B()) << '\n'
              << "\tDiem C: " << *(this->C()) << '\n'
              << "\tChu vi: " << this->Perimeter() << '\n'
              << "\tDien tich: " << this->Area() << '\n';
}

std::string Triangle::ToString() const
{
    std::stringstream ss;
    ss << "A: " << _a->ToString() << ", B: " << _b->ToString() << ", C: " << _c->ToString();
    return ss.str();
}
