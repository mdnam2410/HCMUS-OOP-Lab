#ifndef DICE_H
#define DICE_H

class Dice
{
private:
    int m_roll_count;

public:
    Dice();

    int roll();

    int roll_times() const;
};

#endif