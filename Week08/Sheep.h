#ifndef _SHEEP_H
#define _SHEEP_H

#include "Livestock.h"

#include <vector>

class Sheep : public Livestock
{
public:
    Sheep(bool gender, bool isHungry = true);

    std::vector<Sheep*> giveBirth() const;

    double produceMilk() const;

    void makeSound() const;

    int type() const;

    Sheep* giveBirthOnce() const;
};

#endif
