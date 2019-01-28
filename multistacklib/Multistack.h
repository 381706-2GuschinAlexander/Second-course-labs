#pragma once
#include "Stack.h"

template <class T>
class TMulStack : public TStack<T>
{
protected:
  int count;
  int l;
  TStack<T>** Stacks;
  T* mas;
  T** ind;
  int* lenM;
  int CalcFree();
  void Resize();
public:
  TMulStack(int _count, int _l);
  TMulStack(TMulStack& A);
  ~TMulStack();
  void Put(T &a, int i);
  T Get(int i);
  bool IsEmpty(int i);
  bool IsFull(int i);
};

template<class T>
inline int TMulStack<T>::CalcFree()
{
  return 0;
}

template<class T>
inline void TMulStack<T>::Resize()
{
}

template<class T>
inline TMulStack<T>::TMulStack(int _count, int _l)
{
}

template<class T>
inline TMulStack<T>::TMulStack(TMulStack & A)
{
}

template<class T>
inline TMulStack<T>::~TMulStack()
{
}

template<class T>
inline void TMulStack<T>::Put(T & a, int i)
{
}

template<class T>
inline T TMulStack<T>::Get(int i)
{
  return T();
}

template<class T>
inline bool TMulStack<T>::IsEmpty(int i)
{
  return false;
}

template<class T>
inline bool TMulStack<T>::IsFull(int i)
{
  return false;
}
