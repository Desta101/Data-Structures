#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circleList.h"

#define N 5
#define SIZE 1000
#define UNDER_TEN_THOUSAND 100000


void freeList(nodeList* num)
{
	if (num == NULL)
		return;
	num = num->value;
	while (num->key != -1)
	{
		nodeList* helper = num->value;
		free(num);
		num = helper;
	}
	free(num->value);
}


ptr createListCircle(char* c)
{
	ptr ptrList;
	nodeList* node;
	nodeList* counter;
	int dig = N;
	char ch[N +1];

	ptrList = (nodeCircle*)malloc(sizeof(nodeCircle));
	ptrList->head = (nodeList*)malloc(sizeof(nodeList));
	if (!ptrList->head)
		return NULL;
	ptrList->head->key = -1;
	ptrList->head->value = ptrList->head;
    counter = ptrList->head;

	for (int i = strlen(c) - 1; i > 0; i -= dig) {
		if (i < dig)
			dig = i;
		memcpy(ch, &c[i - dig], dig);
		ch[dig] = '\0';

		node = (nodeList*)malloc(sizeof(nodeList));
		node->key = atoi(ch);
		node->value = ptrList->head;
		counter->value = node;
		counter = counter->value;
	}
	return ptrList;
}

char* string(ptr ch)
{
	char* num;
	char* count;
	int temp = 0;

	nodeList* node = ch->head;
	while (node->value->key != ch->head->key) {
		node = node->value;
		temp++;
	}

	num = (char*)malloc(SIZE * sizeof(char));
	if (!num)
		return NULL;

	count = (char*)malloc((N + 1) * sizeof(char));
	if (!count)
		return NULL;

	strcpy(num, "");
	while (node->key != ch->head->key) {
		sprintf(count, "%d", node->key);
		strcat(num, count);
		for (int i = 0; i < temp; i++)
			node = node->value;
	}
	return num;
}

ptr addint(ptr p, ptr q)
{
	nodeList* node;
	nodeList* list;
	int sum, number, temp = 0;

	if (!p->head || !q->head)
		return;

	node = p->head->value;
	list = q->head->value;

	while (node->key != p->head->key && list->key != q->head->key)
	{
		sum = node->key + list->key + temp;
		number = sum % UNDER_TEN_THOUSAND;
		temp = sum / UNDER_TEN_THOUSAND;
		node->key = number;
		node = node->value;
		list = list->value;
	}

	return p;
}

void main() {
	ptr ptr1, ptr2;
	char num1[SIZE], num2[SIZE];

	printf("Please enter the first number: \n");
	fgets(num1, SIZE, stdin);
	printf("Please enter the second number: \n");
	fgets(num2, SIZE, stdin);

	ptr1 = createListCircle(num1);
	printf("The first number is: %s\n", string(ptr1));
	ptr2 = createListCircle(num2);
	printf("The second number is: %s\n", string(ptr2));
	ptr1 = addint(ptr1, ptr2);
	printf("Total numbers: %s\n", string(ptr1));
}