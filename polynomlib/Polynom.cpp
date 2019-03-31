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
  //need protection
  for (int i = 0; i < A.GetLen(); i++)
    InsLast(A.GetValue(i));
}

Polynom & Polynom::operator=(const Polynom& A)
{
  //
  return *this;
}

Monom Polynom::operator[](int _pos)
{
  return GetValue(_pos);
}

Polynom Polynom::operator*(const Polynom& A)
{
  //
  return Polynom();
}

Polynom Polynom::operator+(const Polynom& A)
{
  //
  return Polynom();
}

Polynom Polynom::operator-(const Polynom& A)
{
  //
  return Polynom();
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
      InsCustom(tmp + A, i);
      return *this;
    }
  }

  InsLast(A);
  return *this;
}
