#include "DoublyLinkedList.h"

using namespace std;

int main()
{

	fstream output;
	output.open("unit_test_output.txt", ios_base::out);
	DoublyLinkedList<int> * list;
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;

	// test insertHead() with deleteFromHead();
	list = new DoublyLinkedList <int>;
	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}
	output << "DoublyLinkedList<T>::deleteFromHead() using DoublyLinkedList<T>:insertHead()" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0, j = 9; i < 10; i++, j--)
	{
		output << list->deleteFromHead() << " : " << arr[j] << endl;
	}

	delete list;

	// test insertHead() with deleteFromTail()
	list = new DoublyLinkedList <int>;
	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}
	output << "DoublyLinkedList<T>::deleteFromTail() using DoublyLinkedList<T>:insertHead()" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0; i < 10; i++)
	{
		output << list->deleteFromTail() << " : " << arr[i] << endl;
	}

	delete list;

	// test insertTail() with deleteFromTail();
	list = new DoublyLinkedList <int>;
	for (int i = 0; i < 10; i++)
	{
		list->insertTail(arr[i]);
	}
	output << "DoublyLinkedList<T>::deleteFromTail() using DoublyLinkedList<T>:insertTail()" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0, j = 9; i < 10; i++, j--)
	{
		output << list->deleteFromTail() << " : " << arr[j] << endl;
	}

	delete list;

	// test insertTail() with deleteFromHead();
	list = new DoublyLinkedList <int>;
	for (int i = 0; i < 10; i++)
	{
		list->insertTail(arr[i]);
	}
	output << "DoublyLinkedList<T>::deleteFromHead() using DoublyLinkedList<T>:insertTail()" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0; i < 10; i++)
	{
		output << list->deleteFromHead() << " : " << arr[i] << endl;
	}

	delete list;

	// test deleteIndex() with forward iteration of existing elements
	list = new DoublyLinkedList <int>;
	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}
	output << "DoublyLinkedList<T>::deleteIndex() with forward iteration of existing elements" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (list->deleteIndex(arr[i]))
			output << "true : true" << endl;
		else
			output << "false : true" << endl;
	}

	// test deleteIndex() with reverse iteration of existing elements
	list = new DoublyLinkedList <int>;
	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}
	output << "DoublyLinkedList<T>::deleteIndex() with reverse iteration of existing elements" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int j = 9; j >= 0; j--)
	{
		if (list->deleteIndex(arr[j]))
			output << "true : true" << endl;
		else
			output << "false : true" << endl;
	}

	delete list;

	// test deleteIndex() with non-existing elements
	list = new DoublyLinkedList <int>;
	int arr2[10];
	for (int i = 0; i < 10; i++)
		arr2[i] = i + 10;
	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}
	output << "DoublyLinkedList<T>::deleteIndex() with non-existing elements" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (list->deleteIndex(arr2[i]))
			output << "true : false" << endl;
		else
			output << "false : false" << endl;
	}

	delete list;

	// test isEmpty() with full list
	list = new DoublyLinkedList <int>;

	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}

	output << "DoublyLinkedList<T>::isEmpty() with full list" << endl;
	output << "a : e (actual : expected)" << endl;
	if (list->isEmpty())
		output << "true : false" << endl;
	else
		output << "false : false" << endl;

	delete list;

	// test isEmpty() with empty list
	list = new DoublyLinkedList <int>;

	output << "DoublyLinkedList<T>::isEmpty() with empty list" << endl;
	output << "a : e (actual : expected)" << endl;
	if (list->isEmpty())
		output << "true : true" << endl;
	else
		output << "false : true" << endl;

	delete list;

	// test isInList() with existing elements
	list = new DoublyLinkedList <int>;

	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}

	output << "DoublyLinkedList<T>::isInList() with existing list elements" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (list->isInList(arr[i]))
			output << "true : true" << endl;
		else
			output << "false : true" << endl;
	}

	delete list;

	// test isInList() with non-existing elements
	list = new DoublyLinkedList <int>;

	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}

	output << "DoublyLinkedList<T>::isInList() with non-existing list elements" << endl;
	output << "a : e (actual : expected)" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (list->isInList(arr2[i]))
			output << "true : false" << endl;
		else
			output << "false : false" << endl;
	}

	delete list;

	// test size() while deleting elements
	list = new DoublyLinkedList <int>;

	for (int i = 0; i < 10; i++)
	{
		list->insertHead(arr[i]);
	}

	output << "DoublyLinkedList<T>::size() while deleting 10 elements" << endl;
	output << "a : e (actual : expected)" << endl;

	for (int i = 0, j = 10; i < 10; i++, j--)
	{
		output << list->size() << " : " << j << endl;
		list->deleteFromHead();
	};

	delete list;

	// test size while adding elements
	list = new DoublyLinkedList <int>;

	output << "DoublyLinkedList<T>::size() while inserting 10 elements" << endl;
	output << "a : e (actual : expected)" << endl;

	for (int i = 0; i < 10; i++)
	{
		output << list->size() << " : " << i << endl;
		list->insertHead(arr[i]);
	};

	delete list;

	return 0;
}
