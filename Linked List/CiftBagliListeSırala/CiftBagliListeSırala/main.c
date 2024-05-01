#include <stdio.h>
#include <stdlib.h>


// listenin 1. elemný ile sonuncu elemanýný 2. elemaný ile sondan ikinci elemanýný vs deðiþtiren programý yazýn
struct node {
	int data;
	struct node* prev;
	struct node* next;
};

struct node* createNode(int data) {
	struct node* yeniNode = (struct node*)malloc(sizeof(struct node));
	yeniNode->data = data;
	yeniNode->prev = NULL;
	yeniNode->next = NULL;
	return yeniNode;
}
void sondanEkle(struct node* head, int _veri) {
	struct node* yeniDugum = createNode(_veri);
	struct node* tmp = head;
	for (; tmp->next != NULL; tmp = tmp->next); //son dugumu bulma islemi
	tmp->next = yeniDugum;
	yeniDugum->prev = tmp;
}
void yazdir(struct node* head) {
	struct node* tmp = head;
	while (tmp != NULL) {
		printf("%d \t", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
void sirala(struct node* head) {
	struct node* tmp = head;
	struct node* tmp2 = head;
	int tempData;
	for (tmp2 = head; tmp2->next != NULL; tmp2 = tmp2->next)
		for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
			if (tmp->data > tmp->next->data) {
				tempData = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = tempData;
			}
		}
}

int main() 
{
	struct node* List = createNode(5);
	sondanEkle(List, 4);
	sondanEkle(List, 3);
	sondanEkle(List, 2);
	sondanEkle(List, 1);
	sondanEkle(List, 0);
	yazdir(List);
	sirala(List);
	yazdir(List);

	return 0;
}
