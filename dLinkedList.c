#include "dLinkedList.h"

/*	Structure Reference
typedef struct ListNode{
	int data;
	struct ListNode *prevPtr;
	struct ListNode *nextPtr;
} ListNode;
*/


/*-------------------------------------------------------------------
 * name: insert
 * inputs:	**sPtr	(ListNode pointer) 
 *					value		(int)
 * outputs: <none>
 * Pushes any integer value to the begining of the linked list sPtr.
 * Call from main(): insert(&ListNodePtr, num);
 *------------------------------------------------------------------*/
void insert( ListNode **sPtr, int value ){
	ListNode *newPtr = malloc( sizeof(ListNode) );
	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->prevPtr = NULL;
		// Set the prevPtr of original "first" node
		if( !isEmpty(*sPtr) ){
			(*sPtr)->prevPtr = newPtr;
		}
		newPtr->nextPtr = *sPtr;
		*sPtr = newPtr;
	}
	else{
		printf("No Memory Available, %d not inserted\n",value);
	}
};


/*-------------------------------------------------------------------
 * name: delete
 * inputs:	**sPtr	(ListNode pointer) 
 *					value		(int)
 * outputs: value		(int)
 * Searches the linked list sPtr for the specified value to be deleted.
 * If value not found, prints error message and returns 0.
 * Call from main(): delete(&ListNodePtr, num);
 *------------------------------------------------------------------*/
int delete( ListNode **sPtr, int value ){
	ListNode *tempPtr;
	ListNode *currentPtr;
	//ListNode *prevPtr;
	
	// If first item in list matches item to be removed
	if(value == (*sPtr)->data){
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		(*sPtr)->prevPtr = NULL;
		free( tempPtr );
		return value;
	}
	// Otherwise previousPtr must begin at 1st item in list and so on 
	else{
		currentPtr = (*sPtr)->nextPtr;
		
		// Loop through list to find item's LOCATION to set currentPtr
		while(currentPtr->data != value && currentPtr != NULL){
			//prevPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		// Assuming value was found in the list
		if(currentPtr != NULL){
			tempPtr = currentPtr;
			
			// If item is at end of list
			if(currentPtr->nextPtr == NULL){
				
				currentPtr->prevPtr->nextPtr = NULL;
			}
			else{
				currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
				currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
			}
			
			free( tempPtr );
			return value;
		}
		else{
			printf("%d not found in list",value);
		}
	}
	return 0;
};

/*-------------------------------------------------------------------
 * name: isEmpty
 * inputs:	*sPtr	(ListNode pointer)
 * outputs: True or False	(Boolean)
 * Returns true if sPtr points to an empty list.
 * Call from main(): isEmpty( ListNodePtr );
 *------------------------------------------------------------------*/
int isEmpty( ListNode *sPtr ){
	return sPtr == NULL;
};

/*-------------------------------------------------------------------
 * name: listSize
 * inputs:	*currentPtr	(ListNode pointer)
 * outputs: count	(int)
 * Counts the number of nodes in the list.
 * Call from main(): listSize( ListNodePtr );
 *------------------------------------------------------------------*/
int listSize( ListNode *currentPtr ){
	int count = 0;
	if( !isEmpty(currentPtr) ){
		while( currentPtr != NULL ){
			count++;
			currentPtr = currentPtr->nextPtr;
		}
	}
	return count;
};

/*-------------------------------------------------------------------
 * name: printList
 * inputs:	*currentPtr	(ListNode pointer)
 * outputs: <none>
 * Loops through list and prints "data" member of each list node.
 * Call from main(): printList( ListNodePtr );
 *------------------------------------------------------------------*/
void printList( ListNode *currentPtr ){
	if( isEmpty(currentPtr) ){
		printf("List is empty\n");
	}
	else{
		printf("The List is: \nNULL <=> ");
		while(currentPtr != NULL){
			printf("%d <=> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n");
	}
};
