#pragma once
#include <iostream>
#include <mString.h>

template <class T>
class THElem
{
protected:
  mString key;
  T value;
public:
  THElem(const mString& _key, const T& _value);
  THElem();
  ~THElem();
  T GetValue();
  mString GetKey();
	THElem<T>& operator=(const THElem& elem);
	bool operator==(const THElem& elem);
	bool operator!=(const THElem& elem);
  void SetKey(const mString& _key);
  void SetValue(const T& _value);
};

template<class T>
THElem<T>::THElem(const mString& _key, const T& _value)
{
  key = _key;
  value = _value;
}

template<class T>
THElem<T>::THElem()
{
  key = "";
  value = 0;
}

template<class T>
THElem<T>::~THElem()
{

}

template<class T>
T THElem<T>::GetValue()
{
  return value;
}

template<class T>
mString THElem<T>::GetKey()
{
  return key;
}

template<class T>
THElem<T> & THElem<T>::operator=(const THElem & elem)
{
	key = elem.key;
	value = elem.value;
	return *this;
}

template<class T>
bool THElem<T>::operator==(const THElem & elem)
{
	if (key != elem.key)
		return false;
	if (value != elem.value)
		return false;

	return true;
}

template<class T>
bool THElem<T>::operator!=(const THElem & elem)
{
	if (key == elem.key)
		return false;
	if (value == elem.value)
		return false;

	return true;
}

template<class T>
void THElem<T>::SetKey(const mString& _key)
{
  key = _key;
}

template<class T>
void THElem<T>::SetValue(const T & _value)
{
  value = _value;
}
