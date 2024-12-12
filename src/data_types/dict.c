#include <stdlib.h>
#include "dict.h"

struct Dict* initDict(int size) {
	struct Dict* d = (struct Dict*)malloc(sizeof(struct Dict));

	d->data = (char*)malloc(sizeof(char) * size);

	return d;
}

// Insert val into dict.
// Key should be an alphabetical char.
// Returns -1 if key is not valid
// otherwise, returns 0.
char insert(struct Dict* dict, char key, char val) {
	// If key is A, it will be inserted into the 0th position, etc... 
	int index;
	if(key >= 'A' && key <= 'Z') {
		index = key - 'A';
	} 
	else if(key >= 'a' && key <= 'z') {
		index = key - 'a';
	} 
	else {
		return -1;
	}

	dict->data[index] = val;
	return 0;
}

// Returns dict[key]
// Returns -1 if key is not a valid alphabetical character.
char get(struct Dict* dict, char key) {
	// If key is A, it will be inserted into the 0th position, etc... 
	int index;
	if(key >= 'A' && key <= 'Z') {
		index = key - 'A';
	} 
	else if(key >= 'a' && key <= 'z') {
		index = key - 'a';
	} 
	else {
		return -1;
	}
	return dict->data[index];
}

