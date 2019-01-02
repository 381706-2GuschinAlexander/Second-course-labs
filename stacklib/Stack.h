#pragma once
#include "exception.h"
template <class T>
class TStack
{
protected:
  T * p;//pointer
  int top;
  int memSize;
public:
  TStack(int ms);
  ~TStack();
  bool IsEmpty();
  bool IsFull();
  int GetSize();
  int GetCount();
  void Put(const T s);
  T Get();
};

template <class T>
TStack<T>::TStack(int ms)
{
  if (ms < 0)
    throw __NEG_SIZE;
  else if (ms > 0)
    p = new T[ms];
  else
    p = NULL;

  top = -1;
  memSize = ms;
}

template <class T>
TStack<T>::~TStack()
{
  delete[] p;
}

template <class T>
bool TStack<T>::IsEmpty()
{
  return top == -1;
}

template <class T>
bool TStack<T>::IsFull()
{
  return top == (memSize - 1);
}

template <class T>
int TStack<T>::GetSize()
{
  return memSize;
}

template <class T>
int TStack<T>::GetCount()
{
  return top + 1;
}

template <class T>
void TStack<T>::Put(const T s)
{
  if (IsFull())
    throw(__STACK_IS_FULL);
  top++;
  p[top] = s;
}

template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
    throw(__STACK_IS_EMPTY);
  top--;
  return p[top + 1];
}
