#include "Circle.h"
#include "Date.h"
#include "DynamicArray.h"
#include "Fraction.h"
#include "Line.h"
#include "Rectangle.h"
#include "Student.h"
#include "Time.h"
#include "Triangle.h"

#include <iostream>
#include <limits>

template <typename T>
T input(std::string prompt)
{
    T obj;
    std::cout << prompt;
    std::cin >> obj;
    return obj;
}

void askIfContinue()
{
    char c;
    std::cout << "Nhan Y (tiep tuc) hoac N (thoat): ";
    std::cin >> c;
    if (c == 'N' || c == 'n')
        exit(EXIT_SUCCESS);
    std::cout << "\n\n";
}

void illustratePoint()
{
    std::cout << "# class Point\n";
    Point P1;
    std::cout << "Da tao ra mot object P1 thuoc lop Point (khoi tao mac dinh)\n";
    std::cout << "P1.ToString(): " << P1.ToString() << '\n';

    std::cout << "\nTao object P2 (khoi tao tuy chinh)\n";
    int x, y;
    x = input<int>("Nhap toa do x: ");
    y = input<int>("Nhap toa do y: ");
    Point P2(x, y);
    std::cout << "P2.ToString(): " << P2.ToString() << '\n';
}

void illustrateLine()
{
    std::cout << "# class Line\n";
    Line L;
    std::cout << "Da tao mot object L thuoc lop Line (khoi tao mac dinh)\n";
    std::cout << "L.ToString(): " << L.ToString() << '\n';
}

void illustrateTriangle()
{
    std::cout << "# class Triangle\n";
    Triangle T;
    std::cout << "Da tao mot object T thuoc lop Triangle (khoi tao mac dinh)\n";
    std::cout << "T.ToString(): " << T.ToString() << '\n';
}

void illustrateRectangle()
{
    std::cout << "# class Rectangle\n";
    Rectangle R;
    std::cout << "Da tao mot object R thuoc lop Rectangle (khoi tao mac dinh)\n";
    std::cout << "R.ToString(): " << R.ToString() << '\n';
}

void illustrateCircle()
{
    std::cout << "# class Circle\n";
    Circle C;
    std::cout << "Da tao mot object C thuoc lop Circle (khoi tao mac dinh)\n";
    std::cout << "C.ToString(): " << C.ToString() << '\n';
}

void illustrateDynamicArray()
{
    std::cout << "# class DynamicArray\n";

    int size = input<int>("Nhap kich thuoc mang: ");
    int* data = new int[size];
    for (int i = 0; i < size; ++i)
        data[i] = input<int>("Nhap phan tu " + std::to_string(i) + ": ");

    DynamicArray DA(data, size);
    std::cout << "Da khoi tao mot object DA thuoc lop DynamicArray:\n";
    std::cout << "DA.ToString(): " << DA.ToString() << '\n';
}

void illustrateFraction()
{
    std::cout << "# class Fraction\n";
    int nom, denom;
    nom = input<int>("Nhap tu: ");
    denom = input<int>("Nhap mau: ");
    Fraction F(nom, denom);
    std::cout << "Da khoi tao mot object F thuoc lop Fraction:\n";
    std::cout << "F.ToString(): " << F.ToString() << '\n';
}

void illustrateStudent()
{
    std::cout << "# class Student\n";
    std::string first, middle, last;
    last = input<std::string>("Nhap ho: ");
    middle = input<std::string>("Nhap ten dem: ");
    first = input<std::string>("Nhap ten: ");

    Student S(first, middle, last);
    std::cout << "Da khoi tao mot object S thuoc lop Student:\n";
    std::cout << "S.ToString(): " << S.ToString() << '\n';
}

void illustrateDate()
{
    std::cout << "# class Date\n";
    Date D1;
    std::cout << "Da khoi tao mot object D1 thuoc lop Date (khong tham so):\n";
    std::cout << "D1.ToString(): " << D1.ToString() << '\n';

    std::cout << "\nKhoi tao doi tuong D2 (co tham so)\n";
    
    int d, m, y;
    d = input<int>("Nhap ngay: ");
    m = input<int>("Nhap thang: ");
    y = input<int>("Nhap nam: ");

    Date D2(d, m, y);
    std::cout << "D2.ToString(): " << D2.ToString() << '\n';
}

void illustrateTime()
{
    std::cout << "# class Time\n";
    Time T1;
    std::cout << "Da khoi tao mot object T1 thuoc lop Time (khong tham so):\n";
    std::cout << "T1.ToString(): " << T1.ToString() << '\n';

    std::cout << "\nKhoi tao doi tuong T2 (co tham so)\n";
    int h, m, s;
    h = input<int>("Nhap gio: ");
    m = input<int>("Nhap phut: ");
    s = input<int>("Nhap giay: ");

    Time T2(h, m, s);
    std::cout << "T2.ToString(): " << T2.ToString() << '\n';
}

typedef void (*FuncPtr_t)();

FuncPtr_t illustrations[] = { 
    illustratePoint,
    illustrateLine,
    illustrateTriangle,
    illustrateRectangle,
    illustrateCircle,
    illustrateDynamicArray,
    illustrateFraction,
    illustrateStudent,
    illustrateDate,
    illustrateTime
};

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        illustrations[i]();
        if (i != 10 - 1)
            askIfContinue();
    }
    return 0;
}