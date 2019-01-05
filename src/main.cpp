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
#include"../include/doubleLinkedList.h"

int main() /** Entry point for the application */
{
	DoubleLinkedList myList;
	//myList.addNode(5);
	//myList.addNode(7);
	//myList.addNode(8);
	//myList.addNode(3);
	//myList.addNode(4);
	
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 1;
}
