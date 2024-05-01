#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <math.h>



// kuyruk olusturma fonskiyonu 
struct Queue* createQueue(int _capacity) {
	struct Queue* yeni = (struct Queue*)malloc(sizeof(struct Queue));
	if (yeni) {
		yeni->capacity = _capacity;
		yeni->rear = _capacity - 1;
		yeni->front = 0;
		yeni->size = 0;
		yeni->array = (int*)malloc(sizeof(int) * _capacity);
	}

	return yeni;
}

// kuyruk dolu mu kontrolu
int isFull(struct Queue* yeni) {
	return (yeni->size == yeni->capacity);
}
// kuyruk bos mu kontrolu
int isEmpty(struct Queue* yeni) {
	return (yeni->size == 0);
}

void Enqueue(struct Queue* yeni, int x) /* sondan eleman ekleme */
{
	if (isFull(yeni))
		return;
	yeni->rear = (yeni->rear + 1) % yeni->capacity; // cevrimsel
	yeni->array[yeni->rear] = x;//veri atama
	yeni->size = yeni->size + 1;
}
int Dequeue(struct Queue* yeni) {   /* bastan eleman silme */
	if (isEmpty(yeni))
		return INT_MIN;

	int item = yeni->array[yeni->front];
	yeni->front = (yeni->front + 1) % yeni->capacity; // cevrimsel
	yeni->size = yeni->size - 1;

	return item;
}

int Front(struct Queue* yeni)/* eleman silmeden bastan elemaný alma islemi*/
{
	if (isEmpty(yeni))
		return INT_MIN;
	return yeni->array[yeni->front];
}
int Rear(struct Queue* yeni) /* eleman eklemeden sondan eleman alma islemi */
{
	if (isEmpty(yeni))
		return INT_MIN;
	return yeni->array[yeni->rear];
}
void goster(struct Queue* yeni) {
	int indis = yeni->front;
	int boyut = yeni->size;
	while (boyut != 0) {
		printf("%d\t", yeni->array[indis]);
		indis = (indis + 1) % yeni->capacity;
		boyut--;
	}
	printf("\n");
}

// kuyruktaki eleman sayisini bulan fonksiyon
int elemanSayisi(struct Queue* queue) {
	int indis = queue->front;
	int boyut = queue->size;
	int sonuc = 0;
	while (boyut != 0) {
		indis = (indis + 1) % queue->capacity;
		sonuc++;
		boyut--;
	}
	return sonuc;
}
int elemanSayisi2(struct Queue* queue) {
	return abs(queue->rear + 1 - queue->front);
}

void tersCevir(struct Queue* kuyruk) {
	int* array = (int*)malloc(sizeof(int) * kuyruk->capacity);
	int a = -1;
	while (kuyruk->size!=0)
		array[++a] = Dequeue(kuyruk);
	while (a != -1)
		Enqueue(kuyruk, array[a--]);
}

int maxBul(struct Queue* queue) {
	int a = queue->front;
	int max = queue->array[a++];
	while (a <= queue->rear) {
		if (queue->array[a] > max)
			max = queue->array[a];
		++a;
	}
	return max;
}