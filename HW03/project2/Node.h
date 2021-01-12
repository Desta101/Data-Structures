#pragma once


typedef struct node
{
	int key;
	struct node* next;
}NODE;


NODE* createList();
int isEmptyList(NODE* head);
NODE* ReorderFirst(NODE* head);
void ReorderSecond(NODE** head);
void insert(NODE** n, int k);
void printList(NODE* n);


