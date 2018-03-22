#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
	// constructors/destructor
	Node()
	{
		next = prev = 0;
	};
	Node(Node<T> & n) : data(n.data), next(n.next), prev(n.prev)
	{};

	// overloaded operators
	Node<T> & operator = (T & t)
	{
		data = t;
		return *this;
	}

	T data;
	Node<T> *next, *prev;
};

#endif