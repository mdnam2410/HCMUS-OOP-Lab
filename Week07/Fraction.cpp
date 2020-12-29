#include "Fraction.h"

#include <cmath>
#include <iostream>
#include <sstream>

int gcd(int a, int b)
{
    return a == 0 ? std::abs(b) : (b == 0 ? std::abs(a) : gcd(b, a % b));
}

Fraction* Fraction::Parse(const std::string &input)
{
    std::size_t slash = input.find('/');
    if (slash == std::string::npos)
        return nullptr;
    
    try {
        int nom = std::stoi(input.substr(0, slash));
        int denom = std::stoi(input.substr(slash + 1));
        return new Fraction(nom, denom);
    } catch (...) {
        return nullptr;
    }
}

Fraction::Fraction() : nom(0), denom(1) {}

Fraction::Fraction(int value) : nom(value), denom(1) {}

Fraction::Fraction(int nominator, int denominator) : nom(nominator), denom(denominator)
{
    if (denom == 0)
        throw "Fraction with zero denominator";
    else if (denom < 0)
        make_denom_positive();
}

void Fraction::make_denom_positive()
{
    if (denom < 0) {
        nom = -nom;
        denom = -denom;
    }
}

Fraction Fraction::reciprocal() const
{
    return Fraction(denom, nom);
}

void Fraction::reduce()
{
    int g = gcd(nom, denom);
    nom /= g;
    denom /= g;
}

Fraction Fraction::get_reduced_copy() const
{
    Fraction clone = *this;
    clone.reduce();
    return clone;
}

std::ostream& operator<<(std::ostream &os, const Fraction &fraction)
{
    os << fraction.nom;
    if (fraction.denom != 1)
        os << '/' << fraction.denom;
    return os;
}

std::string Fraction::ToString() const
{
    std::stringstream ss;
    ss << nom << '/' << denom;
    return ss.str();
}
