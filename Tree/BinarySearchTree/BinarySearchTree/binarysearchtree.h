#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

// agac node'u olusturma fonksiyonu
struct Node* createNode(int x);

// agaca eleman ekleme fonksiyonu
void insert(struct Node** root, int x);

// inorder sol kok sag
void inorder(struct Node* root);

// agaca eleman ekleme (void olmayan)
struct Node* insert2(struct Node* root, int x);

// agactak aranan elemani bulan fonskiyon.
int find(struct Node* root, int x);

// yapraklari silen fonskiyon
struct Node* leafDelete(struct Node* root);

//agactaki maksimum degeri bulur
int getMax(struct Node* root);

//agactaki minimum degeri bulur
int getMin(struct Node* root);

//agac binary search tree mi kontrol eder.
int BST(struct Node* root);


#endif // !BINARYSEARCHTREE_H

