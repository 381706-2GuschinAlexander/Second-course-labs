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
};