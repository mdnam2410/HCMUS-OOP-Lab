#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray
{
private:
    const int INITIAL_SIZE = 128;
    int* m_a;
    int m_len;
    int m_max;
public:
    DynamicArray();

    DynamicArray(const int* a, int n);

    DynamicArray(const DynamicArray& da);

    ~DynamicArray();

    void PushBack(int value);

    int GetAt(int index);

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& da);

    void Info();

    std::string ToString() const;
};

#endif