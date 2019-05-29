#pragma once
#include "THElem.h"
#include "TCTable.h"

template <class T>
class TSTable
{
protected:
	int count;
	int size;
	static THElem<T> exemp;
	THElem<T>* pElem;
public:
	TSTable(const int _size = 10);
	TSTable(const TSTable<T>& table);
	TSTable(const TCTable<T>& table);
	~TSTable();
	static void QuickSort(TCTable<T>& table, int first, int second);
	void AddElem(THElem<T>& elem);
	void AddElem(const mString key, const T & value);
	T& Find(const mString& key);
	void DeleteElem(const mString& key);
	int GetCount();
	friend std::ostream& operator<<(std::ostream& out, const TSTable<T>& table)
	{
		for (int i = 0; i < table.size; i++)
			if (table.pElem[i] != exemp)
				out << table.pElem[i] << std::endl;
		return out;
	}
};

template<class T>
TSTable<T>::TSTable(const int _size)
{
	if (_size < 1)
		throw(__NEG_SIZE);

	count = 0;
	size = _size;
	pElem = new THElem<T>[size];
}

template<class T>
TSTable<T>::TSTable(const TSTable<T>& table)
{
	count = table.count;
	size = table.size;
	pElem = new THElem<T>[size];

	for (int i = 0; i < count; i++)
		pElem[i] = table.pElem[i];
}

template<class T>
TSTable<T>::TSTable(const TCTable<T>& table)
{
	TCTable<T> copy(table);
	count = table.count;
	size = table.size;
	pElem = new THElem<T>[size];

	TCTable<T> sortT(table);
	QuickSort(sortT, 0, count);
	for (int i = 0; i < count; i++)
		pElem[i] = sortT.pElem[i];
}

template<class T>
TSTable<T>::~TSTable()
{
	delete[] pElem;
}

template<class T>
void TSTable<T>::QuickSort(TCTable<T>& table, int first, int second)
{
	int c = (first + second) / 2;
	THElem<T> center = table.pElem[c];
	int i = first, j = second;
	THElem<T> tmp;
	while (i <= j)
	{
		for (i; table.pElem[i++].GetKey() < center.GetKey() && i < table.count;i++);
		for (j; table.pElem[j--].GetKey() < center.GetKey() && j > 0 ;j--);
		if (i <= j)
		{
			tmp = table.pElem[i];
			table.pElem[i] = table.pElem[j];
			table.pElem[j] = tmp;
		}
	}

	if (first < j)
		QuickSort(table, first, j);
	if (second > i)
		QuickSort(table, i, second);
}

template<class T>
void TSTable<T>::AddElem(THElem<T>& elem)
{
	if (count == size)
		throw(1);

	int prevL = 0, prevR = count;
	int rigth = count;
	int left = 0;
	int center = (rigth - left) / 2;

	while (rigth - left >= 1)
	{
		if (elem.GetKey() < pElem[center].GetKey())
		{
			rigth = center;
			center = (rigth - left) / 2;
			if (prevL == left && prevR == rigth)
				rigth = center - 1;
			prevL = left;
			prevR = rigth;
		}
		else if (elem.GetKey() > pElem[center].GetKey())
		{
			left = center;
			center = (rigth - left) / 2;
			if (prevL == left && prevR == rigth)
				left = center + 1;
			prevL = left;
			prevR = rigth;
		}
		else if (elem.GetKey() == pElem[center].GetKey() || rigth - left == 1)
		{
			break;
		}
	}
	for (int i = count; i > center; i--)
	{
		pElem[i] = pElem[i - 1];
	}
	pElem[center] = elem;
	count++;
}

template<class T>
inline void TSTable<T>::AddElem(const mString key, const T & value)
{
	if (count == size)
		throw(1);
	int prevL = 0 , prevR = count;
	int rigth = count;
	int left = 0;
	int center = (rigth + left) / 2;

	while (rigth - left >= 1)
	{
		if (pElem[center].GetKey() > key)
		{
			rigth = center;
			center = (rigth + left) / 2;
			if (prevL == left && prevR == rigth)
				rigth = center - 1;
			prevL = left;
			prevR = rigth;
		}
		else if (pElem[center].GetKey()  < key)
		{
			left = center;
			center = (rigth + left) / 2;
			if (prevL == left && prevR == rigth)
				left = center + 1;
			prevL = left;
			prevR = rigth;
		}
		else if (pElem[center].GetKey() == key || rigth - left == 1)
		{
			break;
		}
	}
	for (int i = count; i > center; i--)
	{
		pElem[i] = pElem[i - 1];
	}
	pElem[center].SetValue(value);
	pElem[center].SetKey(key);
	count++;
}

template<class T>
inline T & TSTable<T>::Find(const mString & key)
{
	int rigth = count;
	int left = 0;
	int prevL = 0, prevR = count;
	int center = (rigth + left) / 2;

	while (rigth - left >= 1)
	{
		if (pElem[center].GetKey() > key)
		{
			rigth = center;
			center = (rigth + left) / 2;
			if (prevL == left && prevR == rigth)
				rigth = center - 1;
			prevL = left;
			prevR = rigth;
		}
		else if (pElem[center].GetKey() < key)
		{
			left = center;
			center = (rigth + left) / 2;
			if (prevL == left && prevR == rigth)
				left = center + 1;
			prevL = left;
			prevR = rigth;
		}
		else if (pElem[center].GetKey() == key)
		{
			return pElem[center].GetValue();
		}
		else
		{
			throw(1);
		}
	}
}

template<class T>
void TSTable<T>::DeleteElem(const mString & key)
{
	int rigth = count;
	int left = 0;
	int center = (rigth - left) / 2;

	while (rigth - left >= 1)
	{
		if (pElem[center].GetKey() > key)
		{
			rigth = center;
			center = (rigth - left) / 2;
		}
		else if (pElem[center].GetKey() < key)
		{
			left = center;
			center = (rigth - left) / 2;
		}
		else if (pElem[center].GetKey() == key)
		{
			for (int i = center; i < count - 1; i++)
			{
				pElem[i] = pElem[i + 1];
			}
			count--;
			return;
		}
		else
		{
			throw(1);
		}
	}
}

template<class T>
inline int TSTable<T>::GetCount()
{
	return count;
}
