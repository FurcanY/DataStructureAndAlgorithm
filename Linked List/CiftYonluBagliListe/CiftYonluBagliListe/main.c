#include <stdlib.h>
#include <stdio.h>

//--------- cift yonlu dugum yapisi -----------
struct dugum {
	int veri;
	struct dugum* onceki;
	struct dugum* sonraki;
};
//---------------- dugum olusturma metodu -----------
struct dugum* olustur(int _veri) {
	struct dugum* yeniDugum = (struct dugum*)malloc(sizeof(struct dugum));
	yeniDugum->veri = _veri;
	yeniDugum->onceki = NULL;
	yeniDugum->sonraki = NULL;
	return yeniDugum;
}
//------------- Listeyi Yazdirma Metodu -------------------
void yazdir(struct dugum* head) {
	struct dugum* tmp = head;
	while (tmp != NULL) {
		printf("%d \t", tmp->veri);
		tmp = tmp->sonraki;
	}
	printf("\n");
}

//----------- Ekleme islemleri ----------------
// ---------- Bastan Ekleme --------------
void bastanEkle(struct dugum** head, int _veri) {
	struct dugum* yeniDugum = olustur(_veri);
	yeniDugum->sonraki = *head;
	(*head)->onceki = yeniDugum;
	*head = yeniDugum;
}
// ------------ Sondan Ekleme -------------
void sondanEkle(struct dugum* head, int _veri) {
	struct dugum* yeniDugum = olustur(_veri);
	struct dugum* tmp = head;
	for (; tmp->sonraki != NULL; tmp = tmp->sonraki); //son dugumu bulma islemi
	tmp->sonraki = yeniDugum;
	yeniDugum->onceki = tmp;


}
// -------------- Deger Ile Ekleme ---------------
void Ekle(struct dugum* head,int deger, int _veri) {
	struct dugum* yeniDugum = olustur(_veri);
	struct dugum* tmp = head;
	for (; tmp->veri != deger; tmp = tmp->sonraki);// degerin bulundugu dugumu bulma
	tmp->sonraki->onceki = yeniDugum;
	yeniDugum->sonraki = tmp->sonraki;
	yeniDugum->onceki = tmp;
	tmp->sonraki = yeniDugum;
}

// ------------ Sirali Ekleme ---------------------

void SiraliEkle(struct dugum** head, int x) {
	struct dugum* yeniDugum = olustur(x);
	struct dugum* tmp = *head;
	while (tmp != NULL) {
		if (x > tmp->veri)
			tmp = tmp->sonraki;
		else
			break;
	}
	if (tmp == *head) {
		(*head)->onceki = yeniDugum;
		yeniDugum->sonraki = *head;
		*head = yeniDugum;
	}
	if (tmp == NULL) {
		tmp = *head;
		for (; tmp->sonraki != NULL; tmp = tmp->sonraki);//son dugumu bulma islemi
		tmp->sonraki = yeniDugum;
		yeniDugum->onceki = tmp;
	}
	else {
		tmp->onceki->sonraki = yeniDugum;
		yeniDugum->onceki = tmp->onceki;
		yeniDugum->sonraki = tmp;
		tmp->onceki = yeniDugum;
	}
	
}
//------------- Silme Islemleri -------------------

//----------- Bastan Silme ------------

void bastanSilme(struct dugum** head) {
	*head = (*head)->sonraki;
	free((*head)->onceki);
	(*head)->onceki - NULL;
}
// ---------- Sondan Silme -------------
void sondanSilme(struct dugum* head) {
	struct dugum* tmp = head;
	for (; tmp->sonraki->sonraki != NULL; tmp = tmp->sonraki);
	free(tmp->sonraki);
	tmp->sonraki = NULL;
}
// ------------- Deger Ile Silme --------------
void Silme(struct dugum* head, int deger) {
	struct dugum* tmp = head;
	for (; tmp->veri != deger; tmp = tmp->sonraki);
	tmp->onceki->sonraki = tmp->sonraki;
	tmp->sonraki->onceki = tmp->onceki;
	free(tmp);
}
// --------------- Cevrimsel Listeyi Tek Yonlu Yapma ------------------
void donustur(struct dugum* head) {
	struct dugum* tmp = head;
	for (; tmp->sonraki != NULL; tmp = tmp->sonraki);
	tmp->sonraki = head;
	head->onceki = tmp;
}





int main() {

	struct dugum *dugum = olustur(2);
	bastanEkle(&dugum, 1);
	yazdir(dugum);
	sondanEkle(dugum, 3);
	yazdir(dugum);
	Ekle(dugum, 2, 4);
	yazdir(dugum);
	bastanEkle(&dugum, 55);
	sondanEkle(dugum, 311);
	yazdir(dugum);
	bastanSilme(&dugum);
	yazdir(dugum);
	sondanSilme(dugum);
	yazdir(dugum);
	Silme(dugum, 2);
	yazdir(dugum);
	printf("-------------------\n");
	//------------ Sirali ekleme islemleri ---------------

	struct dugum* dugum1 = olustur(2);
	sondanEkle(dugum1, 3);
	sondanEkle(dugum1, 5);
	SiraliEkle(&dugum1, 1);
	yazdir(dugum1);
	SiraliEkle(&dugum1, 4);
	yazdir(dugum1);
	SiraliEkle(&dugum1, 6);
	yazdir(dugum1);







	return 0;
}