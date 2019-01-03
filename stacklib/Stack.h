#pragma once
#include "exception.h"
template <class T>
class TStack
{
protected:
  T * p;//pointer
  int pos;
  int size;
public:
  TStack(int n);
  ~TStack();
  bool IsEmpty();
  bool IsFull();
  int GetSize();
  int GetCount();
  void Put(const T s);
  T Get();
};

template <class T>
TStack<T>::TStack(int n)
{
  if (n < 0)
    throw __NEG_SIZE;
  else if (n > 0)
    p = new T[n];
  else
    p = NULL;

  pos = 0;
  size = n;
}

template <class T>
TStack<T>::~TStack()
{
  if(p != NULL)
    delete[] p;
}

template <class T>
bool TStack<T>::IsEmpty()
{
  return pos == 0;
}

template <class T>
bool TStack<T>::IsFull()
{
  return pos == size;
}

template <class T>
int TStack<T>::GetSize()
{
  return size;
}

template <class T>
int TStack<T>::GetCount()
{
  return pos;
}

template <class T>
void TStack<T>::Put(const T s)
{
  if (IsFull())
    throw(__STACK_IS_FULL);
  p[pos++] = s;
}

template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw(__STACK_IS_EMPTY);
  return p[--pos];
}
