#pragma once
#include "THElem.h"
#include "List.h"

template <class T>
class THTableList
{
protected:
	int count;
	int size;
	static THElem<T> exemp;
	List<THElem<T> >* pElem;
	int GetHash(const mString& elem);
public:
	THTableList(const int _size = 10);
	THTableList(const THTableList<T>& table);
	~THTableList();
	void AddElem(THElem<T>& elem);
	void AddElem(const mString key, const T & value);
	T& Find(const mString& key);
	void DeleteElem(const mString& key);
	int GetCount();
	friend std::ostream& operator<<(std::ostream& out, const THTableList<T>& table)
	{
		for (int i = 0; i < table.size; i++)
			if (table.pElem[i] != exemp)
				out << table.pElem[i] << std::endl;
		return out;
	}
};

template<class T>
THElem<T> THTableList<T>::exemp;

template<class T>
int THTableList<T>::GetHash(const mString& elem)
{
	int count = elem.GetCount();
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum /= 2;
		sum += (elem.GetCStr()[i] - 'a' + 1);
	}
	return sum;
}

template<class T>
THTableList<T>::THTableList(const int _size)
{
	if (_size < 1)
		throw(1);

	size = _size;
	count = 0;
	pElem = new List<THElem<T> >[size];
}

template<class T>
THTableList<T>::THTableList(const THTableList<T>& table)
{
	count = table.count;
	size = table.size;
	pElem = new List<THElem<T> >[size];
	for (int i = 0; i < size; i++)
	{
		TLink<THElem<T> >* tmp = table.pElem[i].GetFirstLink();
		while (tmp != NULL)
		{
			pElem[i].InsLast(tmp->GetValue());
			tmp = tmp->GetNextLink();
		}
	}
}

template<class T>
THTableList<T>::~THTableList()
{
	delete[] pElem;
}

template<class T>
void THTableList<T>::AddElem(THElem<T>& elem)
{
	int i = GetHash(elem.GetKey()) % size;
	count++;
	pElem[i].InsLast(elem);
}

template<class T>
void THTableList<T>::AddElem(const mString key, const T & value)
{
	int i = GetHash(key) % size;

	THElem<T> tmp;
	tmp.SetKey(key);
	tmp.SetValue(value);

	pElem[i].InsLast(tmp);
	count++;
}

template<class T>
T & THTableList<T>::Find(const mString & key)
{
	int i = GetHash(key) % size;
	if (pElem[i].GetLen() == 0)
		throw(1);

	TLink<THElem<T> >* tmp = pElem[i].GetFirstLink();
	while (tmp != NULL)
	{
		if (tmp->GetValue().GetKey() == key)
			return (*tmp).GetValue().GetValue();
		tmp = tmp->GetNextLink();
	}

	throw(1);
}

template<class T>
void THTableList<T>::DeleteElem(const mString & key)
{
	int i = GetHash(key) % size;
	if (pElem[i].GetLen() == 0)
		throw(1);

	TLink<THElem<T> >* tmp = pElem[i].GetFirstLink();
	int pos = 0;
	while (tmp != NULL)
	{
		if (tmp->GetValue().GetKey() == key)
			break;
		tmp = tmp->GetNextLink();
		pos++;
	}

	if (tmp != NULL)
	{
		count--;
		pElem[i].DelCustom(pos);
	}
	else
		throw(1);
}

template<class T>
inline int THTableList<T>::GetCount()
{
	return count;
}
