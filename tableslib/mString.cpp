#include "mString.h"
#include <iostream>
#include <cstring>


mString::mString(char * _cstr)
{
  count = strlen(_cstr);
  if (count < 1)
    throw(__NEG_SIZE);

  str = new char[count + 1];
  for (int i = 0; i < count; i++)
    str[i] = _cstr[i];

	str[count] = '\0';
}

mString::mString(const mString & _string)
{
  count = _string.count;
	if (_string.str != NULL);
		str = new char[count + 1];
  for (int i = 0; i < count; i++)
    str[i] = _string.str[i];
}

mString::mString()
{
  count = 0;
  str = NULL;
}

mString::~mString()
{
	if (str != NULL)
		delete[] str;
}



mString & mString::operator=(const mString & _string)
{
  if (str != NULL && str != _string.str)
    delete[] str;

  count = _string.count;
  str = new char[count + 1];
  for (int i = 0; i < count; i++)
    str[i] = _string.str[i];
	str[count] = '\0';
  return *this;
}

mString & mString::operator=(char * _cstr)
{
  if (str != NULL)
    delete[] str;

  count = strlen(_cstr);
  str = NULL;
	if (count > 0)
		str = new char[count + 1];

  for (int i = 0; i < count; i++)
    str[i] = _cstr[i];

	str[count] = '\0';
  return *this;
}

bool mString::operator==(const mString & _string)
{
	if (count != _string.count)
		return false;

	for (int i = 0; i < count; i++)
		if (str[i] != _string.str[i])
			return false;

	return true;
}

bool mString::operator!=(const mString & _string)
{
	if (count != _string.count)
		return true;

	for (int i = 0; i < count; i++)
		if (str[i] != _string.str[i])
			return true;

	return false;
}

bool mString::operator<=(const mString & _string)
{
	unsigned long long sum1 = 0;
	unsigned long long sum2 = 0;

	for (int i = 0; i < count; i++)
	{
		sum1 *= 26;
		sum1 += (str[i] - 'a' + 1);
	}

	for (int i = 0; i < _string.count; i++)
	{
		sum2 *= 26;
		sum2 += (_string.str[i] - 'a' + 1);
	}

	if (sum1 <= sum2)
		return true;
	else
		return false;
}

bool mString::operator>=(const mString & _string)
{
	unsigned long long sum1 = 0;
	unsigned long long sum2 = 0;

	for (int i = 0; i < count; i++)
	{
		sum1 *= 26;
		sum1 += (str[i] - 'a' + 1);
	}

	for (int i = 0; i < _string.count; i++)
	{
		sum2 *= 26;
		sum2 += (_string.str[i] - 'a' + 1);
	}

	if (sum1 >= sum2)
		return true;
	else
		return false;
}

bool mString::operator<(const mString & _string)
{
	unsigned long long sum1 = 0;
	unsigned long long sum2 = 0;

	for (int i = 0; i < count; i++)
	{
		sum1 *= 26;
		sum1 += (str[i] - 'a' + 1);
	}

	for (int i = 0; i < _string.count; i++)
	{
		sum2 *= 26;
		sum2 += (_string.str[i] - 'a' + 1);
	}

	if (sum1 < sum2)
		return true;
	else
		return false;
}

bool mString::operator>(const mString & _string)
{
	unsigned long long sum1 = 0;
	unsigned long long sum2 = 0;

	for (int i = 0; i < count; i++)
	{
		sum1 *= 26;
		sum1 += (str[i] - 'a' + 1);
	}

	for (int i = 0; i < _string.count; i++)
	{
		sum2 *= 26;
		sum2 += (_string.str[i] - 'a' + 1);
	}

	if (sum1 > sum2)
		return true;
	else
		return false;
}

char * mString::GetCStr() const
{
  return str;
}

int mString::GetCount() const
{
  return count;
}
