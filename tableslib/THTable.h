#pragma once
#include "exception.h"
#include "THElem.h"

template <class T>
class THTable
{
protected:
	int count;
  int size;
	int m;
	THElem<T> exemp;
  THElem<T>* pElem;
public:
	void AddElem(THElem<T>& elem);
	T& Find(const mString& key);
  THTable(const int _size = 10);
  int GetHash(const mString& elem);

};

template<class T>
void THTable<T>::AddElem(THElem<T>& elem)
{
	if (count == size)
		throw(1);

	int i = GetHash(elem.GetKey()) % size;
	while (pElem[i] != exemp)
	{
		i = (i + m) % size;
	}

	pElem[i] = elem;
	count++;
}

template<class T>
T & THTable<T>::Find(const mString & key)
{
	int i = GetHash(key) / size;
	int howLong = 0;
	while (pElem[i].GetKey() != key && howLong < count)
	{
		count++;
		i = (i + m) % size;
	}

	if (howLong >= count)
		throw (1);
	
	return pElem[i];
}

template<class T>
THTable<T>::THTable(const int _size)
{
  if (_size < 2)
    throw(1);

  size = _size;
	count = 0;
  pElem = NULL;
  if (_size != 0)
    pElem = new THElem<T>[_size];

	m = 2;
	while (size % m == 0)
		m++;
}

template<class T>
int THTable<T>::GetHash(const mString& elem)
{
	int count = elem.GetCount();
	int sum = 0;
	for(int i = 0; i < count; i++)
	{
		sum /= 2;
		sum += (elem.GetCStr()[i] - 'a' + 1);
	}

	return sum;
}
