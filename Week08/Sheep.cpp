#include "Sheep.h"
#include "Random.h"

#include <iostream>
#include <random>
#include <vector>

// -- Constructors

Sheep::Sheep(bool gender, bool isHungry)
    : Livestock(gender, isHungry)
{
    m_maxMilkSupply = 10.0;
    m_maxChildDeliverOnce = 4;
}

// -- Public member functions

Sheep* Sheep::giveBirthOnce() const
{
    Random r;
    return new Sheep(r.next(2));
}

double Sheep::produceMilk() const
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> urd(0.0, m_maxMilkSupply);
    return urd(mt);
}

void Sheep::makeSound() const
{
    if (m_isHungry)
        std::cout << "sheep" << '\n';
}

int Sheep::type() const
{
    return Livestock::SHEEP;
}
