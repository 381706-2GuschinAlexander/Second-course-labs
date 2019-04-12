#pragma once
#include "exception.h"
#include <iostream>
class Monom
{
protected:
  int n; //length of powers
  double con;//const
  int* pow;//pointer on powers
public:
  Monom();
  Monom(int _n, double _con, int* _pow);
  Monom(const Monom& A);
  ~Monom();
  int GetN() const;
  double GetCon() const;
  int* GetPow() const;
  void SetN(int _n);
  void SetCon(double _con);
  void SetPow(int* _pow);
  Monom& operator=(const Monom& A);
  Monom operator+(const Monom& A);
  Monom operator-(const Monom& A);
  Monom operator*(const Monom& A);
  bool operator==(const Monom& A);
  bool operator!=(const Monom& A);
  bool operator>(const Monom& A);
  bool operator<(const Monom& A);
  friend std::ostream& operator<<(std::ostream& os, const Monom& A)
  {
    os << A.con << '*';
    for (int i = 0; i < A.n - 1; i++)
      os << "x" << i << "^" << A.pow[i] << '*';
    os << "x" << A.n - 1 << "^" << A.pow[A.n - 1];
    return os;
  }
};
