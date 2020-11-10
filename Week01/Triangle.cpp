#include "Triangle.h"

#include <math.h>

Triangle::Triangle()
{
    this->_a = new Point(1.0F, 1.0F);
    this->_b = new Point(1.0F, 2.0F);
    this->_c = new Point(4.0F, 2.0F);
}

Triangle::Triangle(Point a, Point b, Point c)
{
    this->_a = new Point;
    this->_b = new Point;
    this->_c = new Point;

    *(this->_a) = a;
    *(this->_b) = b;
    *(this->_c) = c;
}

Triangle::Triangle(const Triangle& t)
{
    this->_a = new Point;
    this->_b = new Point;
    this->_c = new Point;

    *(this->_a) = *(t._a);
    *(this->_b) = *(t._b);
    *(this->_c) = *(t._c);
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
    *(this->_a) = p;
}

void Triangle::SetB(const Point& p)
{
    *(this->_b) = p;
}

void Triangle::SetC(const Point& p)
{
    *(this->_c) = p;
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