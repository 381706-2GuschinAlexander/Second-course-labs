#pragma once
#include <iostream>
#include "exception.h"
template <class T>
class TVector
{
protected:
	int l; //lenght
	T* p; //pointer

public:
	TVector();
	TVector(int n);
	TVector(TVector<T>& A);
	~TVector();
	int GetSize(); //return lenght
	/*virtual*/ bool operator != (TVector<T>& A);
	/*virtual*/ bool operator == (TVector<T>& A);
	/*virtual*/ TVector<T>& operator = (TVector<T> &A);
	/*virtual*/ T& operator [](int i);
	/*virtual*/ TVector<T> operator + (TVector<T> &A);
	/*virtual*/ TVector<T> operator - (TVector<T>& A);
	/*virtual*/ TVector<T> operator * (TVector<T> &A);

	/*virtual*/ TVector<T> operator + (T& k);
	/*virtual*/ TVector<T> operator - (T& k);
	/*virtual*/ TVector<T> operator * (T& k);

	/*freind istream& operator >> (istream& in, TVector& A);*/
};

template <class T>
TVector<T>::TVector()
{
  l = 0;
  p = NULL;
}

template <class T>
TVector<T>::TVector(int n)
{
	if (n < 0)
		throw(1);
	else if (n == 0)
  {
    l = 0;
    p = NULL;
  } 
  else
	{
		l = n;
		p = new T[l];
    for (int i = 0; i < l; i++)
      p[i] = (T)0;
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

template <class T>
int TVector<T>::GetSize()
{
	return l;
}



template<class T>
TVector<T>& TVector<T>::operator=(TVector<T>& A)
{
	delete[] p;
	l = A.l;
	p = new T[l];
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];

	return *this;
}

template<class T>
bool TVector<T>::operator == (TVector<T>& A)
{
	if (l != A.l)
		return false;
	for (int i = 0; i < l; i++)
		if (p[i] != A.p[i])
			return false;
	return true;
}

template<class T>
bool TVector<T>::operator!=(TVector<T>& A)
{
	if (l != A.l)
		return true;
	for (int i = 0; i < l; i++)
		if (p[i] != A.p[i])
			return true;
	return false;
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
	if (l != A.l)
		throw (1);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] + A.p[i];
	return R;
}


template<class T>
TVector<T> TVector<T>::operator-(TVector<T>& A)
{
	if (l != A.l)
		throw (1);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] - A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(TVector<T>& A)
{
	if (l != A.l)
		throw (1);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] * A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator+(T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] + k;
	return R;
}

template<class T>
TVector<T> TVector<T>::operator-(T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] - k;
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] * k;
	return R;
}

/*template<class T>
istream& TVector<T>::operator >> (istream& in, TVector& A)
{
	for (int i = 0; i < A.l; i++)
		in >> A.p[i];
	return in;
}*/