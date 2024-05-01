#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"


int main() {

	struct Node* tree=NULL;
	insert(&tree, 10);
	insert(&tree, 5);
	insert(&tree, 6);
	insert(&tree, 9);
	insert(&tree, 18);
	insert(&tree, 15);
	insert(&tree, 25);
	inorder(tree);
	printf("\n");
	struct Node* tree2 = createNode(10);
	tree2->left = createNode(9);
	tree2->left->right = createNode(15);
	tree2->right= createNode(32);
	inorder(tree2);
	printf("\n");
	printf("tree 2 %d\n", BST(tree2));
	printf("tree 1 %d\n", BST(tree));
	printf("%d\n", find(tree, 15));




	return 0;
}