#pragma once
#include "mString.h"
template <class T>
class TBElem
{
protected:
	TBElem* right;
	TBElem* left;
	TBElem* parent;
	T value;
	mString key;
public:
	TBElem();
	TBElem( const mString& _key, const T& _value,TBElem<T>* _right = NULL, TBElem<T>* _left = NULL, TBElem<T>* _parent = NULL);
	TBElem(const TBElem<T>& elem);
	~TBElem();
	TBElem& operator=(const TBElem<T>& elem);
	bool operator==(const TBElem<T>& elem);
	bool operator!=(const TBElem<T>& elem);
	T& GetValue();
	mString& GetKey();
	void SetValue(const T& _value);
	void SetKey(const mString& _key);
	TBElem<T>* GetLeft();
	TBElem<T>* GetRight();
	TBElem<T>* GetParent();
	void SetLeft(TBElem<T>* link);
	void SetRight(TBElem<T>* link);
	void SetParent(TBElem<T>* link);
};

template<class T>
TBElem<T>::TBElem()
{
	right = NULL;
	left = NULL;
	parent = NULL;
}

template<class T>
inline TBElem<T>::TBElem(const mString & _key, const T& _value, TBElem<T>* _right, TBElem<T>* _left, TBElem<T>* _parent)
{
	value = _value;
	key = _key;
	parent = _parent;
	left = _left;
	right = _right;
}

template<class T>
TBElem<T>::TBElem(const TBElem<T>& elem)
{
	value = elem.value;
	key = elem.key;
	parent = elem.parent;
	left = elem.left;
	right = elem.right;
}

template<class T>
TBElem<T>::~TBElem()
{
	left = right = parent = NULL;
}

template<class T>
TBElem<T> & TBElem<T>::operator=(const TBElem<T> & elem)
{
	if (this != &elem)
	{
		left = elem.left;
		right = elem.right;
		parent = elem.parent;
		key = elem.key;
		value = elem.value;
	}
	return *this;
}

template<class T>
bool TBElem<T>::operator==(const TBElem<T>& elem)
{
	if (key == elem.key && value == elem.value)
		return true;
	else
		return false;
}

template<class T>
bool TBElem<T>::operator!=(const TBElem<T>& elem)
{
	if (key == elem.key && value == elem.value)
		return false;
	else
		return true;
}

template<class T>
inline T & TBElem<T>::GetValue()
{
	return value;
}

template<class T>
mString & TBElem<T>::GetKey()
{
	return key;
}

template<class T>
void TBElem<T>::SetValue(const T & _value)
{
	value = _value;
}

template<class T>
void TBElem<T>::SetKey(const mString & _key)
{
	key = _key;
}

template<class T>
inline TBElem<T>* TBElem<T>::GetLeft()
{
	return left;
}

template<class T>
inline TBElem<T>* TBElem<T>::GetRight()
{
	return right;
}

template<class T>
inline TBElem<T>* TBElem<T>::GetParent()
{
	return parent;
}

template<class T>
void TBElem<T>::SetLeft(TBElem<T>* link)
{
	left = link;
}

template<class T>
void TBElem<T>::SetRight(TBElem<T>* link)
{
	right = link;
}

template<class T>
void TBElem<T>::SetParent(TBElem<T>* link)
{
	parent = link;
}
