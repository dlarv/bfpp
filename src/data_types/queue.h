#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
	int start;
	char* data;
};

struct Queue* initQueue(char* data);
char popQueue(struct Queue* q);
#endif
