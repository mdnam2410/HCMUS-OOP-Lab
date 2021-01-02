#ifndef _FARM_H
#define _FARM_H

#include "Cattle.h"
#include "Goat.h"
#include "Livestock.h"
#include "Sheep.h"

#include <vector>

class Farm
{
private:
    std::vector<Livestock*> m_livestocks;

    int countAnimal(int type) const;

public:
    Farm(int numOfLivestocks);

    ~Farm();

    int numOfLivestocks() const;

    double totalMilk() const;

    int numOfCattles() const;

    int numOfSheeps() const;

    int numOfGoats() const;

    void check() const;

    void breedingSeason();
};

#endif
