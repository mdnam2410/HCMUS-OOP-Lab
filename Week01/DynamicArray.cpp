#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    this->_a = new int[this->INITIAL_SIZE];
    this->_len = 0;
    this->_max = this->INITIAL_SIZE;
}

DynamicArray::DynamicArray(const int* a, int n)
{
    this->_a = new int[this->INITIAL_SIZE];
    this->_max = this->INITIAL_SIZE;
    if (n <= 0)
        this->_len = 0;
    else {
        this->_len = n;
        for (int i = 0; i < n; ++i)
            this->_a[i] = a[i];
    }
}

DynamicArray::DynamicArray(const DynamicArray& da)
{
    // Prevent self-copy
    if (this != &da) {
        this->_a = new int[this->INITIAL_SIZE];
        this->_len = da._len;
        this->_max = da._max;

        for (int i = 0; i < this->INITIAL_SIZE && i < this->_len; ++i)
            this->_a[i] = da._a[i];
    }
}

DynamicArray::~DynamicArray()
{
    delete[] this->_a;
}

void DynamicArray::PushBack(int value)
{
    this->_a[this->_len++] = value;
}

int DynamicArray::GetAt(int index)
{
    return this->_a[index];
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& da)
{
    if (da._len == 0)
        std::cout << '\n';
    else 
        for (int i = 0; i < da._len; ++i)
            os << da._a[i] << (i == da._len - 1 ? '\n' : ' ');
    return os;
}

void DynamicArray::Info()
{
    std::cout << "\tMax: " << this->_max
              << "\n\tLength: " << this->_len
              << "\n\tData: " << *this;
}