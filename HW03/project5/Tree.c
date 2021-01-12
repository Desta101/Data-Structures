#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"


void rangeSearch(tree_ptr t, itemType u, itemType v)
{
	if (t == NULL)
		return;
	rangeSearch(t->left, u, v);
	if (t->info >= u && t->info <= v)
	{
		printf("%2d", t->info);
	}
	rangeSearch(t->right, u, v);
}

tree_ptr Binary(tree_ptr n1, tree_ptr n2, int sum)
{
	tree_ptr type = (tree_ptr)malloc(sizeof(treeNode));
	if (!type)
		return NULL;

	type->info = sum;
	type->left = n1;
	type->right = n2;
	return type;
}

void insert(tree_ptr* ptr, int val)
{
	if (val == (*ptr)->info)
		return;

	if (val < (*ptr)->info)
	{
		if (NULL == ((*ptr)->left))
			(*ptr)->left = Binary(NULL, NULL, val);
		else
			insert(&(*ptr)->left, val);
	}
	else
	{
		if (NULL == ((*ptr)->right))
			(*ptr)->right = Binary(NULL, NULL, val);
		else
			insert(&(*ptr)->right, val);
	}
}

void printTree(tree_ptr ptr)
{
	if (!ptr)
		return;
	printf("%d ", ptr->info);
	printTree(ptr->left);
	printTree(ptr->right);
}

int main() {
	int u = 4, v = 9;
	tree_ptr ptr = (tree_ptr)malloc(sizeof(treeNode));
	ptr = Binary(NULL, NULL, 0);
	for (int i = 1; i < 15; i++)
		insert(&ptr, i);

	printf("Printing Tree:\n");
	printTree(ptr);
	printf("\n");
	printf("The Range Search(u=%d v=%d):\n", u, v);
	rangeSearch(ptr, u, v);
	printf("\n");
	free(ptr);
	return 0;
}
