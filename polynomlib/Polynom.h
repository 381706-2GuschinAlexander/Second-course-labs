#pragma once
#include "Monom.h"
#include "List.h"

class Polynom : public List<Monom>
{
public:
  Polynom();
  Polynom(const Polynom& A);
  Polynom(const List<Monom>& A);
  Polynom& operator=(const Polynom& A);
  Monom operator[](int _pos);
  Polynom operator*(const Polynom& A);
  Polynom operator+(const Polynom& A);
  Polynom operator-(const Polynom& A);
  Polynom& operator+=(const Monom& A);
  friend std::ostream& operator<<(std::ostream& os, const Polynom& pol)
  {
    for (int i = 0; i < pol.GetLen() - 1; i++)
      os << pol.GetValue(i) << " + ";
    os << pol.GetValue(pol.GetLen() - 1);
    return os;
  }
};