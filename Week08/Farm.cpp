#include "Farm.h"
#include "Random.h"

#include <iostream>

// -- Constructors and destructor

Farm::Farm(int numOfLivestocks) : m_livestocks{}
{
    Random rAnimal;
    Random rGender;
    m_livestocks.reserve(numOfLivestocks);

    for (int i = 0; i < numOfLivestocks; ++i) {
        int gender = rGender.next(2);
        switch (rAnimal.next(3)) {
        case Livestock::CATTLE:
            m_livestocks.push_back(new Cattle(gender));
            break;
        case Livestock::SHEEP:
            m_livestocks.push_back(new Sheep(gender));
            break;
        case Livestock::GOAT:
            m_livestocks.push_back(new Goat(gender));
            break;
        }
    }
}

Farm::~Farm()
{
    for (auto &animal : m_livestocks)
        delete animal;
}

// -- Public member functions

int Farm::numOfLivestocks() const
{
    return m_livestocks.size();
}

int Farm::numOfCattles() const
{
    return countAnimal(Livestock::CATTLE);
}

int Farm::numOfSheeps() const
{
    return countAnimal(Livestock::SHEEP);
}

int Farm::numOfGoats() const
{
    return countAnimal(Livestock::GOAT);
}

double Farm::totalMilk() const
{
    double count = 0.0;
    for (const auto &animal : m_livestocks)
        count += animal->produceMilk();
    return count;
}

void Farm::check() const
{
    int i = 0;
    for (const auto &animal : m_livestocks) {
        std::cout << "[#" << i++ << "]: "
                  << (animal->gender() == MALE ? "male" : "female") << ", "
                  << (animal->isHungry() ? "is hungry" : "not hungry") << ", "
                  << "make sound: ";
        animal->makeSound();
    }
}

void Farm::breedingSeason()
{
    int oldSize = m_livestocks.size();
    for (int i = 0; i < oldSize; ++i) {
        if (m_livestocks[i]->gender() == FEMALE) {
            Random r;
            int numOfOffsprings = r.next(m_livestocks[i]->maxOffspringsDeliverOnce());
            for (int j = 0; j < numOfOffsprings; ++j)
                m_livestocks.push_back(m_livestocks[i]->giveBirthOnce());
        }
    }
}

// -- Private member functions

int Farm::countAnimal(int type) const
{
    int count = 0;
    for (const auto &animal : m_livestocks)
        if (animal->type() == type)
            ++count;
    return count;
}
