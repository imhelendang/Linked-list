#include "linker.h"
#include "nodeType.h"

//Stylesheet:
//*******************************************************************************************************
// * PROGRAMMED BY : Ngoc Dang Tran
// * CLASS : CS1B
// * SECTION : MW: 9:30 - 11:50
// * FILE NAME : driver.cpp
// * ASSIGNMENT : Linked List
//*******************************************************************************************************
//  PURPOSE : Purpose of this lab is to familiarize yourself with Linked List (P.2)
//*******************************************************************************************************
//* The program below displays a menu on the screen, which allows the user to activate any of the modules
/*
**********************************************************
*                          MAIN MENU                     *
*                 <0> Initialize List                    *
*                 <1> IsEmptyList                        *
*                 <2> Print                              *
*                     <a> Print src                      *
*                     <b> Print dst                      *
*                 <3> Length                             *
*                 <4> DestroyList                        *
*                 <5> Search                             *
*                 <6> Insert First                       *
*                 <7> Insert Last                        *
*                 <8> Delete Node                        *
*                 <9> Copy List                          *
*                 <Q> Quit                               *
**********************************************************
                   Enter your choice (1-8):*/
//**********************************************************************************************************
//Main program

int main()
{
	//Data table
	nodeType *srcHead = NULL;
	nodeType *srcTail = NULL;
	nodeType *dstHead = NULL;
	nodeType *dstTail = NULL;
	char choice, discard;
	int num, searchItem;;
	int srcCount, dstCount;
	bool empty = false;
	bool quit = false;
	int newItem = 0;

	//Display menu
	do
	    {
		system("clear");
		cout << left << "**********************************************************" << endl;
		cout 		 << "*                          MAIN MENU                     *" << endl;
		cout 		 << "*                 <0> Initialize List                    *" << endl;
		cout 		 << "*                 <1> IsEmptyList                        *" << endl;
		cout 		 << "*                 <2> Print                              *" << endl;
		cout 		 << "*                     <a> Print src                      *" << endl;
		cout 		 << "*                     <b> Print dst                      *" << endl;
		cout 		 << "*                 <3> Length                             *" << endl;
		cout		 << "*                 <4> DestroyList                        *" << endl;
		cout 		 << "*                 <5> Search                             *" << endl;
		cout 		 << "*                 <6> Insert First                       *" << endl;
		cout 		 << "*                 <7> Insert Last                        *" << endl;
		cout 		 << "*                 <8> Delete Node                        *" << endl;
		cout 		 << "*                 <9> Copy List                          *" << endl;
		cout 		 << "*                 <Q> Quit                               *" << endl;
		cout << left << "**********************************************************" << endl;
		cout 		 << "         Enter your choice (1-9) and Q/q to quit: ";
		cin >> choice;
		cin.ignore();

		//Switch Cases
		switch(choice)
		     {
			case '0':
				initializeList(srcHead, srcTail, srcCount);
				initializeList(dstHead, dstTail, dstCount);
				break;


			case '1':
				empty = isEmptyList(srcHead);
				if(!empty)
					cout << "\nThe list isn't empty!" << endl;
				else
					cout << "\nThe list is empty!" << endl;
				break;

			case '2':
				//Check if the list is empty
				if(srcHead == NULL)
					cout << "The list is empty. Initialize first!" << endl;
				else
					{
						cout << "Please enter (a/b): ";
						cin >> choice;
						if(choice == 'a')
							{
								cout << "\nsrcList: ";
								print(srcHead);
							}
						else
							{
								cout << "\ndstList: ";
								print(dstHead);
							}
					}
				break;

			case '3':
				if(srcHead == NULL)
					  cout << "The list is empty. Initialize first!" << endl;
				else
				   {
					  length(srcCount);
					  cout << "\nLength: " << srcCount << endl;
				   }
				break;
			case '4':
				if(srcHead == NULL)
					  cout << "The list is empty. Initialize first!" << endl;
				else
					  destroyList(srcHead, srcTail, srcCount);
				break;
			case '5':
				if(srcHead == NULL)
					  cout << "The list is empty. Initialize first!" << endl;
				else
					{
						cout << "Enter number to search: ";
						cin >> searchItem;
						cin.ignore();
						if(search(srcHead, searchItem))
							cout << searchItem << " is in the list!" << endl;
						else
							cout << searchItem << " isn't in the list!" << endl;
					}
				break;
			case '6':
				cout << "\nEnter value for newItem to insert forward: ";
				cin >> newItem;
				insertFirst(srcHead, srcTail, srcCount, newItem);
				break;
			case '7':
				cout << "\nEnter value for newItem to insert backward: ";
				cin >> newItem;
				insertLast(srcHead, srcTail, srcCount, newItem);
				break;
			case '8':
				cout << "\nEnter the number to be " << "deleted: ";
				cin >> num;
				deleteNode(srcHead, srcTail, srcCount, num);
				break;
			case '9':
				if(srcHead == NULL)
					  cout << "The list is empty. Initialize first!" << endl;
				else
					copyList(srcHead, srcTail, srcCount, dstHead, dstTail, dstCount);
				break;
			case 'Q':
				quit = true;
				break;
			default:
				cout << "You have entered an invalid choice. Please enter a number in the range 1-9." << endl;
				break;
		     }
		cout << "Press any key to continue..";
		cin >> discard;
		cin.ignore();
	} while(!quit);
return 0;
}
