#include "Dice.h"
#include "Line.h"
#include "Point.h"
#include "Random.h"
#include "Rectangle.h"

#include <iostream>

void illustrate_point()
{
    Point* a = new Point(2, 4);
    Point* b = new Point(-12, 0);

    std::cout << "Da tao ra " << Point::s_instance_count << " diem:\n"
                 "A: " << *a << '\n' <<
                 "B: " << *b << '\n';
    std::cout << "Khoang cach giua hai diem: " << Point::CalcDistance(*a, *b) << '\n';

    delete a;
    std::cout << "So diem sau khi xoa diem A: " << Point::s_instance_count << '\n';

    delete b;
    std::cout << "So diem sau khi xoa diem B: " << Point::s_instance_count << '\n';
}

void illustrate_line()
{
    Line* l1 = new Line{ Point(1, 3), Point(3, 4) };
    Line* l2 = new Line{ Point(6, 0), Point(17, 23) };

    std::cout << "Da tao ra " << Line::s_instance_count << " duong thang:\n"
                 "Duong thang 1: " << *l1 << ", do dai: " << l1->length() << '\n' <<
                 "Duong thang 2: " << *l2 << ", do dai: " << l2->length() << '\n';

    delete l1;
    std::cout << "So duong thang sau khi xoa duong thang 1: " << Line::s_instance_count << '\n';

    delete l2;
    std::cout << "So duong thang sau khi xoa duong thang 2: " << Line::s_instance_count << '\n';
}

int main()
{
    // srand((unsigned int) time(nullptr));

    // Dice d;
    // for (int i = 0; i < 103; ++i)
    //     std::cout << d.roll() << (i == 102 ? '\n' : ' ');
    // std::cout << d.roll_times() << '\n';

    //illustrate_point();
    //illustrate_line();
    return 0;
}