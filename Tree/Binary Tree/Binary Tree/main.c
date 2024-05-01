#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarytree.h"



int main() {
	struct Node* root = createNode(10);
	root->left = createNode(9);
	root->right = createNode(3);
	root->right->left = createNode(5);
	root->left->left = createNode(2);
	root->left->left->left = createNode(20);
	root->left->right = createNode(200);
	int height = getHeight(root);
	printf("Agacin yuksekligi :%d\n", height);
	printf("Aranan deger agacta var mi ? = %d\n", getValue(root, 110));
	//deleteTree(root);
	printf("Agactaki en buyuk deger =%d\n", getMax(root));

	return 0;
}