#pragma once
#include "TVector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
	TMatrix(int n);
	TMatrix(const TMatrix<T>& A);
	TMatrix(const TVector<TVector<T> >& A);
	bool operator==(const TMatrix<T>& A);
  bool operator!=(const TMatrix<T>& A);
	TMatrix& operator=(const TMatrix<T>& A);
	TMatrix operator+(const TMatrix<T>& A);
	TMatrix operator-(const TMatrix<T>& A);
	TMatrix operator*(const TMatrix<T>& A);
  TMatrix operator/(const TMatrix<T>& B);

  friend std::istream & operator>>(std::istream &in, TMatrix<T> &A)
  {
    for (int i = 0; i < A.l; i++)
      in >> A[i];
    return in;
  }

  friend std::ostream & operator<<(std::ostream &out,const TMatrix<T> &A)
  {
    for (int i = 0; i < A.l; i++)
    {
      int tmp = A[i].GetPos();
      for (int j = 0; j < tmp; j++)
        std::cout << 0 << " ";
      out << A[i] << std::endl;
    }
    return out;
  }
};

template <class T>
TMatrix<T>::TMatrix(int n):TVector<TVector<T> >(n)
{
	for(int i = 0; i < n; i++)
    this->p[i] = TVector<T>(n - i, i);
}


template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& A):TVector<TVector<T> >(A)
{

}


template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> >& A) :TVector<TVector<T> >(A)
{
}

template <class T>
bool  TMatrix<T>::operator == (const TMatrix<T>& A)
{
	if (this->l != A.l)
		return false;

	for (int i = 0; i < this->l; i++)
		if (this->p[i] != A.p[i])
			return false;

	return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix<T>& A)
{
  if (this->l != A.l)
    return true;


  for (int i = 0; i < this->l; i++)
    if (this->p[i] != A.p[i])
      return true;

  return false;
}

template <class T>
TMatrix<T>&  TMatrix<T>::operator = (const TMatrix& A)
{
	if (this->l != A.l)
	{
		
		delete[] this->p;
    this->l = A.l;
    this->p = new TVector<T>[this->l];
	}
		
	for (int i = 0; i < this->l; i++)
    this->p[i] = A.p[i];

	return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator + (const TMatrix<T>& A)
{
	if (this->l != A.l)
		throw(__DIFF_SIZE);

	TVector<TVector<T> > temp(this->l);
	for (int i = 0; i < this->l; i++)
		temp[i] = this->p[i] + A.p[i];

	return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator - (const TMatrix<T>& A)
{
	if (this->l != A.l)
		throw(__DIFF_SIZE);

	TMatrix<T> temp(this->l);
	for (int i = 0; i < this->l; i++)
		temp[i] = this->p[i] - A.p[i];

	return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator * (const TMatrix<T>& A)
{
	if (this->l != A.l)
		throw(__DIFF_SIZE);

	TMatrix<T> temp(this->l);
  for (int i = 0; i < this->l; i++)
    for (int j = i; j < this->l; j++)
      for(int k = i; k < j + 1; k++)
        temp[i][j] += this->p[i][k] * A[k][j];

	return temp;
}

template<class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T>& B)
{
  if (this->l != B.l)
    throw(__DIFF_SIZE);

  if (this->l <= 1)
    return (*this) * B;

  T det = B[0][0];
  for (int i = 1; i < this->l; i++)
    det = det * B[i][i];

  if (det == 0)
    throw(__INVALID_OBJECT);

  TMatrix<T> A(B);
  TMatrix<T> _A(A.l);

  for (int i = 0; i < this->l; i++)
  {
    _A[i][i] = 1;
    T k = A[i][i];
    for (int j = i; j < this->l; j++)
    {
      A[i][j] = A[i][j] / k;
      _A[i][j] = _A[i][j] / k;
    }
  }
  for (int j = 1; j < this->l; j++)
    for (int i = j - 1; i >= 0; i--)
    {
      T tmp = A[i][j];
      for (int k = j; k < this->l; k++)
      {
        _A[i][k] -= _A[j][k] * tmp;
        A[i][k] = A[i][k] - A[j][k] * tmp;
      }
    }

  return (*this) * _A ;
}
