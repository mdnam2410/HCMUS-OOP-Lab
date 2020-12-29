#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
public:
    static bool isLeapYear(int year);

    static bool isValidDate(int day, int month, int year);

    static Date* Parse(const std::string &input);

private:
    // Day in the month, range [1, 31]
    int* m_day;
    // Month, range [1, 12]
    int* m_month;

    int* m_year;

public:
    Date();

    Date(int day, int month, int year);

    Date(const Date& other);

    ~Date();

    int getDay() const;

    int getMonth() const;
    
    int getYear() const;

    std::string ToString() const;
};

#endif
