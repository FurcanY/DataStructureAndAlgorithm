#include <stdio.h>
#include <stdlib.h>

//dugum icerisimnde tekrarlananlarý silen program yazýn
// tekrarsýz bir þelkini yeni liste olarak oluþturdum
struct list {
	int data;
	struct list* next;
};
struct list* createNode(int data) {
	struct list* newNode = (struct list*)malloc(sizeof(struct list));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void SondanEkle(struct list* head, int data) {
	struct list* newNode = createNode(data);
	struct list* tmp = head;
	for (; tmp->next != NULL; tmp = tmp->next);
	tmp->next = newNode;
	
}
void yazdir(struct list* d1) {

	while (d1 != NULL) {
		printf("%d", d1->data);
		d1 = d1->next;
	}
	printf("\n");
}
void tekrarlananlariSil(struct list* head, struct list* yeniList) {
	struct list* tmp = head;
	struct list* tmp2 = yeniList;
	int flag = 0;
	for (; tmp != NULL; tmp = tmp->next) {
		
		for (tmp2=yeniList; tmp2 != NULL; tmp2 = tmp2->next) {
			if (tmp2->data == tmp->data) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			SondanEkle(yeniList, tmp->data);
		}
		flag = 0;

	}

}

int main() {
	struct list* List = createNode(1);
	SondanEkle(List, 1);
	SondanEkle(List, 3);
	SondanEkle(List, 2);
	SondanEkle(List, 1);
	SondanEkle(List, 1);
	SondanEkle(List, 5);
	SondanEkle(List, 9);
	SondanEkle(List, 9);
	SondanEkle(List, 2);
	struct list* yeniList = createNode(List->data);
	yazdir(List);
	tekrarlananlariSil(List, yeniList);
	yazdir(yeniList);


	return 0;
}
