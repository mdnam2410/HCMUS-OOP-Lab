#ifndef _GOAT_H
#define _GOAT_H

#include "Livestock.h"

#include <vector>

class Goat : public Livestock
{
public:
    Goat(bool gender, bool isHungry = true);

    std::vector<Goat*> giveBirth() const;

    double produceMilk() const;

    void makeSound() const;

    int type() const;

    Goat* giveBirthOnce() const;
};

#endif
