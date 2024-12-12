#ifndef DICT_H
#define DICT_H

struct Dict {
	char* data;
};

struct Dict* initDict(int size);
char insert(struct Dict* dict, char key, char val);
char get(struct Dict* dict, char key);

#endif
