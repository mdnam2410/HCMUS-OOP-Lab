#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
    int nom;
    int denom;

    void make_denom_positive();

public:
    Fraction();

    Fraction(int value);

    Fraction(int nominator, int denominator);

    Fraction reciprocal() const;
    
    void reduce();

    Fraction get_reduced_copy() const;

    friend std::ostream& operator<<(std::ostream &os, const Fraction &fraction);
};

#endif
