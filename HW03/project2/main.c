#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Node.h"
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, reorderList;
	int num = 0;
	NODE* listNum = NULL;
	NODE* listNumtwo = NULL;

	printf("Please enter a number for the list:\n");
	scanf("%d", &num);

	printf("Enter a numbers to add to list:\n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &reorderList);
		insert(&listNum, reorderList);
		insert(&listNumtwo, reorderList);
	}
	printf("\n");
	printList(listNum);

	printf("\n");
	NODE* newList = ReorderFirst(listNum);
	printf("The new linked list \n");
	printList(newList);
	printf("\n");

	ReorderSecond(&listNumtwo);
	printf("linked list in one passage\n");
	printList(listNumtwo);
	free(listNumtwo);

	return 0;
}