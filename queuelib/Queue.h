#pragma once
#include "Stack.h"

template <class T>
class TQueue : public TStack<T>
{
private:
  int st;
public:
  TQueue(int n);
  void Put(const T s);
  T Get();
};

template<class T>
TQueue<T>::TQueue(int n):TStack<T>(n)
{
  st = 0;
}

template<class T>
void TQueue<T>::Put(const T s)
{
  if (IsFull())
    throw(__STACK_IS_FULL);

  if (size > st + pos)
    this->p[st + pos] = s;
  else
    this->p[st + pos - size] = s;

  pos++;
}

template<class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
    throw(__STACK_IS_EMPTY);

  T temp = this->p[st++];

  pos--;

  if (st == size)
    st = 0;
}