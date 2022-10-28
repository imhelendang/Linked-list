#include "linker.h"
#include "nodeType.h"

//Initialize the list to an empty state.
//Postcondition: head = NULL, tail = NULL, count = 0;
void initializeList(nodeType *&first, nodeType *&last, int& count)
{
	if(isEmptyList(first))
	   {
		first = NULL;
		last = NULL;
		count = 0;
	   }
	else
		destroyList(first, last, count);
		//if the list has any nodes, delete them
}

//Function to determine whether the list is empty.
//Postcondition: Returns true if the list is empty,
// otherwise it returns false.
bool isEmptyList(const nodeType *first)
{
	bool yesEmpty;
	if(first == NULL)
		yesEmpty = true;
	else
		yesEmpty = false;
	return yesEmpty;
}

//Function to output the data contained in each node.
//Postcondition: none
void print(nodeType *first)
{
	nodeType *current;
	current = first;
	cout << endl;
	while (current != NULL) //while more data to print
	   {
		cout << current->info << " ";
		current = current->link;
	   }
    cout << endl;
return;
}

//Function to return the number of nodes in the list.
//Postcondition: The value of count is returned.
int length(int count)
{
	return count;
} //end length

//Function to delete all the nodes from the list.
//Postcondition: head= NULL, tail = NULL, count = 0;
//If empty call initialize
void destroyList(nodeType *& first, nodeType *& last, int &count)
{
	char discard;
	nodeType *temp;		//pointer to deallocate the memory

	//occupied by the node
	while (first != NULL) 	//while there are nodes in
	   { //the list
	   	temp = first; 		//set temp to the current node
	   	first = first->link;	//advance first to the next node
	   	delete temp; 		//deallocate the memory occupied by temp
       }
	last = NULL; //initialize last to nullptr; first has
         //already been set to nullptr by the while loop

	cout << "\nThe list is destroyed!" << endl;
	cout << "Press any key to continue..";
	cin >> discard;
	cin.ignore();
	count = 0;
return;
}

//Function to insert newItem at the end of the list.
//Postcondition: first points to the new list, newItem
// is inserted at the end of the list,
// last points to the last node in the list,
// and count is incremented by 1.
void insertFirst(nodeType *&first, nodeType *&last, int&count, const int& newItem)
{
	nodeType *newNode; //pointer to create the new node
	newNode = new nodeType; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = first; //insert newNode before first

	first = newNode; //make first point to the actual first node

	count++; //increment count

	if (last == NULL) //if the list was empty, newNode is also the last node in the list
	   last = newNode;

return;
}//end insertFirst


//Function to insert newItem at the beginning of the list.
//Postcondition: first points to the new list, newItem is
// inserted at the beginning of the list,
// last points to the last node in the list,
// and count is incremented by 1.
void insertLast(nodeType *&first, nodeType *&last, int&count, const int& newItem)
{
	nodeType *newNode;
	newNode = new nodeType;
	newNode->info = newItem;
	newNode->link = NULL;

	if (first == NULL) //if the list is empty, newNode is
	//both the first and last node
	   {
		first = newNode;
		last = newNode;
		count++; //increment count
	   }
	else //the list is not empty, insert newNode after last
	   {
		last->link = newNode; //insert newNode after last
		last = newNode; //make last point to the actual
		//last node in the list
		count++; //increment count
	   }
return;
}

//Function to determine whether searchItem is in the list.
//Postcondition: Returns true if searchItem is in the
// list, otherwise the value false is
// returned.
bool search(nodeType *srcHead, const int &searchItem)
{
	nodeType *current; //pointer to traverse the list
	bool found = false;
	current = srcHead; //set current to point to the first
	//node in the list

	while (current != nullptr && !found) //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to the next node
return found;
}


 //Function to delete deleteItem from the list.
//Postcondition: If found, the node containing
// deleteItem is deleted from the list.
// first points to the first node, last
// points to the last node of the updated
// list, and count is decremented by 1.
void deleteNode(nodeType *&srcHead, nodeType *&srcTail, int &srcCount, const int & deleteItem)
{
	nodeType *current; //pointer to traverse the list
	nodeType *trailCurrent; //pointer just before current
	bool found;
	if (srcHead == nullptr) //Case 1; the list is empty.
	cout << "Cannot delete from an empty list." << endl;
	else
		{
		if (srcHead->info == deleteItem) //Case 2
			{
				current = srcHead;
				srcHead = srcHead->link;
				srcCount--;
				if (srcHead == nullptr) //the list has only one node
					srcTail = nullptr;
				delete current;
			}
		else //search the list for the node with the given info
			{
				found = false;
				trailCurrent = srcHead; //set trailCurrent to point
				//to the first node
				current = srcHead->link; //set current to point to
				//the second node
			while (current != nullptr && !found)
				{
					if (current->info != deleteItem)
					{
						trailCurrent = current;
						current = current-> link;
					}
					else
						found = true;
				}//end while
				if (found) //Case 3; if found, delete the node
					{
						trailCurrent->link = current->link;
						srcCount--;
						if (srcTail == current) //node to be deleted
						//was the last node
							srcTail = trailCurrent; //update the value
						//of last
						delete current; //delete the node from the list
					}
					else
						cout << "The item to be deleted is not in " << "the list." << endl;
			}//end else
		}//end else
return;
}


//Function to make a copy of otherList (src).
//Postcondition: A copy of otherList(src) is created and
// assigned to this list (dst).
void copyList(nodeType *srcHead, nodeType *&srcTail, int &srcCount,
				nodeType *& dstHead, nodeType *& dstTail, int &dstcount)
{
	nodeType *newNode; //pointer to create a node
	nodeType *current; //pointer to traverse the list

	if (dstHead != nullptr) //if the list is nonempty, make it empty
			destroyList(dstHead, dstTail, dstcount);
	else
		{
			current = srcHead; //current points to the
			//list to be copied
			dstcount = srcCount;
			//copy the first node
			dstHead = new nodeType; //create the node
			dstHead->info = current->info; //copy the info
			dstHead->link = nullptr; //set the link field of
			//the node to nullptr
			dstTail = dstHead; //make last point to the
			//first node
			current = current->link; //make current point to
			//the next node
			//copy the remaining list
			while (current != nullptr)
				{
					newNode = new nodeType; //create a node
					newNode->info = current->info; //copy the info
					newNode->link = nullptr; //set the link of
					//newNode to nullptr
					dstTail->link = newNode; //attach newNode after last
					dstTail = newNode; //make last point to
					//the actual last node
					current = current->link; //make current point
					//to the next node
				}//end while
		}//end else
return;
}//end copyList



