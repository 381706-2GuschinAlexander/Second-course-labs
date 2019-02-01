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
	TVector(const TVector<T>& A);
	~TVector();
	int GetSize() const; //return lenght
	bool operator != (const TVector<T>& A);
  bool operator == (const TVector<T>& A);
  TVector<T>& operator = (const TVector<T> &A);
	T& operator [](int i) const;
	TVector<T> operator + (const TVector<T> &A);
	TVector<T> operator - (const TVector<T>& A);
	TVector<T> operator * (const TVector<T> &A);
	TVector<T> operator + (const T& k);
	TVector<T> operator - (const T& k);
	TVector<T> operator * (const T& k);

  friend std::istream &operator>>(std::istream &in, TVector<T> &A)
  {
    for (int i = A.l - 1; i >= 0; i--)
      in >> A[i];
    return in;
  }

  friend std::ostream &operator<<(std::ostream &out,const TVector<T> &A)
  {
    for (int i = A.l - 1; i >= 0; i--)
      out << A[i] << ' ';
    return out;
  }
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
		throw(__NEG_SIZE);
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
TVector<T>::TVector(const TVector<T>& A)
{
	l = A.l;
	p = new T[l];
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];
}

template <class T>
TVector<T>::~TVector()
{ 
  if(p != NULL)
	  delete[] p;
}

template <class T>
int TVector<T>::GetSize() const
{
	return l;
}



template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& A)
{
  if(p != NULL)
    delete[] p;
  l = A.l;
  p = new T[l];
	for (int i = 0; i < l; i++)
		p[i] = A.p[i];

	return *this;
}

template<class T>
bool TVector<T>::operator == (const TVector<T>& A)
{
	if (l != A.l)
		return false;
	for (int i = 0; i < l; i++)
		if (p[i] != A.p[i])
			return false;
	return true;
}

template<class T>
bool TVector<T>::operator!=(const TVector<T>& A)
{
	if (l != A.l)
		return true;
	for (int i = 0; i < l; i++)
		if (p[i] != A.p[i])
			return true;
	return false;
}

template<class T>
T& TVector<T>::operator[](int i) const
{
	if (i >= l || i < 0)
		throw(__IND_IS_OUT_OF_RANGE);
	else
		return p[i];
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector<T>& A)
{
	if (l != A.l)
		throw (__DIFF_SIZE);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] + A.p[i];
	return R;
}


template<class T>
TVector<T> TVector<T>::operator-(const TVector<T>& A)
{
	if (l != A.l)
		throw (__DIFF_SIZE);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] - A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(const TVector<T>& A)
{
	if (l != A.l)
		throw (__DIFF_SIZE);
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] * A.p[i];
	return R;
}

template<class T>
TVector<T> TVector<T>::operator+(const T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] + k;
	return R;
}

template<class T>
TVector<T> TVector<T>::operator-(const T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] - k;
	return R;
}

template<class T>
TVector<T> TVector<T>::operator*(const T& k)
{
	TVector R(l);
	for (int i = 0; i < l; i++)
		R[i] = p[i] * k;
	return R;
}

