#pragma once
#include "exception.h"
#include "THElem.h"

template <class T>
class THTable
{
protected:
  int size;
  THElem<T>* pElem;
public:
  THTable(const int _size = 0);
  int GetHash(const THElem<T>& elem);

};

template<class T>
THTable<T>::THTable(const int _size)
{
  if (_size < 0)
    throw(1);

  size = _size;
  pElem = NULL;
  if (_size != 0)
    pElem = new THElem<T>[_size];
}

template<class T>
int THTable<T>::GetHash(const THElem<T>& elem)
{
  return 0;
}
