#pragma once

class mString
{
protected:
  char* str;
  int count;
public:
  mString(char * _cstr);
  mString(const mString& _string);
  mString();
  mString& operator=(const mString& _string);
  mString& operator=(char* _cstr);
  char* GetCStr();
  int GetCount();
};