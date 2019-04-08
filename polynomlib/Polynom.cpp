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
  while(A.GetLen() != 0)
    this->DelFirst();

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
    for (int j = 0; i < len2; j++)
      res += this->GetValue(i) * A.GetValue(j);
    

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
    bool isComp = 1;
    if ((*this)[i].GetN() != A.GetN())
      isComp = 0;
    for (int j = 0; j < A.GetN() && isComp; j++)
      if ((((*this)[i]).GetPow())[j] != (A.GetPow())[j])
        isComp = 0;

    if (isComp)
    {
      Monom tmp = GetValue(i);
      DelCustom(i);
      if ((tmp + A).GetCon() != 0)
        InsCustom(tmp + A, i);
      return *this;
    }
  }

  InsLast(A);
  return *this;
}
