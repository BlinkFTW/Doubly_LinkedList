#ifndef _DLINKEDLIST_H
#define _DLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	struct ListNode *prevPtr;
	int data;
	struct ListNode *nextPtr;
} ListNode;

void insert( ListNode **sPtr, int value );
int delete( ListNode **sPtr, int value );
int isEmpty( ListNode *sPtr );
int listSize( ListNode *currentPtr ); 
void printList( ListNode *currentPtr );

#endif
