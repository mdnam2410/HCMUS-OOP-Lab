#include "Fraction.h"
#include "Random.h"

#include <time.h>
#include <vector>
    
constexpr int MAX_RANDOM_VECTOR_SIZE = 40;

void cau_1()
{
    Random random;
    int n = random.next(MAX_RANDOM_VECTOR_SIZE) + 1;
    std::cout << "Integer n: " << n << '\n';

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = random.next();
    
    std::cout << "Randomly-created list of integers: ";
    for (auto &num : v)
        std::cout << num << ' ';
    std::cout << '\n';

    int m = random.next(MAX_RANDOM_VECTOR_SIZE);
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

void cau_2()
{
    const int MAX_FRACTION_ELEMENT_VALUE = 100;
    Random random;
    int n = random.next(MAX_RANDOM_VECTOR_SIZE) + 1;
    std::cout << "Integer n: " << n << '\n';

    try {
        std::vector<Fraction> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = Fraction(random.next(MAX_FRACTION_ELEMENT_VALUE), random.next(MAX_FRACTION_ELEMENT_VALUE) + 1);

        std::cout << "Randomly-created list of fractions: ";
        for (auto &fraction : v)
            std::cout << fraction << ' ';
        std::cout << '\n';
        
        int m = random.next(MAX_RANDOM_VECTOR_SIZE);
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


int main()
{
    srand(time(nullptr));
    cau_2();
    return 0;
}