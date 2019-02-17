#pragma once
template <class T>
class TLink 
{
protected:
  T value;
  TLink<T>* p;
public:
  TLink();
  TLink(const T& a, TLink<T>* _p);
  TLink(const TLink<T>& A);
  void SetValue(const T& a);
  T GetValue();
  TLink<T>* GetNextLink();
  void setP(TLink<T>* _p);
};

template<class T>
void TLink<T>::setP(TLink<T>* _p)
{
  p = _p;
}

template<class T>
TLink<T>::TLink()
{
  value = (T)0;
}

template<class T>
TLink<T>::TLink(const T & a, TLink<T>* _p)
{
  value = a;
  p = _p;
}

template<class T>
TLink<T>::TLink(const TLink<T>& A)
{
  value = A.value;
  p = A.p;
}

template<class T>
void TLink<T>::SetValue(const T & a)
{
  value = a;
}

template<class T>
T TLink<T>::GetValue()
{
  return value;
}

template<class T>
TLink<T>* TLink<T>::GetNextLink()
{
  return p;
}
