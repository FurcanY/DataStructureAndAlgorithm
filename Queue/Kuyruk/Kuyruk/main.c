#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int x;

void recursive(struct Queue* yeni, struct Queue* yeni2) {
	if (isEmpty(yeni))
		return;
	x = Dequeue(yeni);
	recursive(yeni, yeni2);
	Enqueue(yeni2, x);
}

int main() {

	struct Queue* queue = createQueue(1000);
	Enqueue(queue, 10);
	Enqueue(queue, 20);
	Enqueue(queue, 30);
	Enqueue(queue, 40);
	struct Queue* yeni2 = createQueue(1000);
	recursive(queue, yeni2);
	goster(yeni2);


	return 0;
}