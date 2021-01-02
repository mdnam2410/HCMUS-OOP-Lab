#ifndef _CATTLE_H
#define _CATTLE_H

#include "Livestock.h"

#include <vector>

class Cattle : public Livestock
{
public:
    Cattle(bool gender, bool isHungry = true);

    std::vector<Cattle*> giveBirth() const;

    //Cattle** t_giveBirth(int &numOfOffsprings) const;

    double produceMilk() const override;

    void makeSound() const override;

    int type() const override;

    Cattle* giveBirthOnce() const override;
private:
};

#endif
