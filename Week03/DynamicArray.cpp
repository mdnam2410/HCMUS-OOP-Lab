#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    m_a = new int[INITIAL_SIZE];
    m_len = 0;
    m_max = INITIAL_SIZE;
}

DynamicArray::DynamicArray(const int* a, int n)
{
    m_a = new int[INITIAL_SIZE];
    m_max = INITIAL_SIZE;
    if (n <= 0)
        m_len = 0;
    else {
        m_len = n;
        for (int i = 0; i < n; ++i)
            m_a[i] = a[i];
    }
}

DynamicArray::DynamicArray(const DynamicArray& da)
{
    m_a = new int[INITIAL_SIZE];
    m_len = da.m_len;
    m_max = da.m_max;

    for (int i = 0; i < INITIAL_SIZE && i < m_len; ++i)
        m_a[i] = da.m_a[i];
}

DynamicArray::~DynamicArray()
{
    delete[] m_a;
}

void DynamicArray::PushBack(int value)
{
    m_a[m_len++] = value;
}

int DynamicArray::GetAt(int index)
{
    return m_a[index];
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& da)
{
    if (da.m_len == 0)
        std::cout << '\n';
    else 
        for (int i = 0; i < da.m_len; ++i)
            os << da.m_a[i] << (i == da.m_len - 1 ? '\n' : ' ');
    return os;
}

void DynamicArray::Info()
{
    std::cout << "\tMax: " << m_max
              << "\n\tLength: " << m_len
              << "\n\tData: " << *this;
}