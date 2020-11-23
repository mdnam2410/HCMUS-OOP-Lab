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
    Point a(1, 4);
    std::cout << "Da tao ra mot object A thuoc lop Point: " << a << '\n';

    Point b(a);
    std::cout << "Goi khoi tao sao chep object B sao chep tu A: " << b << '\n';
}


int main()
{
    illustrate_point();
}