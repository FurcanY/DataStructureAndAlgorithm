#ifndef BINARY_TREE_H
#define BINARY_TREE_H

//prototpip fonksiyonlar ve soyut veri yapilari

//binary tree soyut veri yapisi
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// yeni bir node olusturur
struct Node* createNode(int x);
// kok sol sag olacak sekilde agaci siralar
void preorder(struct Node* root);
// sol kok sag olacak sekilde agaci siralar
void inorder(struct Node* root);
// sol sag kok olacak sekilde agaci siralar
void postorder(struct Node* root);
// agacin yüksekligini bulur
int getHeight(struct Node* root);
// aranan degeri agacta arar( x = aranan deger ) 
int getValue(struct Node* root, int x);
// agacin elemanlarini siler 
void deleteTree(struct Node* root);
// agactaki en buyuk sayiyi bulur ve geri dondurur
int getMax(struct Node* root);


#endif