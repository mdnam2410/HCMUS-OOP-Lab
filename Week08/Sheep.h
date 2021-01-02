#ifndef _SHEEP_H
#define _SHEEP_H

#include "Livestock.h"

#include <vector>

class Sheep : public Livestock
{
public:
    Sheep(bool gender, bool isHungry = true);

    std::vector<Sheep*> giveBirth() const;

    double produceMilk() const override;

    void makeSound() const override;

    int type() const override;

    Sheep* giveBirthOnce() const override;
private:
};

#endif
