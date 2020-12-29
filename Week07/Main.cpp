#include "Circle.h"
#include "Date.h"
#include "DynamicArray.h"
#include "Fraction.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Student.h"
#include "Time.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

template <typename T>
void Test(const std::vector<std::string> &testSet, const std::string &className)
{
    std::cout << "=========== class " << className << " ============\n";

    for (auto &str : testSet) {
        std::cout << "Input: \"" << str << "\", output: ";
        T *res = T::Parse(str);
        if (res) {
            std::cout << res->ToString() << '\n';
            delete res;
        }
        else
            std::cout << "error\n";
    }
}

int main()
{
    enum { POINT, LINE, RECTANGLE, TRIANGLE, CIRCLE, FRACTION, DYNAMIC_ARRAY, STUDENT, DATE, TIME };

    std::string classNames[] = { "Point", "Line", "Rectangle", "Triangle", "Circle", 
                                "Fraction", "DynamicArray", "Student", "Time", "Date" };
    std::vector<std::vector<std::string>> testSets({
        {                       // Test set for Point
            "(0, 1)",
            "0, 4)",
            "(0, 5))",
            "(1, 3",
            "asbcs",
            "(5 6, 0)",
            "24",
            "()"
        },
        {                       // Test set for Line
            "(1, 4), (5, 10)",
            "5, 2, 4, 2",
            "abscdef",
            "(12, -23)), (4, 2))"
            "(1, 3, 4)",
            "(1, 0), (6, 23), (7, 9)",
            "()"
        },
        {                       // Rectangle
            "(8, 0), (21, 3)",
            "(, 2)",
            "9, 10",
            "()",
            ")(",
            "3, 3"
        },
        {                       // Triangle
            "(1, 3), (4, 2), (5, 0)",
            "5, 2), (8, 3), 4, 6",
            "(5, 2) 5 , 2), (4, 5)",
            "(1, 3), (2, 3)"
            "(4, 0)",
            "abcdef",
            ")4, 5("
        },
        {                       // Circle
            "(0, 0), 5",
            "5, 1, 9",
            "(1, 2), (3, 4)",
            "2, (1, 3)",
            "(0, 5), -10",
            "abcdef",
        },
        {                       // Fraction
            "1/5",
            "a/b",
            "0/9",
            "9/0",
            "3\\2",
            "4 5",
            "acbdef",
            "312 / 341",
        },
        {                       // DynamicArray
            "1",
            "1, 3, 4",
            "abcdef",
            "-3, -2, -1, 0, 1, 2",
            "3.5",
            "8f",
            "1, 2, 3, 5, a, b, c "
        },
        {                       // Student
            "Nguyen Van A",
            "Family Middle Given",
            "Mai Duy Nam",
            "Nguyen Trai",
            "A B C D",
        },
        {                       // Date
            "29/12/2020",
            "1/1/2000",
            "4/5",
            "29/2/2009",
            "32/4/21",
            "abcdef",
            "5/23/1994",
            "8/4a/2010",
        },
        {                       // Time
            "10:55:30",
            "6:3:20",
            "24:5:10",
            "10:70:21",
            "32a:32",
            "a:b:c",
            "6;32;50",
            "abcdef"
        }
    });

    Test<Point>(testSets[POINT], classNames[POINT]);
    Test<Line>(testSets[LINE], classNames[LINE]);
    Test<Rectangle>(testSets[RECTANGLE], classNames[RECTANGLE]);
    Test<Triangle>(testSets[TRIANGLE], classNames[TRIANGLE]);
    Test<Circle>(testSets[CIRCLE], classNames[CIRCLE]);
    Test<Fraction>(testSets[FRACTION], classNames[FRACTION]);
    Test<DynamicArray>(testSets[DYNAMIC_ARRAY], classNames[DYNAMIC_ARRAY]);
    Test<Student>(testSets[STUDENT], classNames[STUDENT]);
    Test<Date>(testSets[DATE], classNames[DATE]);
    Test<Time>(testSets[TIME], classNames[TIME]);
    return 0;
}