#include "Fraction.h"

#include <sstream>

Fraction::Fraction()
{
    m_nom = new int(0);
    m_denom = new int(1);
}

Fraction::Fraction(int value) {
    m_nom = new int(value);
    m_denom = new int(1);
}

Fraction::Fraction(int nom, int denom)
{
    m_nom = new int(nom);
    m_denom = new int(denom);
    makeDenominatorPositive();
}

Fraction::Fraction(const Fraction& f)
{
    m_nom = new int(*f.m_nom);
    m_denom = new int(*f.m_denom);
}

Fraction::~Fraction()
{
    delete m_nom;
    delete m_denom;
}

void Fraction::makeDenominatorPositive()
{
    if (*m_denom < 0) {
        *m_nom = -*m_nom;
        *m_denom = -*m_denom;
    }
}

int Fraction::getNom() const
{
    return *m_nom;
}

int Fraction::getDenom() const
{
    return *m_denom;
}

void Fraction::setNom(int nom)
{
    *m_nom = nom;
}

bool Fraction::setDenom(int denom)
{
    if (denom == 0)
        return false;
    *m_denom = denom;
    makeDenominatorPositive();
    return true;
}

std::string Fraction::ToString() const
{
    std::stringstream ss;
    ss << *m_nom << '/' << *m_denom;
    return ss.str();
}
