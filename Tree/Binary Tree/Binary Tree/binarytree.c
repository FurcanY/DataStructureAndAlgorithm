#include <stdlib.h>
#include <stdio.h>
#include "binarytree.h"


// node olusturma fonksiyonu
struct Node* createNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode != NULL) {
		newNode->data = x;
		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;
}





//preorder kok sol sag
void preorder(struct Node* root) {
	printf("data :%d\t", root->data);

	if (root->left != NULL)
		preorder(root->left);

	if (root->right != NULL)
		preorder(root->right);
}

// inorder sol kok sag
void inorder(struct Node* root) {
	if (root->left != NULL)
		inorder(root->left);

	printf("data :%d\t", root->data);

	if (root->right != NULL)
		inorder(root->right);
}

//postorder sol sag kok
void postorder(struct Node* root) {

	if (root->left != NULL)
		postorder(root->left);

	if (root->right != NULL)
		postorder(root->right);

	printf("data :%d\t", root->data);
}

// agacin yüksekligini bulur
int getHeight(struct Node* root) {
	if (root == NULL)
		return -1;
	int lHeight = getHeight(root->left);
	int rHeight = getHeight(root->right);
	if (lHeight > rHeight)
		return ++lHeight;
	return ++rHeight;
}

//aranan kok agacin icerisinde var mý ? (x aranan deger)
int getValue(struct Node* root, int x) {
	if (root == NULL)
		return 0;
	if (root->data == x)
		return x;
	if (getValue(root->left, x))
		return x;
	return getValue(root->right, x);


}
//agaci siler (postorder'a gore)
void deleteTree(struct Node* root) {
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	printf("silinen deger =%d\n", root->data);
	free(root);
}

// agactaki en buyuk sayiyi bulur.
int getMax(struct Node* root) {
	if (root == NULL)
		return 0;
	int max = root->data;
	int ldata = getMax(root->left);
	int rdata= getMax(root->right);
	if (ldata > max)
		max = ldata;
	if (rdata > max)
		max= rdata;
	return max;
}