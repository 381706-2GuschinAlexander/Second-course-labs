#include "mString.h"
#include <iostream>
#include <cstring>

mString::mString(char * _cstr)
{
  count = strlen(_cstr);
  if (count < 1)
    throw(1);

  str = new char[count];
  for (int i = 0; i < count; i++)
    str[i] = _cstr[i];
}

mString::mString(const mString & _string)
{
  count = _string.count;
  str = new char[count];
  for (int i = 0; i < count; i++)
    str[i] = _string.str[i];
}

mString::mString()
{
  count = 0;
  str = NULL;
}

mString & mString::operator=(const mString & _string)
{
  if (str != NULL)
    delete[] str;

  count = _string.count;
  str = new char[count];
  for (int i = 0; i < count; i++)
    str[i] = _string.str[i];

  return *this;
}

mString & mString::operator=(char * _cstr)
{
  if (str != NULL)
    delete[] str;

  count = strlen(_cstr);
  if (count < 1)
    throw(1);

  str = new char[count];
  for (int i = 0; i < count; i++)
    str[i] = _cstr[i];

  return *this;
}

char * mString::GetCStr()
{
  return str;
}

int mString::GetCount()
{
  return count;
}
