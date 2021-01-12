#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Node.h"
#include <stdlib.h>
#include <string.h>

NODE* createList()
{
	return NULL;
}

int isEmptyList(NODE* head)
{
	return head == NULL;
}

NODE* ReorderFirst(NODE* head)
{
	NODE* even = NULL,* odd = NULL;
	NODE* headEven = NULL;
	NODE* headOdd = NULL;
	while (head) {
		if (head->key % 2) {
			if (odd)
				odd->next = head;
			else
				headOdd = head;
			odd = head;
		}
		else {
			if (even) even->next = head;
			else headEven = head;
			even = head;
		}
		head = head->next;
	}
	if (!odd) return headEven;
	if (!even)  return headOdd;

	odd->next = headEven;
	even->next = NULL;
	return headOdd;
}

//part 2

void ReorderSecond(NODE** head)
{
	NODE* temp = *head,* start;
	NODE* odd = NULL,*sumOdd = NULL;
	NODE* even = NULL,*sumEven = NULL;
	int counter;

	while (temp != NULL)
	{
		counter = temp->key;
		 start = temp;
		 temp = temp->next;

		if (counter % 2 == 0)
		{
			if (sumEven == NULL)
			{
				sumEven = start;
				even = sumEven;
			}
			else
			{
				sumEven->next = start;
				sumEven = sumEven->next;
			}
		}
		else
		{
			if (sumOdd == NULL)
			{
				sumOdd = start;
				odd = sumOdd;
			}
			else
			{
				sumOdd->next = start;
				sumOdd = sumOdd->next;
			}
		}
	}
	if (sumOdd != NULL)
	{
		sumOdd->next = even;
		*head = odd;
		if (sumEven != NULL)
		{
			sumEven->next = NULL;
		}
	}
	else
	{
		*head = even;
	}
}


void insert(NODE** n, int k)
{
	if (*n == NULL)
	{
		*n = (NODE*)malloc(sizeof(NODE));
		(*n)->next = NULL;
		(*n)->key = k;
	}
	else
	{
		NODE* node = *n;
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = (NODE*)malloc(sizeof(NODE));
		node->next->key = k;
		node->next->next = NULL;
	}
}

void printList(NODE* n)
{
	while (n->next != NULL)
	{
		printf("%d->", n->key);
		n = n->next;
	}
	printf("%d\n", n->key);
}
