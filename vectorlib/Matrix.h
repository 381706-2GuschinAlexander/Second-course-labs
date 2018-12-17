#pragma once
#include "TVector.h"

template <class T>
class Matrix : public TVector<TVector<T> >
{
public:
	Matrix(int n);
	Matrix(Matrix<T>& A);
	Matrix(TVector<TVector<T>>& A);
	bool operator==(Matrix<T>& A);
	Matrix& operator=(Matrix<T>& A);
	Matrix operator+(Matrix<T>& A);
	Matrix operator-(Matrix<T>& A);
	Matrix operator*(Matrix<T>& A);
};

template <class T>
Matrix<T>::Matrix(int n):TVector<TVector<T> >(n)
{
	for(int i = 0; i < n; i++)
		p[i] = TVector<T>(n - i);
}


template <class T>
Matrix<T>::Matrix(Matrix<T>& A):TVector<TVector<T> >(A.GetSize())
{
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];
}


template <class T>
Matrix<T>::Matrix(TVector<TVector<T>>& A) :TVector<TVector<T> >(A.GetSize())
{
	for (int i = 0; i < A.GetSize(); i++)
		if (A[i].GetSize() != l - i)
			throw (1);
	for (int i = 0; i < l; i++)
		p[i] = A[i];
}



template <class T>
bool  Matrix<T>::operator == (Matrix<T>& A)
{
	if (l != A.l)
		return false;

	for (int i = 0; i < l; i++)
		if (p[i] != A.p[i])
			return false;

	return true;
}

template <class T>
Matrix<T>&  Matrix<T>::operator = (Matrix& A)
{
	if (l != A.l)
	{
		
		delete[] p;
		l = A.l;
		p = new TVector<T>[l];
	}
		
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];

	return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator + (Matrix<T>& A)
{
	if (l != A.l)
		throw(1);

	TVector<TVector<T>> temp(l);
	for (int i = 0; i < l; i++)
		temp[i] = p[i] + A.p[i];

	return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator - (Matrix<T>& A)
{
	if (l != A.l)
		throw(1);

	Matrix<T> temp(l);
	for (int i = 0; i < l; i++)
		temp[i] = p[i] - A.p[i];

	return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator * (Matrix<T>& A)
{
	if (l != A.l)
		throw(1);

	Matrix<T> temp(l);
	for (int i = 0; i < l; i++)
		for (int j = 0; j < l - i; j++)
			for (int k = 0; k < l - (j + i); k++)
				temp[i][j] += p[i][k] * A.p[k][j];

	return temp;
}