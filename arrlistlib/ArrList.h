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
    throw(__NEG_SIZE);
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
  delete[] p;
  delete[] ind;
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
    throw(__STACK_IS_FULL);

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
  if (IsFull() == 1)
    throw(__STACK_IS_FULL);

  if (count == 0)
    InsFirst(a);
  else
  {
    for (int i = 0; i < size; i++)
      if (ind[i] == -1)
        ind[i] = freeInd;
      
    ind[freeInd] = -1;
    p[freeInd] = a;

    for (int i = 0; i < size; i++)
      if (ind[i] == -2)
      {
        freeInd = i;
        break;
      }

    count++;
  }
}

template<class T>
inline T ArrList<T>::GetFirst()
{
  if (IsEmpty() == 1)
    throw(__STACK_IS_EMPTY);

  int tmp = firstInd;
  firstInd = ind[firstInd];
  if (firstInd == -2)
    firstInd = 0;
  ind[tmp] = -2;
  count--;
  return p[tmp];
}

template<class T>
inline T ArrList<T>::GetLast()
{
  if (IsEmpty() == 1)
    throw(__STACK_IS_EMPTY);

  if (count == 1)
    return GetFirst();
  else 
  {
    int prInd = firstInd;
    int resInd = ind[firstInd];
    while (ind[resInd] != -1)
    {
      prInd = ind[prInd];
      resInd = ind[resInd];
    }

    ind[prInd] = -1;
    ind[resInd] = -2;
    count--;
    return p[resInd];
  }
}
