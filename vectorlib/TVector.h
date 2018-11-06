#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

using namespace std;


template <class ValType>
class TVector 
{
	protected:
		ValType * pVector;
		int Size; // размер вектора
		int StartIndex; // индекс первого элемента вектора
	public:
		TVector(int s = 10, int si = 0);
		TVector(const TVector &v); // конструктор копирования 
		~TVector(); 
		int GetSize() { return Size; } // размер вектора
		int GetStartIndex() { return StartIndex; } // индекс первого элемента
		ValType & GetValue(int pos); // доступ с контролем индекса
		ValType & operator[] (int pos); // доступ
		int operator==(const TVector &v); // сравнение
		TVector & operator= (const TVector &v); // присванивание
											// скалярные операции
		TVector operator+ (const ValType &val); // прибавить скаляр 
		TVector operator- (const ValType &val); // вычесть скаляр
		TVector operator* (const ValType &val); // умножить на скаляр
											// векторные операции
		TVector operator+ (const TVector &v); // сложение 
		TVector operator- (const TVector &v); // вычитание
		TVector operator* (const TVector &v); // скалярное произведение
										  // ввод-вывод
		friend istream & operator>>(istream &in, TVector &v);
		friend ostream & operator<<(ostream &out, const TVector &v);
};

#endif

