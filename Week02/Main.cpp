#include "Dice.h"
#include "Line.h"
#include "Point.h"
#include "Random.h"
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
    std::cout << "# class Line\n";
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

void illustrate_rectangle()
{
    std::cout << "# class Rectangle\n";
    Rectangle* r1 = new Rectangle;
    Rectangle* r2 = new Rectangle(Point(1, 8), Point(2, 10));

    std::cout << "Da tao ra " << Rectangle::s_instance_count << " doi tuong Rectangle:\n"
                 "Rectangle r1: " << *r1 << '\n' <<
                 "Rectangle r2: " << *r2 << '\n';

    delete r1;
    std::cout << "So doi tuong sau khi da xoa r1: " << Rectangle::s_instance_count << '\n';
    
    delete r2;
    std::cout << "So doi tuong sau khi da xoa r2: " << Rectangle::s_instance_count << '\n';
}

void illustrate_random()
{
    std::cout << "# class Random\n";
    Random r;
    
    std::cout << "So duoc tao ngau nhien: " << r.next() << '\n';

    int max;
    std::cout << "Nhap max: ";
    std::cin >> max;
    std::cin.ignore();

    std::cout << "So duoc tao ngau nhien trong khoang [0, " << max - 1 << "]: " << r.next(max) << '\n';
}

void print_roll_result(Dice& dice, int number_of_rolls)
{
    for (int i = 0; i < number_of_rolls; ++i)
        std::cout << dice.roll() << (i == number_of_rolls - 1 ? '\n' : ' ');
}

void illustrate_dice()
{
    std::cout << "# class Dice\n";
    Dice d1, d2, d3;
    std::cout << "Da tao ra 3 con xi ngau d1, d2, d3.\n";

    int max_roll_time = 15;
    Random number_of_rolls;

    std::cout << "Xi ngau 1: ";
    print_roll_result(d1, number_of_rolls.next(max_roll_time) + 1);
    std::cout << "So lan lac cua xi ngau 1: " << d1.roll_times() << '\n';

    std::cout << "Xi ngau 2: ";
    print_roll_result(d2, number_of_rolls.next(max_roll_time) + 1);
    std::cout << "So lan lac cua xi ngau 2: " << d2.roll_times() << '\n';

    std::cout << "Xi ngau 3: ";
    print_roll_result(d3, number_of_rolls.next(max_roll_time) + 1);
    std::cout << "So lan lac cua xi ngau 3: " << d3.roll_times() << '\n';
}

int main()
{
    srand((unsigned int) time(nullptr));

    // Dice d;
    // for (int i = 0; i < 103; ++i)
    //     std::cout << d.roll() << (i == 102 ? '\n' : ' ');
    // std::cout << d.roll_times() << '\n';

    illustrate_point();
    press_enter_to_continue();

    illustrate_line();
    press_enter_to_continue();

    illustrate_rectangle();
    press_enter_to_continue();

    illustrate_random();
    press_enter_to_continue();

    illustrate_dice();

    return 0;
}