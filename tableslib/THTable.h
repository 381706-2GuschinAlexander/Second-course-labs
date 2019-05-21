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
	static THElem<T> exemp;
  THElem<T>* pElem;
	int GetHash(const mString& elem);
public:
	THTable(const int _size = 10);
	THTable(const THTable<T>& table);
	void AddElem(THElem<T>& elem);
	void AddElem(const mString key ,const T & value);
	T& Find(const mString& key);
	void DeleteElem(const mString& key); 
	int GetCount();
	friend std::ostream& operator<<(std::ostream& out, const THTable<T>& table)
	{
		for (int i = 0; i < table.size; i++)
			if (table.pElem[i] != exemp)
				out << table.pElem[i] << std::endl;
		return out;
	}
};

template<class T>
THElem<T> THTable<T>::exemp;

template<class T>
void THTable<T>::AddElem(THElem<T>& elem)
{
	if (count == size)
		throw(__SOD_IS_FULL);

	int i = GetHash(elem.GetKey()) % size;
	while (pElem[i] != exemp)
	{
		i = (i + m) % size;
	}

	pElem[i] = elem;
	count++;
}

template<class T>
void THTable<T>::AddElem(const mString key,const T & value)
{
	if (count == size)
		throw(__SOD_IS_FULL);

	int i = GetHash(key) % size;
	while (pElem[i] != exemp)
	{
		i = (i + m) % size;
	}

	pElem[i].SetValue(value);
	pElem[i].SetKey(key);
	count++;
}

template<class T>
T & THTable<T>::Find(const mString & key)
{
	int i = GetHash(key) % size;
	int howLong = 0;
	while ((pElem[i]).GetKey() != key && howLong < count)
	{
		if (pElem[i] == exemp)
			break;
		i = (i + m) % size;
		howLong++;
	}

	if (pElem[i] == exemp || howLong >= count)
		throw(__MISSING_VALUE);
	
	return pElem[i].GetValue();
}

template<class T>
void THTable<T>::DeleteElem(const mString& key)
{
	int i = GetHash(key) % size;
	int howLong = 0;
	while ((pElem[i]).GetKey() != key && howLong < count)
	{
		if (pElem[i] == exemp)
			break;
		i = (i + m) % size;
		howLong++;
	}

	if (pElem[i] == exemp || howLong >= count)
		throw(__MISSING_VALUE);

	pElem[i] = exemp;
	count--;
}

template<class T>
THTable<T>::THTable(const int _size)
{
  if (_size < 1)
    throw(__NEG_SIZE);

  size = _size;
	count = 0;
  pElem = NULL;
  if (_size != 0)
    pElem = new THElem<T>[_size];

	if (size == 1)
		m = 1;
	else
		m = 2;
	while (size % m == 0)
		m++;
}

template<class T>
THTable<T>::THTable(const THTable<T>& table)
{
	size = table.size;
	count = table.count;
	m = table.m;
	pElem = new THElem<T>[size];

	for (int i = 0; i < size; i++)
		pElem[i] = table.pElem[i];
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

template<class T>
inline int THTable<T>::GetCount()
{
	return count;
}
