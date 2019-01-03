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
  if (this->IsFull())
    throw(__STACK_IS_FULL);

  if (this->size > st + this->pos)
    this->p[st + this->pos] = s;
  else
    this->p[st + this->pos - this->size] = s;

  this->pos++;
}

template<class T>
T TQueue<T>::Get()
{
  if (this->IsEmpty())
    throw(__STACK_IS_EMPTY);

  T temp = this->p[st++];

  this->pos--;

  if (st == this->size)
    st = 0;

  
  return temp;
}