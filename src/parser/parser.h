
#include <stddef.h>
#ifndef PARSER_H

void initParser();
char parse(char* ch, size_t len, int debugMode);
void endParser();
void debug(char ch, char name, int debugMode);
char getNextVal(char head, int amt);
char getPrevVal(char head, int amt);

#endif // !PARSER_H
