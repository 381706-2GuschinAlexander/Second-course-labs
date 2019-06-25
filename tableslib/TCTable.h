#pragma once
#include "THElem.h"


template <class T>
class TSTable;

template <class T>
class TCTable
{
protected:
	int count;
	int size;
	static THElem<T> exemp;
	THElem<T>* pElem;
public:
	TCTable(const int _size = 10);
	TCTable(const TCTable<T>& table);
	~TCTable();
	void AddElem(THElem<T>& elem);
	void AddElem(const mString key, const T & value);
	T& Find(const mString& key);
	void DeleteElem(const mString& key);
	int GetCount();
	friend std::ostream& operator<<(std::ostream& out, const TCTable<T>& table)
	{
		for (int i = 0; i < table.count; i++)
				out << table.pElem[i] << std::endl;
		return out;
	}
	friend class TSTable<T>;
};

template<class T>
THElem<T> TCTable<T>::exemp;

template<class T>
TCTable<T>::TCTable(const int _size)
{
	if (_size < 1)
		throw(__NEG_SIZE);

	count = 0;
	size = _size;
	pElem = new THElem<T>[size];
}

template<class T>
TCTable<T>::TCTable(const TCTable<T>& table)
{
	count = table.count;
	size = table.size;
	pElem = new THElem<T>[size];

	for (int i = 0; i < count; i++)
		pElem[i] = table.pElem[i];
}

template<class T>
TCTable<T>::~TCTable()
{
	delete[] pElem;
}

template<class T>
void TCTable<T>::AddElem(THElem<T>& elem)
{
	if (count == size)
		throw(__SOD_IS_FULL);

	pElem[count++] = elem;
}

template<class T>
void TCTable<T>::AddElem(const mString key, const T & value)
{
	if (count == size)
		throw(__SOD_IS_FULL);

	(pElem[count]).SetKey(key);
	(pElem[count]).SetValue(value);
	count++;
}

template<class T>
T & TCTable<T>::Find(const mString & key)
{
	
	for (int i = 0; i < count; i++)
		if (pElem[i].GetKey() == key)
			return pElem[i].GetValue();

	throw(__MISSING_VALUE);
}

template<class T>
void TCTable<T>::DeleteElem(const mString & key)
{
	int i = 0;
	for (i; i < count; i++)
		if (pElem[i].GetKey() == key)
			break;

	if (i == count)
		throw(__MISSING_VALUE);

	for (int j = i; j < count - 1; j++)
		pElem[j] = pElem[j + 1];

	count--;

}

template<class T>
inline int TCTable<T>::GetCount()
{
	return count;
}
