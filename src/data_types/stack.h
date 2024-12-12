
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

struct Stack {
	int maxSize;
	int top;
	char* data;
};

struct Stack* initStack(int size);
int pushStack(struct Stack* stack, char val);
char popStack(struct Stack* stack);

#endif
