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
	TMatrix& operator=(const TMatrix<T>& A);
	TMatrix operator+(const TMatrix<T>& A);
	TMatrix operator-(const TMatrix<T>& A);
	TMatrix operator*(TMatrix<T>& A);
  TMatrix operator/(TMatrix<T>& B);
};

template <class T>
TMatrix<T>::TMatrix(int n):TVector<TVector<T> >(n)
{
	for(int i = 0; i < n; i++)
    this->p[i] = TVector<T>(n - i);
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
		throw(1);

	TVector<TVector<T> > temp(this->l);
	for (int i = 0; i < this->l; i++)
		temp[i] = this->p[i] + A.p[i];

	return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator - (const TMatrix<T>& A)
{
	if (this->l != A.l)
		throw(1);

	TMatrix<T> temp(this->l);
	for (int i = 0; i < this->l; i++)
		temp[i] = this->p[i] - A.p[i];

	return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator * (TMatrix<T>& A)
{
	if (this->l != A.l)
		throw(1);

	TMatrix<T> temp(this->l);
  for (int i = 0; i < this->l; i++)
    for (int j = 0; j < this->l - i; j++)
      for(int k = 0; j + i + k < this->l;k++)
        temp[i][j] += this->p[this->l - 1 - (j + k)][j] * A[i][j + k];

	return temp;
}

template<class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T>& B)
{
  if (this->l != B.l)
    throw;

  if (this->l == 1)
    return (*this) * B;

  T det = B[0][B.l - 1];
  for (int i = 1; i < B.l; i++)
    det = det * B[i][B.l - i - 1];

  if (det == 0)
    throw;

  TMatrix<T> A(B);
  TMatrix<T> _A(A.l);

  for (int i = 0; i < A.l; i++)
  {
    for (int j = 0; j < A.l - i;j++)
      A[i][j] = A[i][j] / A[i][A.l - i - 1];
    _A[i][A.l - i - 1] = (T)1 / A[i][A.l - i - 1];
  }

  for (int i = 0; i < A.l - 1; i++)
    for (int k = A.l - 2 - i; k >= 0; k--)
      for (int j = i; j >= 0; j--)
        _A[j][k] -= A[i][k] * _A[j][A.l - i - 1];

  return (*this) * _A ;
}
