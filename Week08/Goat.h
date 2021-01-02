#ifndef _GOAT_H
#define _GOAT_H

#include "Livestock.h"

#include <vector>

class Goat : public Livestock
{
public:
    Goat(bool gender, bool isHungry = true);

    std::vector<Goat*> giveBirth() const;

    double produceMilk() const override;

    void makeSound() const override;

    int type() const override;

    Goat* giveBirthOnce() const override;
};

#endif
