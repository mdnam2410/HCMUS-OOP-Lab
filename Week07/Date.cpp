#include "Date.h"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

const int dayOfMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// -- Static member functions --

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool Date::isValidDate(int day, int month, int year)
{
    if (day < 1 || day > 31 || month < 1 || month > 12)
        return false;

    if (month == 2)
        return day <= (dayOfMonth[month - 1] + (isLeapYear(year) ? 1 : 0));
    else
        return day <= dayOfMonth[month - 1];
}

Date* Date::Parse(const std::string &input)
{
    std::size_t firstSlash = input.find('/');
    std::size_t secondSlash = input.find('/', firstSlash + 1);
    if (firstSlash == std::string::npos || secondSlash == std::string::npos)
        return nullptr;
    
    try {
        int d = std::stoi(input.substr(0, firstSlash));
        int m = std::stoi(input.substr(firstSlash + 1, secondSlash - firstSlash));
        int y = std::stoi(input.substr(secondSlash + 1));
        return new Date(d, m, y);
    } catch (...) {
        return nullptr;
    }
}

// -- Constructors and destructor

Date::Date()
{
    std::time_t t = time(nullptr);
    std::tm* now = std::localtime(&t);
    if (!now)
    {
        std::cerr << "Loi thoi gian! Dang thoat chuong trinh...\n";
        exit(EXIT_FAILURE);
    }

    m_day = new int(now->tm_mday);
    m_month = new int(now->tm_mon + 1);
    m_year = new int(now->tm_year + 1900);
}

Date::Date(int day, int month, int year)
{
    if (!isValidDate(day, month, year))
        throw "Invalid date";
    m_day = new int(day);
    m_month = new int(month);
    m_year = new int(year);
}

Date::Date(const Date& other)
{
    m_day = new int(other.getDay());
    m_month = new int(other.getMonth());
    m_year = new int(other.getYear());
}

Date::~Date()
{
    delete m_day;
    delete m_month;
    delete m_year;
}

// -- Member functions

int Date::getDay() const
{
    return *m_day;
}

int Date::getMonth() const
{
    return *m_month;
}

int Date::getYear() const
{
}

int Date::getMonth() const
{
    return *m_month;
}

int Date::getYear() const
{
    return *m_year;
}

std::string Date::ToString() const
{
    std::stringstream ss;
    char prevFill = ss.fill();
    ss.fill('0');
    ss << std::setw(2) << *m_day << '/' << std::setw(2) << *m_month << '/' << std::setw(2) << *m_year;
    ss.fill(prevFill);
    return ss.str();
}