#pragma once

#include <iostream>

class DynamicArray
{
private:
    const int INITIAL_SIZE = 128;
    int* _a;
    int _len;
    int _max;
public:
    DynamicArray();

    DynamicArray(const int* a, int n);

    DynamicArray(const DynamicArray& da);

    ~DynamicArray();

    void PushBack(int value);

    int GetAt(int index);

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& da);

    void Info();
};