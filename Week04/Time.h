#ifndef TIME_H
#define TIME_H

#include <string>

class Time
{
public:
    static bool isValidTime(int hour, int minute, int second);

private:
    int* m_hour;
    int* m_minute;
    int* m_second;

public:
    Time();

    Time(int hour, int minute, int second);

    Time(const Time& other);

    ~Time();

    int getHour() const;

    int getMinute() const;

    int getSecond() const;

    bool setHour(int h);

    bool setMinute(int m);

    bool setSecond(int s);

    std::string ToString() const;
};

#endif
