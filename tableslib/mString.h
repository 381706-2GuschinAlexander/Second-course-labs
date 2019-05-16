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
	~mString();
  mString& operator=(const mString& _string);
  mString& operator=(char* _cstr);
	bool operator==(const mString& _string);
	bool operator!=(const mString& _string);
	bool operator<=(const mString& _string);
	bool operator>=(const mString& _string);
  char* GetCStr() const;
  int GetCount() const;
};