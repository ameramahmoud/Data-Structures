
#pragma once 
#include "Generic_DS/Node.h"

using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T>* Head;

public:
	LinkedList();
	~LinkedList();
	void InsertBeg(const T& data);
	void DeleteAll();
	void Insert(const T& data);
	bool Find(T Key);
	int CountOccurance(const T& value);
	bool DeleteFirst();
	bool DeleteLast();
	bool CancelOrder(int value);
	T getItem(int id);
};

template < typename T>
LinkedList<T>::LinkedList()
{
	Head = nullptr;
}

template < typename T>
LinkedList<T>::~LinkedList()
{
	LinkedList::DeleteAll();
}

template < typename T>
void LinkedList<T>::InsertBeg(const T& data)
{
	Node<T>* R = new Node<T>(data);
	R->setNext(Head);
	Head = R;

}

template < typename T>
void LinkedList<T>::DeleteAll()
{
	Node<T>* P = Head;
	while (Head)
	{
		P = Head->getNext();
		delete Head;
		Head = P;
	}
}


template < typename T>
void LinkedList<T>::Insert(const T& data)
{
	Node<T>* P = Head;
	Node<T>* nptr = new Node <T>;
	nptr->setItem(data);
	if (P == nullptr)
	{
		InsertBeg(data);
	}
	else
	{
		while (P->getNext())
		{
			P = P->getNext();
		}
		P->setNext(nptr);
	}
}

template < typename T>
bool LinkedList<T>::Find(T Key)
{
	Node<T>* P = Head;
	if (P->getItem() == Key)
		return true;

	while (P->getNext())
	{
		if (P->getNext()->getItem() == Key)
			return true;
		P = P->getNext();
	}
	return false;
}

template < typename T>
int LinkedList<T>::CountOccurance(const T& value)
{
	int count = 0;
	Node<T>* P = Head;
	if (P->getItem() == value)
		count++;
	while (P->getNext())
	{
		if (P->getNext()->getItem() == value)
			count++;
		P = P->getNext();
	}
	return count;
}

template < typename T>
bool LinkedList<T>::DeleteFirst()
{
	Node<T>* P = Head;
	Head = P->getNext();
	delete P;
	return true;
}

template < typename T>
bool LinkedList<T>::DeleteLast()
{
	Node<T>* P = Head;
	if (P == nullptr)
	{
		delete P;
		return true;
	}
	else
	{
		while (P->getNext()->getNext())
		{
			P = P->getNext();
		}
		delete P->getNext();
		P->setNext(nullptr);
		return true;
	}
}

template < typename T>
bool LinkedList<T>::CancelOrder(int value)
{
	Node<T>* P = Head;
	if (!P)
	{
		return false;
	}
	if (P->getItem() == value)
	{
		DeleteFirst();
	}

	else
	{
		Node<T>* Curr = Head;
		while (P->getNext())
		{
			Curr = P;
			P = P->getNext();
			if (Curr->getNext()->getNext() == nullptr && P->getNext() == nullptr)
			{
				if (Curr->getNext()->getItem() == value)
					Curr->setNext(P->getNext());
			}
		}

		P = Head;
		while ((P->getNext()->getItem() == value))
		{
			P->setNext(P->getNext()->getNext());
			P = P->getNext();
		}

		while (P->getNext())
		{
			while ((P->getNext()->getItem() == value))
			{
				P->setNext(P->getNext()->getNext());
			}
			if (P)
				P = P->getNext();
		}
		return true;
	}


}


template<class T>
inline T LinkedList<T>::getItem(int id)
{
	Node<T>* P = head;
	while (P)
	{
		if (P->getItem()->GetID() == id)
		{

			return P->getItem();
		}
		P = P->getNext();
	}
	return NULL;
}




#pragma once
