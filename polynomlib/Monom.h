#pragma once
#include "exception.h"
#include <iostream>
class Monom
{
protected:
  int n;
  double con;
  int* pow;
public:
  Monom();
  Monom(int _n, double _con, int* _pow);
  Monom(const Monom& A);
  ~Monom();
  int GetN();
  double GetCon();
  int* GetPow();
  void SetN(int _n);
  void SetCon(double _con);
  void SetPow(int* _pow);
  Monom& operator=(const Monom& A);
  Monom operator+(const Monom& A);
  Monom operator-(const Monom& A);
  Monom operator*(const Monom& A);
  bool operator==(const Monom& A);
  bool operator>(const Monom& A);
  bool operator<(const Monom& A);
  //>> <<
};
