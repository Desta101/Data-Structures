#pragma once

typedef  itemType;
typedef struct binTree {
	int info;
	struct binTree* right;
	struct binTree* left;
}treeNode, * tree_ptr;


void rangeSearch(tree_ptr t, itemType u, itemType v);
tree_ptr Binary(tree_ptr n1, tree_ptr n2, int sum);
void insert(tree_ptr* ptr, int val);
void printTree(tree_ptr ptr);

