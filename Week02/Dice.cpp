#include "Dice.h"

#include "Random.h"

Dice::Dice()
{
    m_roll_count = 0;
}

int Dice::roll()
{
    ++m_roll_count;
    Random r;
    return r.next(6) + 1;
}

int Dice::roll_times() const
{
    return m_roll_count;
}