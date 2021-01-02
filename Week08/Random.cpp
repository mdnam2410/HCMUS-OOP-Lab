#include <stdlib.h>
#include <time.h>

#include "Random.h"

Random::Random()
{
}

Random::~Random()
{
}

int Random::next() const
{
    return rand();
}

int Random::next(int max) const
{
    return rand() % max;
}