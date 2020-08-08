#include <stdio.h>
#include <errno.h>
#include "gettoken.h"

int main(int argc, char *argv[]) {
	// for each input file (*.as)
	//   for each line in the file
	//     while (not <eol>)
	//       get the next token
	int i;
	for (i = 1; i < argc; i++)
	{
		FILE *pFile;
		char fileName[100];
		char line[1000];
		sprintf(fileName, "%s.as", argv[i]);
		pFile = fopen(fileName, "r");
		if (pFile == NULL) {
			exit(ENOENT);
		}
		else {
			Token token;
			while (fgets(line, 1000, pFile)) {
				int tokenLength;
				printf("( ");
				for (char *p = line; 0 < (tokenLength = gettoken(p, &token)); p += tokenLength) {
					printf("(%s \'%s\') ", token._typename, token.name);
				}
				printf(")\n");
			}
			fclose(pFile);
		}
	}
}

//char line[MAXLINELEN];
//int i = 0;
//int input = 0;
//while ((input = getchar()) != EOF) {
//	Token token;
//	i += gettoken(&line[i], &token);
//	switch (token.type) {
//	case DIRECTIVE:
//		directive(token.name);
//		break;
//	case LABEL:
//		label(token.name);
//		break;
//	case INSTRUCTION:
//	case REGISTER:
//	case NUMBER:
//	case COMMA:
//	}
//}