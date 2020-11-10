#include "Rectangle.h"

Rectangle::Rectangle()
{
	this->_topLeft = new Point(1.0F, 1.0F);
	this->_bottomRight = new Point(10.0F, 10.0F);
}

Rectangle::Rectangle(Point topLeft, Point bottomRight)
{
	this->_topLeft = new Point(topLeft.X(), topLeft.Y());
	this->_bottomRight = new Point(bottomRight.X(), bottomRight.Y());
}

Rectangle::Rectangle(const Rectangle& r)
{
	this->_topLeft = new Point;
	this->_bottomRight = new Point;

	*(this->_topLeft) = *(r._topLeft);
	*(this->_bottomRight) = *(r._bottomRight);
}

Rectangle::~Rectangle()
{
	delete this->_topLeft;
	delete this->_bottomRight;

	this->_topLeft = this->_bottomRight = nullptr;
}

Point* Rectangle::TopLeft()
{
	return this->_topLeft;
}

Point* Rectangle::BottomRight()
{
	return this->_bottomRight;
}

void Rectangle::SetTopLeft(const Point& p)
{
	*(this->_topLeft) = p;
}

void Rectangle::SetBottomRight(const Point& p)
{
	*(this->_bottomRight) = p;
}

float Rectangle::Perimeter()
{
	Point topRight(this->_topLeft->X(), this->BottomRight()->Y());
	return 2.0F* (topRight.CalcDistanceTo(*this->_topLeft) + topRight.CalcDistanceTo(*this->_bottomRight));
}

float Rectangle::Area()
{
	Point topRight(this->_topLeft->X(), this->BottomRight()->Y());
	return topRight.CalcDistanceTo(*this->_topLeft) * topRight.CalcDistanceTo(*this->_bottomRight);
}

void Rectangle::Info()
{
	std::cout << "\tDiem trai tren: " << *(this->TopLeft()) << '\n';
    std::cout << "\tDiem phai duoi: " << *(this->BottomRight()) << '\n';
    std::cout << "\tChu vi: " 		  << this->Perimeter() << '\n';
    std::cout << "\tDien tich: " 	  << this->Area() << '\n';
}