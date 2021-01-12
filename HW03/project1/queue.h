#pragma once

typedef int queueinfo;
typedef struct node
{
	queueinfo value;
	struct node* next;
} QueueNode;

QueueNode* createQueue();
int isEmptyQueue(QueueNode* Q);
void insert(QueueNode** Q, queueinfo x);
void delafter(QueueNode* p, queueinfo* x);
void printQueue(QueueNode* Q);
void insertList(int number, int sum);