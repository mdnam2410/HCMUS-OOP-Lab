#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
	static int s_instance_count;
private:
	float m_x;
	float m_y;
public:
	Point();

	Point(const float x, const float y);

	Point(const Point& p);

	~Point();

	float X() const;

	float Y() const;

	void SetX(float value);

	void SetY(float value);

	float CalcDistanceTo(const Point& other) const;

	Point& operator=(const Point& other);

	friend std::ostream& operator<<(std::ostream& os, const Point& point);

	friend std::istream& operator>>(std::istream& is, Point& point);

	static float CalcDistance(const Point& a, const Point& b);
};

#endif