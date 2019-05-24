#include "Polynom.h"

Polynom::Polynom() : List<Monom>()
{

}

Polynom::Polynom(const Polynom& A)
{
  for (int i = 0; i < A.GetLen(); i++)
    InsLast(A.GetValue(i));
}

Polynom::Polynom(const List<Monom>& A)
{
  for (int i = 0; i < A.GetLen(); i++)
    *this += A.GetValue(i);
}

Polynom & Polynom::operator=(const Polynom& A)
{
  while(GetLen() != 0)
    DelFirst();

  for (int i = 0; i < A.GetLen(); i++)
    InsLast(A.GetValue(i));

  return *this;
}

Monom Polynom::operator[](int _pos)
{
  return GetValue(_pos);
}

Polynom Polynom::operator*(const Polynom& A)
{
  Polynom res;
  int len1 = this->GetLen();
  int len2 = A.GetLen();

  for(int i = 0; i < len1; i++)
    for (int j = 0; j < len2; j++)
    {
      Monom tmp = (this->GetValue(i) * A.GetValue(j));
      res += tmp;
    }

  return res;
}

Polynom Polynom::operator+(const Polynom& A)
{
  Polynom res(*this);
  for (int i = 0; i < A.GetLen(); i++)
    res += A.GetValue(i);

  return res;
}

Polynom Polynom::operator-(const Polynom& A)
{
  Polynom res(*this);
  for (int i = 0; i < A.GetLen(); i++)
  {
    Monom tmp(A.GetValue(i));
    tmp.SetCon(-tmp.GetCon());
    res += tmp;
  }

  return res;
}

Polynom& Polynom::operator+=(const Monom & A)
{
  for (int i = 0; i < this->len; i++)
  {
    bool isComp = 0;
    Monom tmp = GetValue(i);
    if (tmp.GetN() == A.GetN())
    {
      isComp = 1;
      for (int i = 0; i < tmp.GetN(); i++)
        if (tmp.GetPow()[i] != A.GetPow()[i])
          isComp = 0;
    }
    
    if (isComp)
    {
      DelCustom(i);
      if (tmp.GetCon() != -A.GetCon())
        InsCustom(tmp + A, i);

      return *this;
    }
  }

  InsLast(A);
  return *this;
}
