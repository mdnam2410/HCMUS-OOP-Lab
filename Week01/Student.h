#pragma once

#include <string>

class Student
{
private:
    std::string _firstName;
    std::string _middleName;
    std::string _lastName;
public:
    Student();

    Student(std::string firstName, std::string middleName, std::string lastName);
    
    ~Student();

    std::string GetFirstName();
    
    std::string GetMiddleName();
    
    std::string GetLastName();

    void SetFirstName(std::string firstName);
    
    void SetMiddleName(std::string middleName);
    
    void SetLastName(std::string lastName);

    std::string FullName();

    void Info();
};