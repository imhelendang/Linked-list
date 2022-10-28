#ifndef LINKER_H_
#define LINKER_H_

#include <iostream>
#include <string>
#include "nodeType.h"
using namespace std;

void initializeList(nodeType *&, nodeType *&, int&);
//Initialize the list to an empty state.
//Postcondition: head = NULL, tail = NULL, count = 0;

bool isEmptyList(const nodeType *) ;
//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
// otherwise it returns false.

void print(nodeType *) ;
//Function to output the data contained in each node.
//Postcondition: none

int length(int) ;
//Function to return the number of nodes in the list.
//Postcondition: The value of count is returned.

void destroyList(nodeType *& , nodeType *& , int&);
//Function to delete all the nodes from the list.
//Postcondition: head= NULL, tail = NULL, count = 0;

void insertFirst(nodeType *&, nodeType *&, int&, const int&);
//Function to insert newItem at the end of the list.
//Postcondition: first points to the new list, newItem
// is inserted at the end of the list,
// last points to the last node in the list,
// and count is incremented by 1.

void insertLast(nodeType *&, nodeType *&, int&, const int&);
//Function to insert newItem at the beginning of the list.
//Postcondition: first points to the new list, newItem is
// inserted at the beginning of the list,
// last points to the last node in the list,
// and count is incremented by 1.

bool search(nodeType *srcHead, const int &searchItem) ;
//Function to determine whether searchItem is in the list.
//Postcondition: Returns true if searchItem is in the
// list, otherwise the value false is
// returned.

void deleteNode(nodeType *&srcHead, nodeType *&srcTail, int &srcCount, const int & deleteItem);
//Function to delete deleteItem from the list.
//Postcondition: If found, the node containing
// deleteItem is deleted from the list.
// first points to the first node, last
// points to the last node of the updated
// list, and count is decremented by 1.

void copyList(nodeType *srcHead, nodeType *&srcTail, int &srcCount,
		nodeType *& dstHead, nodeType *& dstTail, int &dstcount);
//Function to make a copy of otherList (src).
//Postcondition: A copy of otherList(src) is created and
// assigned to this list (dst).


#endif /* LINKER_H_ */
