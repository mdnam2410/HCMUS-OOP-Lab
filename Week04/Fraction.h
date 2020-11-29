#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
	int* m_nom;
	int* m_denom;

public:
	Fraction();
	
	Fraction(int value);
	
	Fraction(int nom, int denom);

	Fraction(const Fraction& f);

	~Fraction();
	
	void makeDenominatorPositive();

	int getNom() const;

	int getDenom() const;

	void setNom(int nom);

	bool setDenom(int denom);
	
	std::string ToString() const;
};

#endif