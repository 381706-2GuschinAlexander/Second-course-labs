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
	void AddElem(const mString key, const T & value);
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
	TStackList<TBElem<T>*> points;
	points.Put(node);
	while (points.IsEmpty() != true)
	{
		TBElem<T>* tmp = points.Get();
		if (tmp != NULL)
		{
			if (tmp->GetLeft() != NULL)
				points.Put(tmp->GetLeft());
			if(tmp->GetRight() != NULL)
				points.Put(tmp->GetRight());
			delete tmp;
		}
	}
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
void TBTable<T>::AddElem(const mString key, const T & value)
{
	if (count == 0)
	{
		node = new TBElem<T>(key, value);
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
			par->SetRight(new TBElem<T>(key, value));
			par->GetRight()->SetParent(par);
		}
		else if (elem.GetKey() < par->GetKey())
		{
			par->SetLeft(new TBElem<T>(key, value));
			par->GetLeft()->SetParent(par);
		}
	}
}

template<class T>
void TBTable<T>::DeleteElem(const mString & key)
{
	TBElem<T>* tmp = node;
	TBElem<T>* par;
	while (tmp != NULL)
	{
		if (tmp->GetKey() == key)
		{
			if (tmp == node)
				par = tmp;

			break;
		}
		par = tmp;
		if (tmp->GetKey() > key)
			tmp = tmp->GetLeft();
		else if (tmp->GetKey() < key)
			tmp = tmp->GetRight();
	}

	if (par == NULL && tmp != NULL)
		throw(1);

	if(tmp != node)
		if (par->GetLeft() == tmp)
			par->SetLeft(NULL);
		else
			par->SetRight(NULL);

	TStackList<TBElem<T>*> points;
	TStackList<TBElem<T> > res;
	TBElem<T>* st;
	points.Put(tmp);
	while (points.IsEmpty() != true)
	{
		st = points.Get();
		if (st->GetLeft() != NULL)
		{
			points.Put(st->GetLeft());
			res.Put(*(st->GetLeft()));
		}
		if (st->GetRight() != NULL)
		{
			points.Put(st->GetRight());
			res.Put(*(st->GetRight()));
		}
		delete st;
		
	}

	if (tmp == par)
		node = NULL;

	while (res.IsEmpty() != true)
	{
		TBElem<T> t = res.Get();
		t.SetRight(NULL);
		t.SetLeft(NULL);
		if (node == NULL)
			node = new TBElem<T>(t);
		else
			AddElem(t);
	}
	count--;
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
