#include "Student.h"

#include <iostream>

Student::Student()
{
    _firstName = _middleName = _lastName = nullptr;
}

Student::Student(std::string firstName, std::string middleName, std::string lastName)
{
    _firstName = new std::string(firstName);
    _middleName = new std::string(middleName);
    _lastName = new std::string(lastName);
}

Student::Student(const Student& other)
{
    SetFirstName(other.GetFirstName());
    SetMiddleName(other.GetMiddleName());
    SetLastName(other.GetLastName());
}

Student::~Student()
{
    delete _firstName;
    delete _middleName;
    delete _lastName;
}

std::string Student::GetFirstName() const
{
    return _firstName ? *_firstName : "";
}

std::string Student::GetMiddleName() const
{
    return _middleName ? *_middleName : "";
}

std::string Student::GetLastName() const
{
    return _lastName ? *_lastName : "";
}

void Student::SetFirstName(std::string firstName)
{
    if (_firstName)
        delete _firstName;
    _firstName = new std::string(firstName);
}

void Student::SetMiddleName(std::string middleName)
{
    if (_middleName)
        delete _middleName;
    _middleName = new std::string(middleName);
}

void Student::SetLastName(std::string lastName)
{
    if (_lastName)
        delete _lastName;
    _lastName = new std::string(lastName);
}

std::string Student::FullName() const
{
    return GetLastName() + " " + GetMiddleName() + " " + GetFirstName();
}

std::string Student::ToString() const
{
    return FullName();
}
