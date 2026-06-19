/*
You can change Decimal to Fraction.
And you
*/

#include "Fraction.h"

#include <cstdlib>
#include <stdexcept>
#include <sstream>

namespace
{
int yuguri(int x, int y)
{
  if (y == 0)
    return x;
  return yuguri(y, x % y);
}
}

void Fraction::normalize()
{
  if (den == 0)
  {
    throw std::invalid_argument("denominator must not be zero");
  }

  if (den < 0)
  {
    num = -num;
    den = -den;
  }
  int g = yuguri(std::abs(num), std::abs(den));
  num /= g;
  den /= g;
}

Fraction::Fraction(int x, int y) : num(x), den(y)
{
  normalize();
}

// Convert double to Fraction.
Fraction::Fraction(double x)
{
  const int SCALE = 1000000; // precision
  num = static_cast<int>(x * SCALE);
  den = SCALE;
  normalize();
}

std::string Fraction::toString() const
{
  std::stringstream ss;
  ss << "(" << num << "/" << den << ")";
  return ss.str();
}

Fraction Fraction::operator+(const Fraction &f) const
{
  return Fraction(
      num * f.den + den * f.num,
      den * f.den);
}
Fraction Fraction::operator-(const Fraction &f) const
{
  return Fraction(
      num * f.den - den * f.num,
      den * f.den);
}
Fraction Fraction::operator*(const Fraction &f) const
{
  return Fraction(
      num * f.num,
      den * f.den);
}
Fraction Fraction::operator/(const Fraction &f) const
{
  return Fraction(
      num * f.den,
      den * f.num);
}
