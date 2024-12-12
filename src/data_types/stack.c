#include "stack.h"

struct Stack* initStack(int size) {
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));

	s->top = -1;
	s->maxSize = size;
	s->data = (char*)malloc(sizeof(char) * size);

	return s;
}
int pushStack(struct Stack* stack, char val) {
	if(stack->top >= stack->maxSize) {
		return 1;
	}
	stack->data[++stack->top] = val;

	return 0;
}

char popStack(struct Stack* stack) {
	if(stack->top == -1) {
		return 0;
	}
	char output = stack->data[stack->top];

	stack->data[stack->top] = 0x0;
	stack->top--;
	return output;
}
