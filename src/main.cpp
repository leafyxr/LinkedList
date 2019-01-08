/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h> 
#include"../include/DoubleLinkedList.h"

int main() /** Entry point for the application */
{
	DoubleLinkedList<int> myList;
	if (myList.isEmpty()) {
		cout << "List is empty" << endl << endl;
	}
	else {
		cout << "List is not empty" << endl << endl;
	}
	myList.addNodeTail(56);
	myList.removeNodeHead();
	myList.addNodeTail(67);
	myList.addNodeTail(46);
	myList.removeNodeHead();
	myList.addNodeTail(21);
	myList.removeNodeTail();
	myList.addNodeTail(5);
	myList.addNodeTail(51);
	myList.addNodeTail(14);
	myList.addNodeTail(65);
	myList.removeNode(3);
	myList.addNodeTail(42);
	myList.addNodeTail(25);
	myList.addNodeTail(38);
	myList.getNode(4);
	myList.getNodeHead();
	myList.getNodeTail();
	cout << "Length of list is " << myList.getLength() << endl << endl;
	if (myList.isEmpty()) {
		cout << "List is empty" << endl << endl;
	}
	else {
		cout << "List is not empty" << endl << endl;
	}
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 1;
}
