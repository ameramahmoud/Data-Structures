#pragma once
#include "Generic_DS/Node.h"

template <typename T>
class PriorityQueue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, int pri);
	bool dequeue(T& frntEntry);
	bool peekFront(T& frntEntry)  const;
	T* toArray(int& count);	//returns array of T (array if items)
	~PriorityQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: PriorityQueue()
The constructor of the PriorityQueue class.

*/

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this PriorityQueue is empty.

Input: None.
Output: True if the PriorityQueue is empty; otherwise false.
*/
template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this PriorityQueue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::enqueue(const T& newEntry, int pri)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	newNodePtr->setPri(pri);
	// Insert the new node
	if (isEmpty())
	{
		frontPtr = newNodePtr; // The PriorityQueue is empty
		backPtr = newNodePtr; // New node is at back
		return true;
	}
	else if (frontPtr->getPri() < pri)
	{
		newNodePtr->setNext(frontPtr);
		frontPtr = newNodePtr;
		return true;
	}
	else if (backPtr->getPri() >= pri)
	{
		backPtr->setNext(newNodePtr);
		backPtr = newNodePtr; // New node is at back
		return true;
	}
	return false;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this PriorityQueue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// PriorityQueue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in PriorityQueue
		backPtr = nullptr;

	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;


	return true;

}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
gets the front of this PriorityQueue. The operation does not modify the PriorityQueue.

Input: None.
Output: The front of the PriorityQueue.
return: flase if PriorityQueue is empty
*/
template <typename T>
bool PriorityQueue<T>::peekFront(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: toArray
returns an array of "T"
Output: count: the length of the returned array (zero if PriorityQueue is empty)
returns: The array of T. (nullptr if PriorityQueue is empty)
*/

template <typename T>
T* PriorityQueue<T>::toArray(int& count)
{
	count = 0;

	if (!frontPtr)
		return nullptr;
	//counting the no. of items in the PriorityQueue
	Node<T>* p = frontPtr;
	while (p)
	{
		count++;
		p = p->getNext();
	}


	T* Arr = new T[count];
	p = frontPtr;
	for (int i = 0; i < count; i++)
	{
		Arr[i] = p->getItem();
		p = p->getNext();
	}
	return Arr;
}

#pragma once
