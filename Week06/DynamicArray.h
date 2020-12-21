#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray
{
private:
    static const int INITIAL_SIZE;
    int* m_data;
    int  m_size;
    int  m_max;

    /**
     * @brief Reallocate m_data with new_max_size elements, m_size and m_max are unchanged.
     *        If new_max_size <= 0, nothing is changed.
     * 
     * @param new_max_size New size to reallocate
     */
    void reallocate(int new_max_size);

public:
    /**
     * @brief Default constructor for Dynamic Array, preallocate the array with INITIAL_SIZE elements.
     * 
     */
    DynamicArray();

    /**
     * @brief Construct a new Dynamic Array object with NEW_SIZE elements with default value 0
     * 
     * @param new_size Must be greater than 0
     */
    DynamicArray(int new_size);

    /**
     * @brief Construct a new Dynamic Array object by copy from the array a
     * 
     * @param a The array to copy from
     * @param n Size of a
     */
    DynamicArray(const int *a, int n);

    /**
     * @brief Copy constructor
     * 
     * @param array 
     */
    DynamicArray(const DynamicArray& array);

    ~DynamicArray();

    bool is_empty() const;

    /**
     * @brief Return the current size of the array.
     * 
     * @return int 
     */
    int size() const;

    /**
     * @brief Resize the array with NEW_SIZE, reallocate m_data if neccessary
     * 
     * @param new_size New size
     */
    void resize(int new_size);

    /**
     * @brief Add a new element to the back of the array.
     * 
     * @param value The value of the new element to be added
     */
    void push_back(int value);

    /**
     * @brief Delete an element from the back of the array.
     *        If the array is currently empty, underflow will occur.
     * 
     * @throw const char*
     */
    void pop_back();

    /**
     * @brief Shrink the allocated memory to best fit the current size of the array.
     * 
     */
    void shrink_to_fit();

    /**
     * @brief Get the element at INDEX
     * 
     * @param index 
     * @return int 
     */
    int get_at(int index) const;

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& da);

    void info() const;
};

#endif
