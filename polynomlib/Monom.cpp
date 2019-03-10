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
    pow = A.pow;
}

Monom::~Monom()
{
  if (pow != NULL)
    delete pow;
}