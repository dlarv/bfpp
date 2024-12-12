#include "limits.h"
#include "parser.h"
#include "../data_types/dict.h"
#include "../data_types/queue.h"
#include "../data_types/stack.h"
#include <stddef.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

char _varNames[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char _fnNames[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

struct Queue* varNames;
struct Queue* fnNames;
struct Stack* varPtrs;
struct Stack* fnPtrs;
struct Dict* vars;
struct Dict* fns;

char tape[255];
char head;

void initParser() {
	// Init function and variable names.
	varNames = initQueue(_varNames);
	fnNames = initQueue(_fnNames);

	// Init return ptr stacks.
	varPtrs = initStack(26);
	fnPtrs = initStack(26);

	// Init var/fn ptr dicts.
	vars = initDict(26);
	fns = initDict(26);

	head = 0;
}

char parse(char input[], size_t len, int debugMode) {
	int seekingEndLoop = FALSE;
	struct Stack loopStartPtrs = *initStack(255);

	int seekingEndFn = FALSE;

	for(size_t i = 0; i < len; i++) {
		char ch = input[i];
		if(ch <= 31) {
			continue;
		}

		// Loop logic.
		// First encounter of new [
		// In loop, executing normally
		// In loop, skipping
		// Encounter ], val == 0
		// Encounter ], val != 0
		if(seekingEndLoop) {
			if(ch == ']') {
				popStack(&loopStartPtrs);
				seekingEndLoop = FALSE;
			}
			continue;
		}
		if(seekingEndFn) {
			if(ch == ')') {
				seekingEndFn = FALSE;
			}
			continue;
		}

		int index;
		char name;
		char val = tape[head];

		switch(ch) {
			case '+':
				tape[head] = getNextVal(val, 1);
				break;
			case '-':
				tape[head] = getPrevVal(val, 1);
				break;
			case '>':
				head = getNextVal(head, 1);
				break;
			case '<':
				head = getPrevVal(head, 1);
				break;
			case '.':
				printf("Output: %d\n", val);
				break;
			case ',':
				break;
			case '[':
				pushStack(&loopStartPtrs, i);

				if(val == 0) {
					seekingEndLoop = TRUE;
				}
				break;
			case ']':
				index = popStack(&loopStartPtrs);
				if(val != 0) {
					i = index - 1;
				}
				break;
			case '=': 
				name = popQueue(varNames);
				insert(vars, name, head);
				break;
			case '(':
				name = popQueue(fnNames);
				insert(fns, name, i);
				seekingEndFn = TRUE;
				break;
			case ')':
				i = popStack(fnPtrs);
				break;
			case '\'':
				head = popStack(varPtrs);
				break;
			default:
				if(ch >= 'a' && ch <= 'z') {
					pushStack(varPtrs, head);
					head = get(vars, ch); 
				} 
				else if(ch >= 'A' && ch <= 'Z') {
					pushStack(fnPtrs, i);
					i = get(fns, ch);
				}


			
		}
		debug(ch, name, debugMode || ch == '#');
	}
	return '.';
}

void endParser() {
	free(varNames);
	free(fnNames);
	free(varPtrs);
	free(fnPtrs);
	free(vars);
	free(fns);
}

void debug(char ch, char name, int debugMode) {
	if(!debugMode) {
		return;
	}

	printf("\nChar: %c\n", ch);

	if(ch == '(') {
		printf("Created new fn with id = %c\n", name);
	} 
	else if(ch == '=') {
		printf("Created new var with id = %c\n", name);
	}
	else if(ch >= 'A' && ch <= 'Z') {
		printf("Calling fn %c. Moving function ptr to %d\n", ch, get(fns, ch));
	}
	else if(ch >= 'a' && ch <= 'z') {
		printf("Goto var %c. Moving mem ptr to %d\n", ch, get(vars, ch));
	}

	for(int i = -2; i <= 2; i++) {
		printf("| %-3d ", tape[getNextVal(head, i)]);
	}
	printf("|\n");

	for(int i = -2; i <= 2; i++) {
		printf("|%-3d", getNextVal(head, i));
		if(i == 0) {
			printf("^ ");
		} else {
			printf("  ");
		}
	}
	printf("|\n");
	char* buffer[255];
	size_t len = 255;

	printf("Press Enter to continue...");
	getline(buffer, &len, stdin);
}

char getNextVal(char head, int amt) {
	if(head == CHAR_MAX) {
		head = CHAR_MIN + amt;
	} else {
		head += amt;
	}
	return head;
}
char getPrevVal(char head, int amt) {
	if(head == CHAR_MIN) {
		head = CHAR_MAX + amt;
	} else {
		head -= amt;
	}
	return head;
}
