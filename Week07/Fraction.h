#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

class Fraction
{
public:
    static Fraction* Parse(const std::string &input);
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

    std::string ToString() const;

    friend std::ostream& operator<<(std::ostream &os, const Fraction &fraction);
};

#endif
