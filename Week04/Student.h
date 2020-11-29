#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    std::string* _firstName;
    std::string* _middleName;
    std::string* _lastName;
public:
    Student();

    Student(std::string firstName, std::string middleName, std::string lastName);

    Student(const Student& other);
    
    ~Student();

    std::string GetFirstName() const;
    
    std::string GetMiddleName() const;
    
    std::string GetLastName() const;

    void SetFirstName(std::string firstName);
    
    void SetMiddleName(std::string middleName);
    
    void SetLastName(std::string lastName);

    std::string FullName() const;

    std::string ToString() const;
};

#endif