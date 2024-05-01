#include <stdio.h>
#include <stdlib.h>

/*
	bir N basamakli bir sayi girilsin.
	Her basamaktaki degerleri bir dugum olarak liste olusturan metod olusturun
	Örneðin, 12345 girerseniz listede 1, 2, 3, 4, 5 deðerlerine sahip düðümleri
	içeren 5 düðüm olacaktýr.
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
void bastanEkle(struct node** head, int data) {
	struct node* newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;

}
void yazdir(struct node* d1) {

	while (d1 != NULL) {
		printf("%d\t", d1->data);
		d1 = d1->next;
	}
	printf("\n");
}
void metot(struct node** head, int sayi) {
	
	*head = createNode(sayi % 10);
	sayi = sayi / 10;
	while (sayi !=0) {
		bastanEkle(&*head, sayi % 10);
		sayi = sayi / 10;
		
	}
}
int main() {
	int sayi = 12345;
	struct node* list = NULL;
	metot(&list, sayi);
	yazdir(list);
	return 0;
}