#include "Cattle.h"
#include "Random.h"

#include <iostream>
#include <random>
#include <vector>

// -- Constructors

Cattle::Cattle(bool gender, bool isHungry)
    : Livestock(gender, isHungry)
{
    m_maxMilkSupply = 20.0;
    m_maxChildDeliverOnce = 2;
}

// -- Public member functions

Cattle* Cattle::giveBirthOnce() const
{
    Random r;
    return new Cattle(r.next(2));
}

double Cattle::produceMilk() const
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> urd(0.0, m_maxMilkSupply);
    return urd(mt);
}

void Cattle::makeSound() const
{
    if (m_isHungry)
        std::cout << "cattle" << '\n';
}

int Cattle::type() const
{
    return Livestock::CATTLE;
}
