#include "Tree.h"

int TTree::tree_size = 100;
int TTree::busy_tree_size = 0;
char* TTree::memory = 0;
TTree* TTree::start = NULL;
TTree* TTree::end = NULL;
TTree* TTree::cur_free = NULL;

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

void TTree::Initialization(int size)
{
	if (size < 0)
		throw(1);
	if (memory == 0)
	{
		tree_size = size;
		memory = new char[sizeof(TTree) * size];
		start = (TTree*)memory;
		cur_free = end = start;
		for (int i = 0; i < size - 1; i++)
		{
			end->nextLevel = (TTree*)(&(memory[(i + 1) * sizeof(TTree)]));
			end = end->nextLevel;
		}
	}
}

void * TTree::operator new(const size_t size)
{
	if (busy_tree_size == tree_size)
		throw(1);

	if (cur_free != 0)
	{
		TTree* tmp = cur_free;
		cur_free = cur_free->nextLevel;
		busy_tree_size++;
		return tmp;
	}
}
