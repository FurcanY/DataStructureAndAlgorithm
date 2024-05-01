#include <stdio.h>
#include <stdlib.h>

/*
	Çift baðlantýlý bir listenin ilk öðesinin deðerini son öðeyle,
	ikinci öðeyi ikinci son öðeyle vb. deðiþtirecek bir program yazýn.
*/
struct node {
	int data;
	struct node* next;
};
struct node* createNode(int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void yazdir(struct node* d1) {

	while (d1 != NULL) {
		printf("%d\t", d1->data);
		d1 = d1->next;
	}
	printf("\n");
}
void SondanEkle(struct node* head, int data) {
	struct node* newNode = createNode(data);
	struct node* tmp = head;
	for (; tmp->next != NULL; tmp = tmp->next);
	tmp->next = newNode;

}
void degistir(struct node* head) {
	struct node* tmp = head;
	struct node* tmp2 = head;
	int uzunluk = 0;
	for (; tmp != NULL; tmp = tmp->next,uzunluk++);
	tmp = head;
	int i = 0;
	for (; i < uzunluk/2; i++)
	{
		//bastan istenilen dugumu bulma
		for (int j = 0; j < i; j++)
			tmp = tmp->next;
		//sondan istenilen dugumu bulma
		for (int k = 0; k < uzunluk - i-1; k++)
			tmp2 = tmp2->next;

		// deger degisimi yapimi
		int temp = tmp->data;
		tmp->data = tmp2->data;
		tmp2->data = temp;

		// tmpleri tekrar head yapma (sonraki notasyon icin lazimdir)
		tmp = head;
		tmp2 = head;
	}
}
int main() {

	struct node *list = createNode(1);
	SondanEkle(list, 2);
	SondanEkle(list,3);
	SondanEkle(list, 4);
	SondanEkle(list, 5);
	yazdir(list);

	degistir(list);
	yazdir(list);

	return 0;
}