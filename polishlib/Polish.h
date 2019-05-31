#pragma once
#include "exception.h"
#include "StackList.h"
#include <iostream>

class Polish
{
protected:
	char* str;
	int GetPriority(char sym); 
	int IsOperation(char sym); 
public:
	Polish(char* exp);
	~Polish();
	double Calculate();
	char* Convert(char * exp);
};

