#include <stdlib.h>
#include <stdio.h>

/*
	4x^3 -3x^2 +10 gibi bir polinomu tek yonlu bagli liste ile temsil ediniz.

*/
struct polinom {
	int katsayi;
	int derece;
	struct polinom* sonraki;
};

struct polinom* olustur(int kSayi, int der) {
	struct polinom* yeniPolinom = (struct polinom*)malloc(sizeof(struct polinom));
	yeniPolinom->katsayi = kSayi;
	yeniPolinom->derece = der;
	yeniPolinom->sonraki = NULL;

	return yeniPolinom;
}
void polinomEkle(struct polinom* head, int kSayi, int der) {
	struct polinom* yeniPolinom = olustur(kSayi, der);
	struct polinom* tmp = head;
	for (; tmp->sonraki != NULL; tmp = tmp->sonraki);

	tmp->sonraki = yeniPolinom;
}

void yazdir(struct polinom* head) {
	struct polinom* tmp = head;
	
	while (tmp != NULL) {
		if (tmp->katsayi > 0 && tmp!=head)
			printf("+");
		printf("%dx^%d ", tmp->katsayi, tmp->derece);
		tmp = tmp->sonraki;
	}
}

int main() {
	struct polinom* polinom1 = olustur(4, 3);
	polinomEkle(polinom1, -3, 2);
	polinomEkle(polinom1, 10, 0);
	yazdir(polinom1);

	return 0;
}