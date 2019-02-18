#pragma once
#include "exception.h"


template <class T>
class ArrList
{
protected:
  T* p;
  int* ind;
  int size;
  int count;
  int freeInd;
  int firstInd;
public:
  ArrList(const int _size = 0);
  ArrList(const ArrList& A);
  ~ArrList();
  bool IsFull();
  bool IsEmpty();
  void InsFirst(const T& a);
  void InsLast(const T& a);
  T GetFirst();
  T GetLast();
};

template<class T>
ArrList<T>::ArrList(const int _size)
{
  if (_size < 0)
    throw(1);
  else if (_size == 0)
  {
    p = NULL;
    ind = NULL;
    size = 0;
  }
  else
  {
    size = _size;
    p = new T[size];
    ind = new int[size];
    for (int i = 0; i < size; i++)
      ind[i] = -2;
  }
  firstInd = -1;
  count = 0;
  freeInd = 0;
}

template<class T>
ArrList<T>::ArrList(const ArrList & A)
{
  if (A.size != 0) {
    p = new T[A.size];
    ind = new int[A.size];
  }

  size = A.size;
  firstInd = A.firstInd;
  count = A.count;
  freeInd = A.freeInd;

  for (int i = 0; i < size; i++)
  {
    p[i] = A.p[i];
    ind[i] = A.ind[i];
  }
}

template<class T>
inline ArrList<T>::~ArrList()
{
}

template<class T>
bool ArrList<T>::IsFull()
{
  return count == size;
}

template<class T>
bool ArrList<T>::IsEmpty()
{
  return count == 0;
}

template<class T>
void ArrList<T>::InsFirst(const T & a)
{
  if (IsFull() == 1)
    throw(1);

  p[freeInd] = a;
  ind[freeInd] = firstInd;
  firstInd = freeInd;

  for(int i = 0; i < size;i++)
    if (ind[i] == -2)
    {
      freeInd = i;
      break;
    }

  count++;
}

template<class T>
inline void ArrList<T>::InsLast(const T & a)
{
}

template<class T>
inline T ArrList<T>::GetFirst()
{
  if (IsEmpty() == 1)
    throw(1);

  int tmp = firstInd;
  firstInd = ind[firstInd];
  ind[firstInd] = -2;

  count--;

  return p[tmp];
}

template<class T>
inline T ArrList<T>::GetLast()
{
  return (T)0;
}
