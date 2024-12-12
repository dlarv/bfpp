#include <stdio.h>
#include <string.h>
#include "parser/parser.h"

int runTests() {
	printf("Beginning testing...\n");

	initParser();
	printf("TODO\n");

	endParser();
	return 0;
}

int main(int argc, char* argv[]) {
	int debugMode = 0;
	if(argc > 1) {
		if(!strcmp(argv[1], "-d")) {
			debugMode = 1;
		}
		else if(!strcmp(argv[1], "-t")) {
			return runTests();
		}
	}

	initParser();

	char* buffer[255];
	size_t len = 255;

	printf("Enter bf code: ");
	getline(buffer, &len, stdin);
	printf("\n...\n");


	parse(*buffer, len, debugMode);


	endParser();
}

