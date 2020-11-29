#include "Time.h"

#include <ctime>
#include <iostream>
#include <sstream>

// -- Static member functions

bool Time::isValidTime(int hour, int minute, int second)
{
    return (hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59) && (second >= 0 && second <= 59);
}

Time::Time()
{
    std::time_t t = time(nullptr);
    std::tm* now = std::localtime(&t);
    if (!now)
    {
        std::cerr << "Loi thoi gian! Dang thoat chuong trinh...\n";
        exit(EXIT_FAILURE);
    }

    m_hour = new int(now->tm_hour);
    m_minute = new int(now->tm_min);
    m_second = new int(now->tm_sec);
}

Time::Time(int hour, int minute, int second)
{
    if (!isValidTime(hour, minute, second))
    {
        std::cerr << "Thoi gian khong hop le! Dang thoat chuong trinh...\n";
        exit(EXIT_FAILURE);
    }

    m_hour = new int(hour);
    m_minute = new int(minute);
    m_second = new int(second);
}

Time::Time(const Time& other)
{
    m_hour = new int(other.getHour());
    m_minute = new int(other.getMinute());
    m_second = new int(other.getSecond());
}

Time::~Time()
{
    delete m_hour;
    delete m_minute;
    delete m_second;
}

// -- Member functions


int Time::getHour() const
{
    return *m_hour;
}

int Time::getMinute() const
{
    return *m_minute;
}

int Time::getSecond() const
{
    return *m_second;
}

bool Time::setHour(int h)
{
    if (!isValidTime(h, *m_minute, *m_second))
        return false;
    *m_hour = h;
    return true;
}

bool Time::setMinute(int m)
{
    if (!isValidTime(*m_hour, m, *m_second))
        return false;
    *m_minute = m;
    return true;
}

bool Time::setSecond(int s)
{
    if (!isValidTime(*m_hour, *m_minute, s))
        return false;
    *m_second = s;
    return true;
}

std::string Time::ToString() const
{
    std::stringstream ss;
    ss << *m_hour << ':' << *m_minute << ':' << *m_second;
    return ss.str();
}