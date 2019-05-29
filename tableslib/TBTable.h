#pragma once
#include "TBElem.h"
#include "StackList.h"

template <class T>
class TBTable 
{
protected:
	static TBElem<T> exemp;
	TBElem<T>* node;
	int count;
public:
	TBTable();
	TBTable(const TBTable& table);
	~TBTable();
	int GetCount();
	TBElem<T>* GetNode() const;
	void AddElem(TBElem<T>& elem);
	void DeleteElem(const mString& key);
	T& Find(const mString& key);
};

template<class T>
TBTable<T>::TBTable()
{
	node = NULL;
	count = 0;
}

template<class T>
TBTable<T>::TBTable(const TBTable & table)
{
	count = table.count;
	node = new TBElem<T>(*(table.node));
	TStackList<TBElem<T>*> st1;
	TStackList<TBElem<T>*> st2;
	st1.Put(node);
	st2.Put(table.node);
	while (st2.IsEmpty() != true)
	{
		TBElem<T>* tmp1 = st1.Get();
		TBElem<T>* tmp2 = st2.Get();
		if (tmp2->GetLeft() != NULL)
		{
			tmp1->SetLeft(new TBElem<T>(*(tmp2->GetLeft())));
			st1.Put(tmp1->GetLeft());
			st2.Put(tmp2->GetLeft());
			tmp1->GetLeft()->SetParent(tmp1);
		}
		if (tmp2->GetRight() != NULL)
		{
			tmp1->SetRight(new TBElem<T>(*(tmp2->GetRight())));
			st1.Put(tmp1->GetRight());
			st2.Put(tmp2->GetRight());
			tmp1->GetRight()->SetParent(tmp1);
		}
	}
}

template<class T>
TBTable<T>::~TBTable()
{

}

template<class T>
int TBTable<T>::GetCount()
{
	return count;
}

template<class T>
TBElem<T>* TBTable<T>::GetNode() const
{
	return node;
}

template<class T>
void TBTable<T>::AddElem(TBElem<T>& elem)
{
	if (count == 0)
	{
		node = new TBElem<T>(elem);
		count++;
	}
	else
	{
		TBElem<T>* fir = node;
		TBElem<T>* par;
		while (fir != NULL)
		{
			par = fir;
			if (elem.GetKey() > fir->GetKey())
				fir = fir->GetRight();
			else if (elem.GetKey() < fir->GetKey())
				fir = fir->GetLeft();
			else
				throw (1);
		}
		count++;
		if (elem.GetKey() > par->GetKey())
		{
			par->SetRight(new TBElem<T>(elem));
			par->GetRight()->SetParent(par);
		}
		else if (elem.GetKey() < par->GetKey())
		{
			par->SetLeft(new TBElem<T>(elem));
			par->GetLeft()->SetParent(par);
		}
	}
}

template<class T>
void TBTable<T>::DeleteElem(const mString & key)
{
}

template<class T>
T & TBTable<T>::Find(const mString & key)
{
	TBElem<T>* tmp = node;
	while (tmp != NULL)
	{
		if (tmp->GetKey() > key)
			tmp = tmp->GetLeft();
		else if (tmp->GetKey() < key)
			tmp = tmp->GetRight();
		else
			return tmp->GetValue();
	}
	
	throw(1);
}
