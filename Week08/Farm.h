#ifndef _FARM_H
#define _FARM_H

#include "Cattle.h"
#include "Goat.h"
#include "Livestock.h"
#include "Sheep.h"

#include "Random.h"

#include <vector>

class Farm
{
private:
    std::vector<Cattle*> m_cattles;
    std::vector<Sheep*> m_sheeps;
    std::vector<Goat*> m_goats;
    
private:
    template <typename T>
    static void breed(std::vector<T*> &animalList) {
        int oldSize = animalList.size();
        for (int i = 0; i < oldSize; ++i) {
            if (animalList[i]->gender() == FEMALE) {
                Random r;
                int offsprings = r.next(animalList[i]->maxOffspringsDeliverOnce());
                for (int j = 0; j < offsprings; ++j)
                    animalList.push_back(animalList[i]->giveBirthOnce());
            }
        }
    }

    template <typename T>
    static double milk(const std::vector<T*> &animalList) {
        double count = 0.0;
        for (const auto &animal : animalList)
            count += animal->produceMilk();
        return count;
    }

    template <typename T>
    static void cleanUp(std::vector<T*> &animalList) {
        for (auto &animal : animalList)
            delete animal;
    }

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
