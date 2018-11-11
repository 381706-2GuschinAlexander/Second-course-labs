#include "TVector.h"

template <class T>
TVector<T>::TVector(int n)
{
	if (n <= 0)
		throw(1);
	else 
	{
		l = n;
		p = new T[l];
	}
}

template <class T>
TVector<T>::TVector(TVector<T>& A)
{
	l = A.l;
	p = new T[l];
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];
}

template <class T>
TVector<T>::~TVector()
{
	delete[] p;
}

template<class T>
TVector<T>& TVector<T>::operator=(TVector<T>& A)
{
	delete[] p;
	l = A.l;
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];

	return *this;
}

template<class T>
T& TVector<T>::operator[](int i)
{
	if (i >= l || i < 0)
		throw(1);
	else
		return p[i];
}

template<class T>
TVector<T> TVector<T>::operator+(TVector<T>& A)
{
	int max = l > A.l ? l : A.l;
	int min = l < A.l ? l : A.l;
	TVector R(max);

	for (int i = 0; i < min; i++)
		R[i] = p[i] + A.p[i];

	if (l > A.l)
		for (int i = min; i < max; i++)
			R[i] = p[i];
	else
		for (int i = min; i < max; i++)
			R[i] = A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(TVector<T>& A)
{
	int max = l > A.l ? l : A.l;
	int min = l < A.l ? l : A.l;
	TVector R(max);

	for (int i = 0; i < min; i++)
		R[i] = p[i] * A.p[i];

	if (l > A.l)
		for (int i = min; i < max; i++)
			R[i] = p[i];
	else
		for (int i = min; i < max; i++)
			R[i] = A.p[i];
	return R;
}
