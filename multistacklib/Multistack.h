#pragma once
#include "MStack.h"

template <class T>
class TMulStack : public MStack<T>
{
protected:
  int count;
  int l;
  MStack<T>** stacks;
  T* gstack;
  T** ind;
  int* lenS;
  bool Resize();
  int resizeCount;
public:
  TMulStack(int _count, int _l);
  TMulStack(TMulStack& A);
  ~TMulStack();
  void Put(T a, int i);
  T Get(int i);
  bool IsEmpty(int i);
  bool IsFull(int i);
  int CalcFree(int i);
};

template<class T>
int TMulStack<T>::CalcFree(int i)
{
  return (stacks[i]->GetSize() - stacks[i]->GetCount());
}

template<class T>
bool TMulStack<T>::Resize()
{
  /*   OwO What this?  */
  return false;
}

template<class T>
TMulStack<T>::TMulStack(int _count, int _l)
{
  if (_count < 0 || _l < 0)
    throw(1);

  if(_count > _l)
    throw(1);

  int resizeCount = 0;  
  count = _count;
  l = _l;
  gstack = new T[l];

  //length of all stacks
  lenS = new int[count]; 
  for (int i = 0; i < count; i++)
    lenS[i] = l / count;
  lenS[0] += l % count;

  //index for all stacks
  ind = new T*[count];
  ind[0] = gstack;
  int t = 0;
  for (int i = 1; i < count; i++)
  {
    ind[i] = &gstack[lenS[i - 1] + t];
    t += lenS[i - 1];
  }

  //set index and length for all stacks
  stacks = new MStack<T>*[count];
  for (int i = 0; i < count; i++)
  {
    stacks[i] = new MStack<T>();
    stacks[i]->SetMem(ind[i], lenS[i]);
  }
}

template<class T>
TMulStack<T>::TMulStack(TMulStack & A)
{
  int resizeCount = 0;
  count = A.count;
  l = A.l;
  gstack = new T[l];

  lenS = new int[count];
  for (int i = 0; i < count; i++)
    lenS[i] = A.lenS[i];

  ind = new T*[count];
  ind[0] = gstack;
  int t = 0;
  for (int i = 1; i < count; i++)
  {
    ind[i] = &gstack[lenS[i - 1] + t];
    t += lenS[i - 1];
  }

  for (int i = 0; i < l; i++)
    gstack[i] = A.gstack[i];
}

template<class T>
TMulStack<T>::~TMulStack()
{
  delete[] gstack;
  delete[] ind;
  delete[] lenS;
}

template<class T>
void TMulStack<T>::Put(T a, int i)
{
  if (IsFull(i) == true)
    if (Resize() == false)
      throw(1);

  stacks[i]->Put(a);
}

template<class T>
T TMulStack<T>::Get(int i)
{
  if (IsEmpty(i) == true)
    throw(1);
 
  return stacks[i]->Get();
}

template<class T>
bool TMulStack<T>::IsEmpty(int i)
{
  return stacks[i]->IsEmpty();
}

template<class T>
bool TMulStack<T>::IsFull(int i)
{
  return stacks[i]->IsFull();
}
