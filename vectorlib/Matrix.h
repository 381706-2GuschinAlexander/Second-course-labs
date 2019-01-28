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
	TMatrix operator*(const TMatrix<T>& A);
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
TMatrix<T> TMatrix<T>::operator * (const TMatrix<T>& A)
{
	if (this->l != A.l)
		throw(1);

	TMatrix<T> temp(this->l);
	for (int i = 0; i < this->l; i++)
		for (int j = 0; j < this->l - i; j++)
			for (int k = 0; k < this->l - (j + i); k++)
				temp[i][j] += this->p[i][k] * A.p[k][j];

	return temp;
}