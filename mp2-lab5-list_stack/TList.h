#pragma once
#include <stddef.h>
#include "TNode.h"
template <class T>
class TList
{
protected:
	TNode<T>* pFirst;
public:
	TList() { pFirst = NULL; }
	void ins_first(T val)
	{
		TNode<T>* First = new TNode<T>;
		First->Value = val;
		First->pNext = pFirst;
		pFirst = First;
	}
	void ins_current(TNode<T>* current, T val)
	{
		TNode<T>* newEl = new TNode<T>;
		newEl->Value = val;
		newEl->pNext = current->pNext;
		current->pNext = newEl;
	}

	void del_firts()
	{
		if (pFirst != NULL) {
			TNode<T>* pDel = pFirst;
			pFirst = pFirst->pNext;
			delete[] pDel;
		}
	}

	void del_last()
	{
		TNode<T>* prev = pFirst;
		TNode<T>* current = pFirst;
		while (current->pNext != NULL) {
			prev = current;
			current = current->pNext;
		}
		delete current;
		prev->pNext = NULL;
	}
};

