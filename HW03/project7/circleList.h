#pragma once

typedef struct nodeList
{
	int key;
	struct nodeList* value;
} nodeList;

typedef struct nodeCircle
{
	nodeList* head;
} nodeCircle, * ptr;

void freeList(nodeList* num);
ptr createListCircle(char* c);
char* string(ptr ch);
ptr addint(ptr p, ptr q);






ptr createListCircle(char* num);
char* listToStringNumber(ptr list);
ptr addint(ptr p, ptr q);