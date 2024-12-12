#include "queue.h"
#include <stdlib.h>
#include <string.h>

struct Queue* initQueue(char* data) {
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

	q->data = (char*)malloc(sizeof(char) * 26);
	memcpy(q->data, data, 26);

	q->start = -1;

	return q;
}

// Functionality requires a char be popped off the front of the queue, then immediately pushed onto the back.
// So this is only a queue in theory.
char popQueue(struct Queue* q) {
	q->start++;
	q->start %= 26;
	return q->data[q->start];
}
