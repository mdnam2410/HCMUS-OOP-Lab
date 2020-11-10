#include "Student.h"

#include <iostream>

Student::Student()
{
    this->_firstName = this->_middleName = this->_lastName = "";
}

Student::Student(std::string firstName, std::string middleName, std::string lastName)
{
    this->_firstName = firstName;
    this->_middleName = middleName;
    this->_lastName = lastName;
}

Student::~Student()
{
}

std::string Student::GetFirstName()
{
    return this->_firstName;
}

std::string Student::GetMiddleName()
{
    return this->_middleName;
}

std::string Student::GetLastName()
{
    return this->_lastName;
}

void Student::SetFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

void Student::SetMiddleName(std::string middleName)
{
    this->_middleName = middleName;
}

void Student::SetLastName(std::string lastName)
{
    this->_lastName = lastName;
}

std::string Student::FullName()
{
    return this->_firstName + " " + this->_middleName + " " + this->_lastName;
}

void Student::Info()
{
    std::cout << "\tHo: " << this->_lastName << '\n';
    std::cout << "\tTen dem: " << this->_middleName << '\n';
    std::cout << "\tTen: " << this->_firstName << '\n';
    std::cout << "\tHo va ten: " << this->FullName() << '\n';
}