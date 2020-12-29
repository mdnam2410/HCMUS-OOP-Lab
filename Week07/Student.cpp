#include "Student.h"
#include "Utils.h"

#include <iostream>
#include <sstream>

// -- Static member functions

Student* Student::Parse(const std::string &input)
{
    std::stringstream ss(input);
    std::string givenName, middleName, familyName;
    int numOfWords = CountWords(input);
    ss >> familyName;
    --numOfWords;
    
    while (numOfWords > 1) {
        std::string temp;
        ss >> temp;
        middleName += " " + temp;
        --numOfWords;
    }
    ss >> givenName;
    return new Student(givenName, middleName, familyName);
}

// -- Constructors & destructor

Student::Student()
{
    m_givenName = m_middleName = m_familyName = nullptr;
}

Student::Student(std::string firstName, std::string middleName, std::string lastName)
{
    m_givenName = new std::string(firstName);
    m_middleName = new std::string(middleName);
    m_familyName = new std::string(lastName);
}

Student::Student(const Student& other)
{
    SetFirstName(other.GetFirstName());
    SetMiddleName(other.GetMiddleName());
    SetLastName(other.GetLastName());
}

Student::~Student()
{
    delete m_givenName;
    delete m_middleName;
    delete m_familyName;
}

// -- Public member functions

std::string Student::GetFirstName() const
{
    return m_givenName ? *m_givenName : "";
}

std::string Student::GetMiddleName() const
{
    return m_middleName ? *m_middleName : "";
}

std::string Student::GetLastName() const
{
    return m_familyName ? *m_familyName : "";
}

void Student::SetFirstName(std::string firstName)
{
    if (m_givenName)
        delete m_givenName;
    m_givenName = new std::string(firstName);
}

void Student::SetMiddleName(std::string middleName)
{
    if (m_middleName)
        delete m_middleName;
    m_middleName = new std::string(middleName);
}

void Student::SetLastName(std::string lastName)
{
    if (m_familyName)
        delete m_familyName;
    m_familyName = new std::string(lastName);
}

std::string Student::FullName() const
{
    return GetLastName() + " " + GetMiddleName() + " " + GetFirstName();
}

std::string Student::ToString() const
{
    return FullName();
}
