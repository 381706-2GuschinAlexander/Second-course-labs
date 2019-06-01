#pragma once
#include "exception.h"
#include "TreeIterator.h"

class Text : public TTree
{
protected:
	TTree* root;
public:
	Text(const char* string);
	Text(Text& text);
	Text(TTree& tree);
	TTree* GetRoot();
	void Insert(const int pos, const char* string);
	void Insert(TTree* start, TTree* string);
	int Find(const char* string);
	TTree* FindTree(const char* string);
	char* Copy(const int start, const int len);
	TTree* Copy(TTree* start/*must be word*/, const int len);
	void Delete(const int start_del, const int lenght);
	void Delete(TTree* start_del, const int lenght);
};

