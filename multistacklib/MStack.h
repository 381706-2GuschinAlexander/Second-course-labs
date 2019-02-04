#pragma once
#include "Stack.h"
template <class T>
class MStack : public TStack<T>
{
public:
  void SetMem(T* _p, int _size)
  {
    this->p = _p;
    this->size = _size;
  }
  MStack(int _size) :TStack<T>(_size)
  {

  }
  MStack():TStack<T>()
  {

  }
};