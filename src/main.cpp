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
#include <iostream>
#include <memory>
#include"../include/DoubleLinkedList.h"

int main() /** Entry point for the application */
{
	DoubleLinkedList myList;
	myList.addNodeHead(3);
	myList.addNodeHead(6);
	myList.addNodeHead(4);
	myList.addNodeHead(2);
	myList.addNodeHead(6);
	
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 1;
}
