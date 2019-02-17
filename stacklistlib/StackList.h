#pragma once
#include "exception.h"
#include "TLink.h"

template <class T>
class TStackList
{
protected:
  TLink<T>* currentElem;
  int len;
public:
  TStackList();
  ~TStackList();
  void Put(const T& A);
  T Get();
  bool IsEmpty();

};

template<class T>
TStackList<T>::TStackList()
{
  currentElem = NULL;
  len = 0;
}

template<class T>
TStackList<T>::~TStackList()
{
  if (currentElem != NULL) {
    TLink<T>* tmp = currentElem;
    for (int i = 0; i < len - 1; i++)
    {
      tmp = tmp->GetNextLink();
      delete currentElem;
      currentElem = tmp;
    }
    delete tmp;
  }
}

template<class T>
void TStackList<T>::Put(const T & A)
{
  if (IsEmpty() == 1)
  {
    currentElem = new TLink<T>(A, NULL);
  }
  else
  {
    currentElem = new TLink<T>(A, currentElem);
  }
  len++;
}

template<class T>
T TStackList<T>::Get()
{
  T tmp;

  if (IsEmpty() == 1)
    throw(1);
  else if (len == 1)
  {
    tmp = currentElem->GetValue();
    delete currentElem;
    currentElem = NULL;
  }
  else
  {
    tmp = currentElem->GetValue();
    TLink<T>* TMP = currentElem;
    currentElem = currentElem->GetNextLink();
    delete TMP;
  }
  len--;
  return tmp;
}

template<class T>
bool TStackList<T>::IsEmpty()
{
  return len == 0;
}
