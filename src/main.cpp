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
	DoubleLinkedList<int> myList;//!<Create list
	if (myList.isEmpty()) {//!<Check if empty
		cout << "List is empty" << endl << endl;
	}
	else {
		cout << "List is not empty" << endl << endl;
	}
	myList.addNodeAfter(38, 1);//!<add to node
	myList.addNodeAfter(63, 5);//!<add to node
	myList.addNodeTail(56);//!< add to tail
	myList.removeNodeHead();//!<remove head
	myList.addNodeTail(67);//!<Add to tail
	myList.addNodeTail(46);//!<Add to tail
	myList.removeNodeHead();//!<Remove Head
	myList.addNodeTail(21);//!<Add to Tail
	myList.removeNodeTail();//!<Remove Tail
	myList.addNodeTail(5);//!<Add to Tail
	myList.addNodeTail(51);//!<Add to Tail
	myList.addNodeTail(14);//!<Add to Tail
	myList.addNodeTail(65);//!<Add to Tail
	myList.removeNode(3);//!<Remove 3rd Node
	myList.addNodeTail(42);//!<Add to Tail
	myList.addNodeTail(25);//!<Add to Tail
	myList.addNodeTail(38);//!<Add to Tail
	myList.getNodeData(4);//!<Get 4th Node
	myList.getHeadData();//!<Get Head Data
	myList.getTailData();//!<Get Tail Data
	myList.addNodeAfter(38, 5);//!<Add to Node
	myList.addNodeBefore(38, 5);//!<Add to Node
	myList.selectNode(3);//!<Select 3rd Node
	myList.getSelectedNodeData();//!<Get selected node Data
	myList.scrollForwards();//!<Select next node
	myList.getSelectedNodeData();//!<Get selected node Data
	myList.scrollBackwards();//!<Select previous node
	myList.getSelectedNodeData();//!<Get selected node Data
	myList.addNodeAfterSelected(24);//!<Add to Node
	myList.addNodeBeforeSelected(89);//!<Add to Node
	cout << "Length of list is " << myList.getLength() << endl << endl;//!<Get Length
	if (myList.isEmpty()) {//!<Check if empty
		cout << "List is empty" << endl << endl;
	}
	else {
		cout << "List is not empty" << endl << endl;
	}
	myList.deleteAllNodes();//!<Delete all nodes
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
	return 1;
}
