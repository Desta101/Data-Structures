#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

QueueNode* createQueue()
{
	return NULL;
}

int isEmptyQueue(QueueNode* Q)
{
	if (Q == NULL)
		return ;
}

void insert(QueueNode** Q, queueinfo x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	if (!(*Q))
	{
		(*Q) = node;
		node->value = x;
		node->next = node;
	}
	else
	{
		node->value = x;
		node->next = (*Q)->next;
		(*Q)->next = node;
	}
}

void delafter(QueueNode* p, queueinfo* x)
{

	QueueNode* node = p->next->next;
		*x = p->next->value;
		free(p->next);
		p->next = node;
	
}

void printQueue(QueueNode* Q) {

	if (isEmptyQueue(Q) == 0)

		printf("%d ", Q->value);
}


void insertList(int num, int sum)
{
	QueueNode* node = NULL;
	queueinfo value = 0;
	int i;

	for ( i = 1; i <= num; i++)
	{
		insert(&node, (num - i )+ 1);
	}

	printf("Order of elimination: ");

	while (node->next != node)
	{
		for ( i = 0; i < sum - 1; i++)
		{
			node = node->next;
		}
		delafter(node, &value);
		printf("%d ", value);
	}
	delafter(node, &value);
	printf("\nLeader: %d", value);
}


