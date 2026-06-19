#pragma once
#include <string>

class Fraction
{
private:
    int num; // numerator
    int den; // denominator

    void normalize();

public:
    Fraction(int x = 0, int y = 1);

    // Convert double to Fraction.
    Fraction(double x);

    std::string toString() const;

    Fraction operator+(const Fraction &f) const;
    Fraction operator-(const Fraction &f) const;
    Fraction operator*(const Fraction &f) const;
    Fraction operator/(const Fraction &f) const;
};
