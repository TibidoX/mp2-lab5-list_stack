#pragma once
#include "TList.h"
#include <stddef.h>
#include <iostream>
using namespace std;
template <class T>
class TListQueue
{
	TNode<T>* pFirst; //head
	TNode<T>* pLast; //tail
public:
	TListQueue() { pFirst = pLast = NULL; }
	void Push(T el)
	{
		if (IsFull())
			throw - 1;
		TNode<T>* ins = new TNode<T>;
		ins->Value = el;
		ins->pNext = NULL;
		if (pLast != NULL) {
			pLast->pNext = ins;
		}
		else pFirst = ins;

		pLast = ins;

	}

	T Pop()
	{
		if (IsEmpty())
			throw - 1;
		T res = pFirst->Value;
		TNode<T>* del = pFirst;
		if (pFirst->pNext = NULL)
			pLast = NULL;
		pFirst = pFirst->pNext;
		delete del;
		return res;
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

	~TListQueue()
	{
		TNode<T>* tmp = pFirst;
		while (tmp != NULL)
		{
			TNode<T>* tmp1 = tmp;
			tmp = tmp->pNext;
			delete tmp1;
		}
	}

	TListQueue(const TListQueue& c)
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
			pLast = p;
		}
	}

	bool operator==(const TListQueue<T>& c) const
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

	TListQueue<T>& operator=(const TListQueue& c)
	{
		//TListQueue<T> res;
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
			pLast = p;
		}
		return *this;
	}
	void Print()
	{
		TNode<T>* t = pFirst;
		while (t != NULL) {
			cout << t->Value << " ";
			t = t->pNext;
		}
		cout << endl;
	}
	void Clear() { pFirst = pLast = NULL; }
};