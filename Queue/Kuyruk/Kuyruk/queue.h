#ifndef QUEUE_H
#define QUEUE_H

// soyut veri yapilari ve prototip fonksiyonlar
struct Queue {
	int rear, front, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(int _capacity);

int isFull(struct Queue* yeni);

int isEmpty(struct Queue* yeni);

void Enqueue(struct Queue* yeni, int x);

int Dequeue(struct Queue* yeni);

int Front(struct Queue* yeni);

int Rear(struct Queue* yeni);

void goster(struct Queue* yeni);

int elemanSayisi(struct Queue* queue);

int elemanSayisi2(struct Queue* queue);

void tersCevir(struct Queue* kuyruk);

int maxBul(struct Queue* queue);


#endif // !QUEUE_H
