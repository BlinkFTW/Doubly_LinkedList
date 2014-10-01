prog : dListTest.c dLinkedList.o dLinkedList.h
	gcc dListTest.c -o dListTest.exe dLinkedList.o
dLinkedList.o : dLinkedList.c dLinkedList.h
	gcc dLinkedList.c -c
