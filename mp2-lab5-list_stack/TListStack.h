#pragma once
#include "TList.h"
#include <stddef.h>
template <class T>
class TListStack
{
	TNode<T>* pFirst;
public:
	TListStack() { pFirst = NULL; }
	~TListStack()
	{
		while (pFirst != NULL)
		{
			TNode<T>* pDel = pFirst;
			pFirst = pFirst->pNext;
			delete pDel;
		}
	}
	TListStack(const TListStack<T>& c)
	{
		TNode<T>* tmp = c.pFirst;
		TNode<T>* p, * prv;
		pFirst = NULL;
		prv = new TNode<T>;
		while (tmp != NULL)
		{
			p = new TNode<T>;

			p->Value = tmp->Value;
			p->pNext = NULL;
			if (pFirst == NULL)
			{
				pFirst = p;
				prv = p;
			}
			else
			{
				prv->pNext = p;
				prv = prv->pNext;
			}
			tmp = tmp->pNext;
			
		}
	}

	

	void Push(T el)
	{
		TNode<T>* ins = new TNode<T>;
		ins->Value = el;
		ins->pNext = pFirst;
		pFirst = ins;
	}
	T Pop()
	{
		
		if (!IsEmpty()) {
			T res = pFirst->Value;
			TNode<T>* First = pFirst;
			pFirst = pFirst->pNext;
			delete First;
			return res;
		}
		else throw - 1;
	}

	bool IsEmpty()
	{
		if (pFirst == NULL)
			return true;
		else return false;
	}

	bool IsFull()
	{
		TNode<T>* tmp = new TNode<T>;
		if (tmp == NULL)
			return true;
		else {
			delete tmp;
				return false;
		}
	}

	T Top() 
	{
		if (!IsEmpty())
			return pFirst->Value;
		else throw - 1;
	}

	void Clear() { pFirst = NULL; }

	bool operator==(const TListStack<T>& c) const
	{
		TNode<T>* tmp = pFirst;
		TNode<T>* tmpc = c.pFirst;
		while (tmp != NULL && tmpc != NULL)
		{
			if (tmp->Value != tmpc->Value)
				return false;
			else {
				tmp = tmp->pNext;
				tmpc = tmpc->pNext;
			}
		}
		if (tmp == NULL && tmpc == NULL)
			return true;
		else return false;
	}

	TListStack<T>& operator=(const TListStack& c)
	{
		TNode<T>* tmp = c.pFirst;
		TNode<T>* p, * prv;
		pFirst = NULL;
		prv = new TNode<T>;
		while (tmp != NULL)
		{
			p = new TNode<T>;

			p->Value = tmp->Value;
			p->pNext = NULL;
			if (pFirst == NULL)
			{
				pFirst = p;
				prv = p;
			}
			else
			{
				prv->pNext = p;
				prv = prv->pNext;
			}
			tmp = tmp->pNext;
		}
		return *this;
	}
};





