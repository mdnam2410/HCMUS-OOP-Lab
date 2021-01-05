#ifndef _CATTLE_H
#define _CATTLE_H

#include "Livestock.h"

#include <vector>

class Cattle : public Livestock
{
public:
    Cattle(bool gender, bool isHungry = true);

    std::vector<Cattle*> giveBirth() const;

    double produceMilk() const;

    void makeSound() const;

    int type() const;

    Cattle* giveBirthOnce() const;
};

#endif
