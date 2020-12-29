#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    /**
     * Format: <family name> <middle name> <given name>
     */
    static Student* Parse(const std::string &input);

private:
    std::string* m_givenName;
    std::string* m_middleName;
    std::string* m_familyName;

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