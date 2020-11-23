#include "DynamicArray.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"

#include <iostream>


void press_enter_to_continue()
{
    std::cout << "Nhan enter de tiep tuc: ";
    char c;
    std::cin.get(c);
    std::cout << '\n';
}

void illustrate_point()
{
    std::cout << "# class Point\n";
    Point A(1, 4);
    std::cout << "Da tao ra mot object A thuoc lop Point:\n";
    std::cout << "A: " << A << '\n';

    Point B(A);
    std::cout << "Goi khoi tao sao chep object B sao chep tu A:\n";
    std::cout << "B: " << B << '\n';
}

void illustrate_line()
{
    std::cout << "# class Line\n";
    Point a(1, 3), b(5, 6);
    Line A(a, b);
    std::cout << "Da tao mot object A thuoc lop Line:\n";
    std::cout << "A: " << A << '\n';

    Line B(A);
    std::cout << "Goi khoi tao sao chep object B, sao chep du lieu tu object A.\n";
    std::cout << "B: " << B << '\n';
}

void illustrate_rectangle()
{
    std::cout << "# class Rectangle\n";
    Rectangle R1(Point(1, 2), Point(3, 4));
    std::cout << "Da tao mot object R1 thuoc lop Rectangle:\n";
    std::cout << "R1: " << R1 << '\n';

    Rectangle R2(R1);
    std::cout << "Khoi tao sao chep object R2, sao chep du lieu tu R1:\n";
    std::cout << "R2: " << R2 << '\n';
}

void illustrate_dynamic_array()
{
    std::cout << "# class DynamicArray\n";
    int data[] = { 1, 2, 3, 4, 5 };
    DynamicArray da1(data, 5);
    std::cout << "Da khoi tao mot object da1 thuoc lop DynamicArray:\n";
    da1.Info();

    DynamicArray da2(da1);
    std::cout << "Khoi tao sao chep object da2, sao cheo du lieu tu da1:\n";
    da2.Info();
}

int main()
{
    illustrate_point();
    press_enter_to_continue();

    illustrate_line();
    press_enter_to_continue();

    illustrate_dynamic_array();
    press_enter_to_continue();

    illustrate_rectangle();
    return 0;
}