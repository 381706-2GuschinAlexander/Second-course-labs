#pragma once
#include "exception.h"
#include "TLink.h"

template <class T>
class List
{
protected:
  TLink<T>* firstLink;
  TLink<T>* lastLink;
  int len;
public:
  List();
  ~List();
  T GetValue(int pos) const;
  bool IsEmpty() const;
  int GetLen() const;
  void InsFirst(const T& a);
  void InsCustom(const T& a, int pos);
  void InsLast(const T& a);
  void DelFirst();
  void DelCustom(int pos);
};

template<class T>
inline List<T>::List()
{
  len = 0;
  firstLink = NULL;
  lastLink = NULL;
}

template<class T>
inline List<T>::~List()
{
  if (firstLink != NULL) {
    TLink<T>* tmpFirst = firstLink;
    TLink<T>* tmpSecond;

    if (len > 1)
      tmpSecond = tmpFirst->GetNextLink();

    for (int i = 0; i < len - 1; i++)
    {
      delete tmpFirst;
      tmpFirst = tmpSecond;
      tmpSecond = tmpFirst->GetNextLink();
    }

    if (len > 1)
      delete tmpSecond;
  }
}

template<class T>
T List<T>::GetValue(int pos) const
{
  if (pos < 0 || pos >= len)
    throw(__IND_IS_OUT_OF_RANGE);

  TLink<T>* res = firstLink;
  for (int i = 0; i < pos; i++)
    res = res->GetNextLink();
  
  return res->GetValue();
}

template<class T>
inline bool List<T>::IsEmpty() const
{
  return len == 0;
}

template<class T>
int List<T>::GetLen() const
{
  return len;
}

template<class T>
void List<T>::InsFirst(const T & a)
{
  firstLink = new TLink<T>(a, firstLink);
  len++;
  if (len == 1)
    lastLink = firstLink;
}

template<class T>
void List<T>::InsCustom(const T & a, int pos)
{
  if (pos < 0 || pos > len)
    throw(__IND_IS_OUT_OF_RANGE);

  if (pos == 0)
    InsFirst(a);
  else if (pos == len)
    InsLast(a);
  else
  {
    TLink<T>* tmp = firstLink;
    for (int i = 0; i < pos - 1; i++)
      tmp = tmp->GetNextLink();
    TLink<T>* res = new TLink<T>(a, tmp->GetNextLink());
    tmp->setP(res);
    len++;
  }
}

template<class T>
void List<T>::InsLast(const T & a)
{ 
  TLink<T>* tmp = new TLink<T>(a, NULL);

  if (len > 0)
    lastLink->setP(tmp);
  else
    firstLink = tmp;

  lastLink = tmp;
  len++;
}

template<class T>
inline void List<T>::DelFirst()
{
  if (IsEmpty() == 1)
    throw(__STACK_IS_EMPTY);

  TLink<T>* tmp = firstLink;
  firstLink = firstLink->GetNextLink();
  delete tmp;
  len--;
}

template<class T>
inline void List<T>::DelCustom(int pos)
{
  if (pos < 0 || pos >= len)
    throw(__IND_IS_OUT_OF_RANGE);

  if (pos == 0)
    DelFirst();
  else if(pos != len - 1)
  {
    TLink<T>* tmp = firstLink;
    for (int i = 0; i < pos - 1; i++)
      tmp->GetNextLink();

    TLink<T>* tmpD = tmp->GetNextLink();
    tmp->setP((tmp->GetNextLink())->GetNextLink());
    delete tmpD;
    len--;
  }
  else
  {
    TLink<T>* tmp = firstLink;
    for (int i = 0; i < pos - 1; i++)
      tmp = tmp->GetNextLink();

    tmp->setP(NULL);
    delete (tmp->GetNextLink());
    len--;
  }
}
