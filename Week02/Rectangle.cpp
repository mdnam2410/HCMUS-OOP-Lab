#include "Rectangle.h"

int Rectangle::s_instance_count = 0;

Rectangle::Rectangle()
{
	m_topLeft = new Point(1.0F, 1.0F);
	m_bottomRight = new Point(10.0F, 10.0F);
	++s_instance_count;
}

Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight)
{
	m_topLeft = new Point(topLeft.X(), topLeft.Y());
	m_bottomRight = new Point(bottomRight.X(), bottomRight.Y());
	++s_instance_count;
}

Rectangle::Rectangle(const Rectangle& r)
{
	m_topLeft = new Point;
	m_bottomRight = new Point;

	*(m_topLeft) = *(r.m_topLeft);
	*(m_bottomRight) = *(r.m_bottomRight);
	
	++s_instance_count;
}

Rectangle::~Rectangle()
{
	delete m_topLeft;
	delete m_bottomRight;

	m_topLeft = m_bottomRight = nullptr;
	--s_instance_count;
}

Point* Rectangle::TopLeft()
{
	return m_topLeft;
}

Point* Rectangle::BottomRight()
{
	return m_bottomRight;
}

void Rectangle::SetTopLeft(const Point& p)
{
	*(m_topLeft) = p;
}

void Rectangle::SetBottomRight(const Point& p)
{
	*(m_bottomRight) = p;
}

float Rectangle::Perimeter()
{
	Point topRight(m_topLeft->X(), BottomRight()->Y());
	return 2.0F* (topRight.CalcDistanceTo(*m_topLeft) + topRight.CalcDistanceTo(*m_bottomRight));
}

float Rectangle::Area()
{
	Point topRight(m_topLeft->X(), BottomRight()->Y());
	return topRight.CalcDistanceTo(*m_topLeft) * topRight.CalcDistanceTo(*m_bottomRight);
}

void Rectangle::Info()
{
	std::cout << "\tDiem trai tren: " << *(TopLeft()) << '\n';
    std::cout << "\tDiem phai duoi: " << *(BottomRight()) << '\n';
    std::cout << "\tChu vi: " 		  << Perimeter() << '\n';
    std::cout << "\tDien tich: " 	  << Area() << '\n';
}