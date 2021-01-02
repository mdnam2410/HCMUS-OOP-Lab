#include "Goat.h"
#include "Random.h"

#include <iostream>
#include <random>
#include <vector>

// -- Constructors

Goat::Goat(bool gender, bool isHungry)
    : Livestock(gender, isHungry)
{
    m_maxMilkSupply = 10.0;
    m_maxChildDeliverOnce = 5;
}

// -- Public member functions

Goat* Goat::giveBirthOnce() const
{
    Random gender;
    return m_gender == FEMALE ? new Goat(gender.next(2)) : nullptr;
}

double Goat::produceMilk() const
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> urd(0.0, m_maxMilkSupply);
    return urd(mt);
}

void Goat::makeSound() const
{
    if (m_isHungry)
        std::cout << "goat" << '\n';
}

int Goat::type() const
{
    return Livestock::GOAT;
}
