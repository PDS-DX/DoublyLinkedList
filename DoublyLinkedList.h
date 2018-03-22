#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#pragma warning(disable : 4715)

#include "Node.h"
#include <cstdint>
#include <exception>

template <class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	void insertHead(T &);
	void insertTail(T &);
	T deleteFromHead();
	T deleteFromTail();
	bool deleteIndex(const T &);
	bool isEmpty() const;
	bool isInList(const T &);
	uint32_t size() const;
private:
	Node<T> *pHead, *pTail;
	uint32_t numElements;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	pHead = pTail = 0;
	numElements = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (pHead)
	{
		Node<T> * tmp;
		tmp = pHead;
		while (!isEmpty())
		{
			if (tmp == pTail)
			{
				delete tmp;
				numElements--;
				pHead = pTail = 0;
				return;
			}
			else
			{
				pHead = pHead->next;
				pHead->prev = 0;
				delete tmp;
				numElements--;
				tmp = pHead;
			}
		}
	}
}

template <class T>
void DoublyLinkedList<T>::insertHead(T & t)
{
	if (pHead)
	{
		Node<T> * tmp = new Node <T>;
		tmp->data = t;
		tmp->next = pHead;
		pHead->prev = tmp;
		pHead = tmp;
		numElements++;
	}
	else
	{
		pHead = pTail = new Node <T> ;
		pHead->data = t;
		numElements++;
	}
}

template <class T>
void DoublyLinkedList<T>::insertTail(T & t)
{
	if (pHead)
	{
		pTail->next = new Node <T>;
		pTail->next->prev = pTail;
		pTail = pTail->next;
		pTail->data = t;
		numElements++;
	}
	else
	{
		pHead = pTail = new Node <T>;
		pHead->data = t;
		numElements++;
	}
}

template <class T>
T DoublyLinkedList<T>::deleteFromHead()
{
	try
	{
		if (!pHead)
			throw exception("DoublyLinkedList<T>::deleteFromHead() : Cannot Delete Nodes From Empty List");
		T t = pHead->data;
		if (pHead == pTail)
		{
			delete pHead;
			pHead = pTail = 0;
			return t;
		}
		pHead = pHead->next;
		delete pHead->prev;
		numElements--;
		pHead->prev = 0;
		return t;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

template <class T>
T DoublyLinkedList<T>::deleteFromTail()
{
	try
	{
		if (!pHead)
			throw exception("DoublyLinkedList<T>::deleteFromTail() : Cannot Delete Nodes From Empty List");
		T t = pTail->data;
		if (pHead == pTail)
		{
			delete pHead;
			pHead = pTail = 0;
			return t;
		}
		pTail = pTail->prev;
		delete pTail->next;
		numElements--;
		pTail->next = 0;
		return t;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

template <class T>
bool DoublyLinkedList<T>::deleteIndex(const T & t)
{
	try
	{
		// check if list is empty
		if (!pHead)
			throw exception("DoublyLinkedList<T>::deleteIndex() : Cannot Delete Nodes From Empty List");
		// check index is head of list
		if (pHead->data == t)
		{
			// if only one node exists
			if (pHead == pTail)
			{
				delete pHead;
				pHead = pTail = 0;
				return true;
			}
			// else, delete head
			else
			{
				pHead = pHead->next;
				delete pHead->prev;
				pHead->prev = 0;
				numElements--;
				return true;
			}
		}

		Node<T> * tmp;
		// traverse nodes until index is found or until end of list
		for (tmp = pHead->next; tmp != 0 && tmp->data != t; tmp = tmp->next);
		if (tmp != 0)
		{
			if (tmp = pTail)
			{
				pTail = pTail->prev;
				pTail->next = 0;
				delete tmp;
				numElements--;
				return true;
			}
			// if index is not the last node
			else
			{
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
				delete tmp;
				numElements--;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	catch (exception e)
	{
		cout << e.what() << endl;
		return false;
	}
}

template <class T>
bool DoublyLinkedList<T>::isEmpty() const
{
	if (numElements > 0)
		return false;
	else
		return true;
}

template <class T>
bool DoublyLinkedList<T>::isInList(const T & t)
{
	if (pHead)
	{
		Node<T> * tmp;
		for (tmp = pHead; tmp != 0 && tmp->data != t; tmp = tmp->next);
		if (tmp != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template <class T>
uint32_t DoublyLinkedList<T>::size() const
{
	return numElements;
}
#endif