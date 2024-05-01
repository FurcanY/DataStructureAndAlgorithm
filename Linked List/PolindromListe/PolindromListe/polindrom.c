#include <stdio.h>
#include <stdlib.h>

/*
	Tek Yonlu listenin polindrom olup olmadigini kontrol eden kodu yaziniz.
*/
struct polindrom {
	int veri;
	struct polindrom* sonraki;

};

struct polindrom* olustur(int x) {
	struct polindrom* yeni = (struct polindrom*)malloc(sizeof(struct polindrom));
	yeni->veri = x;
	yeni->sonraki = NULL;
	return yeni;
}
int polindromMu(struct polindrom** head) {
	struct polindrom* tmp = *head;
	for (; tmp->sonraki->sonraki != NULL; tmp = tmp->sonraki);
	if ((*head)->sonraki == NULL) 
		return 1;
	else {
		free(tmp->sonraki);
		tmp ->sonraki = NULL;

	}
	if (*head == tmp) {
		return polindromMu(&(*head));
	}
	return 0;
	   
}

int main()
{
	struct polindrom *pld1 = olustur(1);
	struct polindrom* pld2 = olustur(2);
	struct polindrom* pld3 = olustur(2);
	struct polindrom* pld4 = olustur(1);
	pld1->sonraki = pld2;
	pld2->sonraki = pld3;
	pld3->sonraki = pld4;
	if (polindromMu(&pld1)) {
		printf("Sayi Polindrom\n");
	}
	else {
		printf("Sayi Polindrom Degil\n");

	}
	return 0;
}