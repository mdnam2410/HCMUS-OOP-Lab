#include "Farm.h"
#include "Random.h"

#include <iostream>

// -- Constructors and destructor

Farm::Farm(int numOfLivestocks) : m_livestocks{}
{
    Random rAnimal;
    Random rGender;

    for (int i = 0; i < numOfLivestocks; ++i) {
        int gender = rGender.next(2);
        switch (rAnimal.next(3)) {
        case Livestock::CATTLE:
            m_cattles.push_back(new Cattle(gender));
            break;
        case Livestock::SHEEP:
            m_sheeps.push_back(new Sheep(gender));
            break;
        case Livestock::GOAT:
            m_goats.push_back(new Goat(gender));
            break;
        }
    }
}

Farm::~Farm()
{
    Farm::cleanUp(m_cattles);
    Farm::cleanUp(m_sheeps);
    Farm::cleanUp(m_goats);
}

// -- Public member functions

int Farm::numOfLivestocks() const
{
    return numOfCattles() + numOfGoats() + numOfSheeps();
}

int Farm::numOfCattles() const
{
    return m_cattles.size();
}

int Farm::numOfSheeps() const
{
    return m_sheeps.size();
}

int Farm::numOfGoats() const
{
    return m_goats.size();
}

double Farm::totalMilk() const
{
    return Farm::milk(m_cattles) + Farm::milk(m_sheeps) + Farm::milk(m_goats);
}

void Farm::check() const
{
    int i = 0;
    for (const auto &cattle : m_cattles) {
        std::cout << "[#" << i++ << "]: cattle, "
                  << (cattle->gender() == MALE ? "male" : "female") << ", "
                  << (cattle->isHungry() ? "is hungry" : "not hungry") << ", "
                  << "make sound: ";
        cattle->makeSound();
    }

    for (const auto &sheep : m_sheeps) {
        std::cout << "[#" << i++ << "]: sheep, "
                  << (sheep->gender() == MALE ? "male" : "female") << ", "
                  << (sheep->isHungry() ? "is hungry" : "not hungry") << ", "
                  << "make sound: ";
        sheep->makeSound();
    }

    for (const auto &goat : m_goats) {
        std::cout << "[#" << i++ << "]: goat, "
                  << (goat->gender() == MALE ? "male" : "female") << ", "
                  << (goat->isHungry() ? "is hungry" : "not hungry") << ", "
                  << "make sound: ";
        goat->makeSound();
    }
}

void Farm::breedingSeason()
{
    Farm::breed(m_cattles);
    Farm::breed(m_sheeps);
    Farm::breed(m_goats);
}
