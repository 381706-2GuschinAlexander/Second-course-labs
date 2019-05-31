#include "Tree.h"
#include <iostream>
#include <cstring>

int TTree::tree_size = 100;
int TTree::busy_tree_size = 0;
char* TTree::memory = 0;
TTree* TTree::start = NULL;
TTree* TTree::end = NULL;
TTree* TTree::freeP = NULL;

TTree::TTree(const int _level)
{
	if (_level < 0 || _level > 3)
		throw(1);
	Initialization(tree_size);
	level = _level;
	letter = 0;
	sameLevel = NULL;
	nextLevel = NULL;
}

TTree::TTree(const char * word)
{
	Initialization(tree_size);
	int len = strlen(word);
	level = 2;
	sameLevel = NULL;
	nextLevel = new TTree(word[0]);
	TTree* tmpNext = nextLevel;
	for (int i = 1; i < len; i++)
	{
		tmpNext->sameLevel = new TTree(word[i]);
		tmpNext = tmpNext->sameLevel;
	}
}

TTree::TTree(const char _letter)
{
	Initialization(tree_size);
	level = 3;
	letter = _letter;
	sameLevel = NULL;
	nextLevel = NULL;
}

TTree::TTree(const TTree & tree)
{
	Initialization(tree_size);
	level = tree.level;
	letter = tree.letter;
	sameLevel = tree.sameLevel;
	nextLevel = tree.nextLevel;
}

TTree::~TTree()
{
	TTree* tmp;
	TStackList<TTree*> stack;
	stack.Put(this);
	if (stack.IsEmpty() == false)
		tmp = stack.Get();
	if (tmp->GetSameLevel() != NULL)
		stack.Put(tmp->GetSameLevel());
	if (tmp->GetNextLevel() != NULL)
		stack.Put(tmp->GetNextLevel());
	tmp->letter = -1;
}

TTree & TTree::operator=(const TTree & tree)
{
	if (level != tree.level)
		throw(1);

	if (this != &tree)
	{
		sameLevel = tree.sameLevel;
		nextLevel = tree.nextLevel;
		letter = tree.letter;
	}
}

TTree & TTree::operator+=(const TTree & tree)
{
	TTree* tmp = this;
	if (level != tree.level)
		while (tmp->level != tree.level)
			tmp = tmp->nextLevel;
	while (tmp->sameLevel != NULL)
		tmp = tmp->sameLevel;
	tmp->sameLevel = new TTree(tree);
	return *this;
}

TTree & TTree::operator+=(const char _letter)
{
	TTree* tmp = new TTree(_letter);
	*this += *tmp;
	return *this;
}

TTree & TTree::operator+=(const char * word)
{
	TTree* tmp = new TTree(word);
	*this += *tmp;
	return *this;

}

void TTree::Initialization(int size)
{
	if (size < 0)
		throw(1);
	if (memory == NULL)
	{
		tree_size = size;
		memory = new char[sizeof(TTree) * size];
		start = (TTree*)memory;
		freeP = end = start;
		for (int i = 0; i < size - 1; i++)
		{
			end->nextLevel = (TTree*)(&(memory[(i + 1) * sizeof(TTree)]));
			end = end->nextLevel;
		}
	}
}

void TTree::GarbageCollector()
{
	freeP = NULL;
	TTree* tmp;
	for (int i; i < tree_size; i++)
	{
		if (((TTree*)(&(memory[i * sizeof(TTree)])))->letter == -1)
		{
			tmp = freeP;
			freeP = ((TTree*)&(memory[i * sizeof(TTree)]));
			((TTree*)&(memory[i * sizeof(TTree)]))->nextLevel = tmp;
		}
	}
}

void TTree::ClearMemory(void)
{
	delete[] memory;
	memory = NULL;
	busy_tree_size = 0;
}

void * TTree::operator new(const size_t size)
{
	if (busy_tree_size == tree_size)
		throw(1);

	if (freeP != NULL)
	{
		TTree* tmp = freeP;
		freeP = freeP->nextLevel;
		busy_tree_size++;
		return tmp;
	}
}

void TTree::operator delete(void * tree)
{
	TTree* tmp = (TTree*)tree;
	tmp->nextLevel = freeP;
	freeP = tmp;
	tmp->letter = -1;
	tmp->level = 0;
	tmp->sameLevel = NULL;
}

void TTree::SetSameLevel(TTree * _sameLevel)
{
	sameLevel = _sameLevel;
}

void TTree::SetNextLevel(TTree * _nextLevel)
{
	nextLevel = _nextLevel;
}

void TTree::SetLetter(const char _letter)
{
	letter = _letter;
}

void TTree::SetLevel(const int _level)
{
	level = _level;
}

void TTree::SetTreeSize(const int treeSize)
{
	tree_size = treeSize;
}

TTree * TTree::GetSameLevel()
{
	return sameLevel;
}

TTree * TTree::GetNextLevel()
{
	return nextLevel;
}

char TTree::GetLetter()
{
	return letter;
}

int TTree::GetLevel()
{
	return level;
}

int TTree::GetTreeSize()
{
	return tree_size;
}

int TTree::GetTreeBusySize()
{
	return busy_tree_size;
}
