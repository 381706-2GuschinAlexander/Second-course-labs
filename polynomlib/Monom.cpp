#include "Monom.h"

Monom::Monom()
{
  n = 0;
  con = 0;
  pow = NULL;
}

Monom::Monom(int _n, double _con, int* _pow)
{
  if (_n <= 0)
    throw(1);

  con = _con;
  n = _n;
  pow = new int[_n];

  try
  {
    for (int i = 0; i < _n; i++)
    {
      if (_pow[i] < 0)
        throw(1);

      pow[i] = _pow[i];
    }
  }
  catch(int e)
  {
    throw(e);
  }
}

Monom::Monom(const Monom& A)
{
  n = A.n;
  con = A.con;
  pow = new int[n];
  for (int i = 0; i < n; i++)
    pow[i] = A.pow[i];
}

Monom::~Monom()
{
  if (pow != NULL)
    delete pow;
}

int Monom::GetN() const
{
  return n;
}

double Monom::GetCon() const
{
  return con;
}

int* Monom::GetPow() const
{
  /*
  int* p = new int[n];
  for (int i = 0; i < n; i++)
    p[i] = pow[i];
  return p;
  */

  return pow;
}

void Monom::SetN(int _n)
{
  if (_n < 0)
    throw(1);
  else if (_n == 0)
  {
    if(pow != NULL)
      delete pow;
  }
  else 
  {
    int* tmp = new int[n];
    for (int i = 0; i < n; i++)
      tmp[i] = pow[i];
    delete pow;

    pow = new int[_n];
    int firstInd = (n > _n ? _n : n);
    int secondInd = (n <= _n ? _n : n);

    for (int i = 0; i < firstInd; i++)
      pow[i] = tmp[i];
    if (_n > n)
      for (int i = firstInd; i < secondInd; i++)
        pow[i] = 0;

    n = _n;
    delete tmp;
  }
}

void Monom::SetCon(double _con)
{
  con = _con;
}

void Monom::SetPow(int* _pow)
{
  try
  {
    for (int i = 0; i < n; i++)
    {
      if (_pow[i] < 0)
        throw(1);

      pow[i] = _pow[i];
    }
  }
  catch (int e)
  {
    throw(e);
  }
}

Monom& Monom::operator=(const Monom& A)
{
  if (pow != NULL)
    delete pow;
  n = A.n;
  con = A.con;
  pow = new int[A.n];
  for (int i = 0; i < n; i++)
    pow[i] = A.pow[i];

  return *this;
}

Monom Monom::operator+(const Monom& A)
{
  
  if (n != A.n)
    throw(1);

  Monom res(*this);
  for (int i = 0; i < n; i++)
    if (pow[i] != A.pow[i])
      throw(1);

  res.con += A.con;
  return res;
}

Monom Monom::operator-(const Monom& A)
{

  if (n != A.n)
    throw(1);

  Monom res(*this);
  for (int i = 0; i < n; i++)
    if (pow[i] != A.pow[i])
      throw(1);

  res.con -= A.con;
  return res;
}

Monom Monom::operator*(const Monom& A)
{
  int minN = (A.GetN() < GetN() ? A.GetN() : GetN());
  bool flag = (A.GetN() >= GetN() ? 1 : 0);

  Monom res;
  if (flag == true)
  {
    res = A;
    res.con *= this->con;
    for (int i = 0; i < minN; i++)
      res.pow[i] += pow[i];
  }
  else
  {
    res = *this;
    res.con *= A.con;
    for (int i = 0; i < minN; i++)
      res.pow[i] += A.pow[i];
  }

  

  return res;
}

bool Monom::operator==(const Monom& A)
{
  if (con != A.con)
    return false;
  if (n != A.n)
    return false;
  for (int i = 0; i < A.n; i++)
    if (pow[i] != A.pow[i])
      return false;

  return true;
}

bool Monom::operator!=(const Monom & A)
{
  return !(*this == A);
}

bool Monom::operator>(const Monom & A)
{
  if (n != A.n)
    throw(1);
  for (int i = 0; i < A.n; i++)
    if (pow[i] != A.pow[i])
      throw(1);

  bool res;
  (con > A.con ? res = true : res = false);
  return res;
}

bool Monom::operator<(const Monom & A)
{
  if (n != A.n)
    throw(1);
  for (int i = 0; i < A.n; i++)
    if (pow[i] != A.pow[i])
      throw(1);

  bool res;
  (con < A.con ? res = true : res = false);
  return res;
}
