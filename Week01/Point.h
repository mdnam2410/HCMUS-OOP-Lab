#pragma once

#include <iostream>

class Point
{
private:
	float _x;
	float _y;
public:
	Point();

	Point(float x, float y);

	Point(const Point& p);

	~Point();

	float X();

	float Y();

	void SetX(float value);

	void SetY(float value);

	float CalcDistanceTo(const Point& other);

	Point& operator=(const Point& other);

	friend std::ostream& operator<<(std::ostream& os, const Point& point);

	friend std::istream& operator>>(std::istream& is, Point& point);
};

