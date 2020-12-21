#include "DynamicArray.h"
#include "Fraction.h"
#include "Random.h"

#include <time.h>
#include <vector>
    
constexpr int MAX_VECTOR_SIZE = 40;
constexpr int RANDOM_MAX = 100;

template <typename T>
T input(const char *prompt)
{
    std::cout << prompt;
    T obj;
    std::cin >> obj;
    return obj;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool ask_continue()
{
    do {
        std::cout << "\nContinue? [Y/N]: ";
        char c;
        std::cin >> c;
        if (c != 'Y' && c != 'N')
            continue;
        return c == 'Y';
    } while (true);
}

void exercise_1()
{
    std::cout << "\n====== EXERCISE 1 ======\n";
    Random random;
    int n = random.next(MAX_VECTOR_SIZE) + 1;
    std::cout << "Integer n: " << n << '\n';

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = random.next(RANDOM_MAX);
    
    std::cout << "Randomly-created list of integers: ";
    for (auto &num : v)
        std::cout << num << ' ';
    std::cout << '\n';

    int m = random.next(MAX_VECTOR_SIZE);
    std::cout << "Integer m: " << m << '\n';
    try {
        if (m >= v.size())
            throw "Index out of bound";
        else
            std::cout << "Element at index m: " << v.at(m) << '\n';
    } catch (const char *error) {
        std::cerr << "Error: " << error << '\n';
    }
}   

void exercise_2()
{
    std::cout << "\n====== EXERCISE 2 ======\n";
    const int MAX_FRACTION_ELEMENT_VALUE = 100;
    Random r;
    int n = r.next(MAX_VECTOR_SIZE) + 1;
    std::cout << "Integer n: " << n << '\n';

    try {
        std::vector<Fraction> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = Fraction(r.next(RANDOM_MAX), r.next(RANDOM_MAX) + 1);

        std::cout << "Randomly-created list of fractions: ";
        for (auto &fraction : v)
            std::cout << fraction << ' ';
        std::cout << '\n';
        
        int m = r.next(MAX_VECTOR_SIZE);
        std::cout << "Integer m: " << m << '\n';

        if (m >= v.size())
            throw "Index out of bound";
        else
            std::cout << "Fraction at index m: " << v[m]
                      << ", its reciprocal: " << v[m].reciprocal()
                      << ", its reduced version: " << v[m].get_reduced_copy() << '\n';
    } catch (const char *error) {
        std::cout << "Error: " << error << '\n';
    }
}

void exercise_3()
{
    std::cout << "\n====== EXERCISE 3 ======\n";
    std::cout << "0. Exit\n"
                 "1. Pop back\n"
                 "2. Push back\n"
                 "3. Shrink to fit\n"
                 "4. Access\n"
                 "5. Resize\n"
                 "6. Print info (the array, size, and max size)\n\n";
    
    DynamicArray da;
    std::cout << "Created an empty array.\n";
    int choice;
    do {
        choice = input<int>("Enter choice: ");
        try {
            switch (choice) {
            case 1:
                da.pop_back();
                std::cout << "Popped back successfully.\n";
                break;

            case 2: {
                int new_value = input<int>("Enter new value: ");
                da.push_back(new_value);
                std::cout << "Pushed back successfully.\n";
                break;
            }

            case 3:
                da.shrink_to_fit();
                std::cout << "Shrank successfully.\n";
                break;

            case 4: {
                int index = input<int>("Enter index: ");
                std::cout << "Element at " << index << ": " << da.get_at(index) << '\n';
                break;
            }

            case 5: {
                int new_size = input<int>("Enter new size: ");
                da.resize(new_size);
                std::cout << "Resized successfully.\n";
                break;
            }

            case 6:
                da.info();
                break;
            }
        } catch (const char *e) {
            std::cerr << "Error: " << e << '\n';
        }
        std::cout << '\n';
    } while (choice != 0);
}

int main()
{
    typedef void (*func_ptr_t)();
    func_ptr_t exercises[] = {exercise_1, exercise_2, exercise_3};
    int size = 3;
    
    for (int i = 0; i < size; ++i) {
        exercises[i]();
        if (i != size - 1)
            if (!ask_continue())
                exit(EXIT_SUCCESS);
    }
    return 0;
}