#include <stdio.h>
#include <stdlib.h>

struct dugum {
	int veri;
	struct dugum *sonraki;
};
struct dugum* olustur(int _veri) {
	struct dugum*yeniDugum= (struct dugum*)malloc(sizeof(struct dugum));
	yeniDugum->veri = _veri;// parametre verisinin atanmasi
	return yeniDugum;
}
//----------------- Ekleme Islemleri---------------------------

void sondanEkle(struct dugum* head, int _veri) {
	struct dugum* yeniDugum = olustur(_veri);
	struct dugum* tmpNode=head;
	for (tmpNode = head; tmpNode->sonraki != head; tmpNode = tmpNode->sonraki);
	
	yeniDugum->sonraki = head;
	tmpNode->sonraki = yeniDugum;
	
}
void bastanEkle(struct dugum** head, int _veri) {
	struct dugum* yeniDugum = olustur(_veri);
	yeniDugum->sonraki = *head;

	struct dugum* tmp = *head;
	for (tmp = *head; tmp->sonraki != *head; tmp = tmp->sonraki);// son dugumu bulma islemi
	
	tmp->sonraki = yeniDugum;
	*head = yeniDugum;

}
void ekle(struct dugum* head, int deger,int _veri) {
	struct dugum* yeniDugum = olustur(_veri);
	struct dugum* tmp = head;
	for (; tmp->veri != deger; tmp = tmp->sonraki);
	yeniDugum->sonraki = tmp->sonraki;
	tmp->sonraki = yeniDugum;
}
void yazdir(struct dugum* head) {

	struct dugum* tmpNode = head;
	do {
		printf("%d\t", tmpNode->veri);
		tmpNode = tmpNode->sonraki;
	} while (tmpNode!= head);
	printf("\n");
}
// -----------------Silme islemleri----------------------

void bastanSil(struct dugum** head) {
	struct dugum* tmp = *head;
	struct dugum* tmp2 = *head;//son dugumu bulmak icin
	for (; tmp2->sonraki != *head; tmp2 = tmp2->sonraki);
	*head = (*head)->sonraki;
	tmp2->sonraki = *head;
	free(tmp);
}
void sondanSilme(struct dugum* head) {
	struct dugum* tmp = head;
	for (; tmp->sonraki->sonraki != head; tmp = tmp->sonraki);
	free(tmp->sonraki);
	tmp->sonraki = head;
}
void sil(struct dugum* head, int deger) {
	struct dugum* tmp = head;// degerden onceki dugumu bulmak icin
	for (; tmp->sonraki->veri != deger; tmp = tmp->sonraki);
	struct dugum* silinecek = tmp->sonraki;
	tmp->sonraki = tmp->sonraki->sonraki;
	free(silinecek);
}
int main() {
	struct dugum* dugum = olustur(4);
	dugum->sonraki = dugum;
	bastanEkle(&dugum,5);
	bastanEkle(&dugum,6);
	sondanEkle(dugum, 3);
	ekle(dugum, 3, 2);
	yazdir(dugum);
	bastanSil(&dugum);
	yazdir(dugum);
	sondanSilme(dugum);
	yazdir(dugum);
	sil(dugum, 4);
	yazdir(dugum);



	
	return 0;
}