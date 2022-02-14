#pragma once
#include <stddef.h>
template <class T>
struct TNode
{
	T Value;
	TNode* pNext;


	int length(TNode* f)
	{
		TNode* current = f;
		int res = 0;
		while (current != NULL) {
			current = current->pNext;
			res++;
		}
		return res;
	}

	void ins_last(TNode* f, int val)
	{
		TNode* current = f;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		TNode* n = new TNode;
		n->Value = val;
		n->pNext = NULL;
		current->pNext = n;
	}
};

