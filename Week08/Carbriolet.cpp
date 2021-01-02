#include "Carbriolet.h"

#include <iostream>

void Carbriolet::startEngine() const
{
    std::cout << "Removing roof\n";
    Car::startEngine();
}
