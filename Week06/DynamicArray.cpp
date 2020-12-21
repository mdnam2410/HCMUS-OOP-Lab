#include "DynamicArray.h"

const int DynamicArray::INITIAL_SIZE = 128;

DynamicArray::DynamicArray()
{
    m_data = new int[INITIAL_SIZE];
    m_size = 0;
    m_max = INITIAL_SIZE;
}

DynamicArray::DynamicArray(int new_size) : m_data {nullptr}, m_size {0}, m_max {INITIAL_SIZE}
{
    resize(new_size);
}

DynamicArray::DynamicArray(const int *a, int n) : DynamicArray(n)
{
    for (int i = 0; i < n; ++i)
        m_data[i] = a[i];
}

DynamicArray::DynamicArray(const DynamicArray& array) : DynamicArray(array.m_size)
{
    for (int i = 0; i < m_size; ++i)
        m_data[i] = array.m_data[i];
}

DynamicArray::~DynamicArray()
{
    delete[] m_data;
}

void DynamicArray::reallocate(int new_max_size)
{
    if (new_max_size > 0) {
        int *temp = new int[new_max_size]{};
        if (m_data) {
            for (int i = 0; i < m_size; ++i)
                temp[i] = m_data[i];
            delete[] m_data;
        }
        m_data = temp;
    }
}

bool DynamicArray::is_empty() const
{
    return m_size == 0;
}

int DynamicArray::size() const
{
    return m_size;
}

void DynamicArray::resize(int new_size)
{
    if (new_size < 0)
        throw "Cannot resize with negative value";
    m_size = new_size;
    int level = new_size / INITIAL_SIZE;
    m_max = (level + 1) * INITIAL_SIZE;
    reallocate(m_max);
}

void DynamicArray::push_back(int value)
{
    if (m_size + 1 >= m_max) {
        m_max += INITIAL_SIZE;
        reallocate(m_max + INITIAL_SIZE);
    }
    m_data[m_size++] = value;
}

void DynamicArray::pop_back()
{
    if (m_size == 0)
        throw "Array underflow";
    --m_size;
}

void DynamicArray::shrink_to_fit()
{
    int level = m_size / INITIAL_SIZE;
    /// max is always greater or equal level + 1, and the best is to keep max = level + 1
    if (m_max / INITIAL_SIZE != level + 1) {
        m_max = (level + 1) * INITIAL_SIZE;
        reallocate(m_max);
    }
}

int DynamicArray::get_at(int index) const
{
    if (index < 0 || index >= m_size)
        throw "Index out of bound";
    return m_data[index];
}

std::ostream& operator<<(std::ostream& os, const DynamicArray& da)
{
    os << '[';
    for (int i = 0; i < da.m_size; ++i)
        os << da.m_data[i] << (i == da.m_size - 1 ? "" : ", ");
    os << ']';
    return os;
}

void DynamicArray::info() const
{
    std::cout << "data: " << *this << '\n'
              << "size: " << m_size << '\n'
              << "max: " << m_max << '\n';
}
