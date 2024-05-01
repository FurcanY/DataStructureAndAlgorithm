#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"


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

// agaca eleman ekleme fonksiyonu
void insert(struct Node** root, int x) {
	if ((*root) == NULL)
		(*root) = createNode(x);
	if (x > (*root)->data)
		insert(&(*root)->right, x);
	if (x <  (*root)->data)
		insert(&(*root)->left, x);
}

// agaca  eleman ekleme (void olmayan)
struct Node* insert2(struct Node* root, int x) {
	if (root == NULL)
		root = createNode(x);
	if (x > (root->data))
		root->right = insert2(root->right, x);
	if (x < (root->data))
		root->left = insert2(root->left, x);
	return root;
}

// inorder sol kok sag
void inorder(struct Node* root) {
	if (root->left != NULL)
		inorder(root->left);

	printf("data :%d\t", root->data);

	if (root->right != NULL)
		inorder(root->right);
}

int find(struct Node* root, int x) {
	if (root == NULL)
		return -1;
	if (root->data == x)
		return x;
	if (x > root->data)
		return find(root->right, x);
	else
		return find(root->left, x);

}

// yapraklari silen fonskiyon
struct Node* leafDelete(struct Node* root) {
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
	{
		free(root);
		return NULL;
	}
	root->left = leafDelete(root->left);
	root->right = leafDelete(root->right);
	return root;
}

//agactaki maksimum degeri bulur
int getMax(struct Node* root) {
	if (root == NULL)
		return -1;
	int max = root->data;
	int ldata = getMax(root->left);
	int rdata = getMax(root->right);
	if (ldata > max)
		max = ldata;
	if (rdata > max)
		max = rdata;
	return max;

}
//agactaki minimum degeri bulur
int getMin(struct Node* root) {
	if (root == NULL)
		return INT_MAX;
	int min = root->data;
	int ldata = getMin(root->left);
	int rdata = getMin(root->right);
	if (ldata < min)
		min = ldata;
	if (rdata <  min)
		min = rdata;
	return min;

}

//agac binary search tree mi kontrol eder.
int BST(struct Node* root) {
	if (root == NULL)
		return 1;
	if (root->left != NULL && root->data <  getMax(root->left))
		return 0;
	if (root->right != NULL && root->data > getMin(root->right))
		return 0;
	if ((!BST(root->left)) || (!BST(root->right)))
		return 0;
	return 1;
}