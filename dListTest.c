/*

Description:
	This program tests all the functions, found in dLinkedList.c,
	in the implementation of a dynamic doubly Linked List.

	Certain tests will include:
	- inserting items into the list
	- deleting an item from the middle of the list
	- verifying the size of the list
	- accessing a number in the list from main()
	
*/

#include <stdio.h>
#include "dLinkedList.h"


int main()
{
	// Initialize the "end" of the list
	ListNode *startPtr = NULL;
	
	// Pushing values onto the list
	insert(&startPtr, 5);
	insert(&startPtr, 4);
	insert(&startPtr, 3);
	insert(&startPtr, 2);
	insert(&startPtr, 1);
	
	printList( startPtr );
	
	// Delete one of the items
	if( !isEmpty(startPtr) ){
		printf("The value removed from the list was: %d\n", delete( &startPtr, 2 ) );
	}
	
	printList( startPtr );
	
	// Show the current size of the list
	printf("The current list size is: %d\n", listSize( startPtr ) );
	
	// Access the 2nd value in the list from main()
	printf("The value %d is from the list\n",startPtr->nextPtr->data);
	
	free( startPtr );
	return 0;
};
