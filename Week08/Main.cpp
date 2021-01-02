#include "Car.h"
#include "Carbriolet.h"

#include "Farm.h"

#include <iostream>
#include <vector>

bool askContinue()
{
    do {
        std::cout << "\nContinue? [Y/N]: ";
        char c;
        std::cin >> c;
        if (c != 'Y' && c != 'N')
            continue;
        return c == 'Y';
    } while (true);
}

int main()
{
    srand(time(nullptr));

    std::cout << "\n========== Exercise 1 ==========\n";
    Car *car = new Car;
    car->startEngine();

    Carbriolet *carbriolet = new Carbriolet;
    carbriolet->startEngine();

    delete car;
    delete carbriolet;

    askContinue();
    
    std::cout << "\n========== Exercise 2 ==========\n";
    Farm farm(12);
    std::cout << "The farm has:\n";
    farm.check();
    std::cout << "Cattles: " << farm.numOfCattles() << '\n'
              << "Sheeps: " << farm.numOfSheeps() << '\n'
              << "Goats: " << farm.numOfGoats() << '\n';
    std::cout << "Total milk collected: " << farm.totalMilk() << '\n';

    farm.breedingSeason();
    std::cout << "\nAfter breeding, the farm has:\n";
    farm.check();
    std::cout << "Cattles: " << farm.numOfCattles() << '\n'
              << "Sheeps: " << farm.numOfSheeps() << '\n'
              << "Goats: " << farm.numOfGoats() << '\n';
    std::cout << "Total milk collected: " << farm.totalMilk() << '\n';
    return 0;

}