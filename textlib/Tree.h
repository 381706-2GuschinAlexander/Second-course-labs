#pragma once
#include <iostream>
#include "StackList.h"

class TTree
{
protected:
	TTree* sameLevel;
	TTree* nextLevel;
	char letter;
	int level;
	static char* memory;
	static TTree* start;
	static TTree* end;
	static TTree* cur_free;
	static int tree_size;
	static int busy_tree_size;
public:
	TTree(const int _level);
	TTree(const char* word);
	TTree(const char _letter = 0);
	TTree(const TTree& tree);
	~TTree();
	TTree& operator=(const TTree& tree);
	TTree& operator+=(const TTree& tree);
	TTree& operator+=(const char _letter);
	TTree& operator+=(const char* word);
	void* operator new (const size_t size);
	void operator delete (void* tree);
	void Output();
	char* ToString();
	void SetSameLevel(TTree* _same_level);
	void SetNextLevel(TTree* _next_level);
	void SetLetter(const char _letter);
	void SetLevel(const int _level);
	static void SetTreeSize(const int size);
	TTree* GetSameLevel();
	TTree* GetNextLevel();
	char GetLetter();
	int GetLevel();
	static int GetTreeSize();//////tests!!!!!!
	static int GetTreeBusySize();//////
	TTree* Clone();
	void Initialization(int size);
	void GarbageCollector();
	static void ClearMemory(void);
};

