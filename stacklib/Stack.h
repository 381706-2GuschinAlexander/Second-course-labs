#pragma once
#include "exception.h"
template <class T>
class Stack
{
protected:
  T * p;//pointer
  int top;
  int memSize;
public:
  Stack(int ms);
  ~Stack();
  bool IsEmpty();
  bool IsFull();
  int GetSize();
  int GetCount();
  void Put(const T s);
  T Get();
};

template <class T>
Stack<T>::Stack(int ms)
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
Stack<T>::~Stack()
{
  delete[] p;
}

template <class T>
bool Stack<T>::IsEmpty()
{
  return top == -1;
}

template <class T>
bool Stack<T>::IsFull()
{
  return top == (memSize - 1);
}

template <class T>
int Stack<T>::GetSize()
{
  return memSize;
}

template <class T>
int Stack<T>::GetCount()
{
  return t + 1;
}

template <class T>
void Stack<T>::Put(const T s)
{
  if (IsFull())
    throw(__STACK_IS_FULL);
  top++;
  p[top] = s;
}

template <class T>
T Stack<T>::Get()
{
  if (IsEmpty())
    throw(__STACK_IS_EMPTY);
  top--;
  return p[top + 1];
}