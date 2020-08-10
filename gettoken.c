#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gettoken.h"

#define BOOL int
#define FALSE (0)
#define TRUE (1)

#define arraylen(array) (sizeof(array) / sizeof(array[0]))
#define settokentype(ptok, typ) ((ptok)->type = (typ), strcpy((ptok)->_typename, #typ))

static const char *instructions[] = { "mov", "cmp", "add", "sub", "lea", "clr", "not", "inc", "dec", "jmp", "bne", "jsr", "red", "prn", "rts", "stop" };

static BOOL isinstruction(const char *word) {
	for (int i = 0; i < arraylen(instructions); i++) {
		if (0 == strcmp(instructions[i], word)) {
			return TRUE;
		}
	}
	return FALSE;
}

int gettoken(const char *input, Token *token)
{
	int nchars;

	if (0 < sscanf(input, " %[,]%n", token->string, &nchars)) {
		settokentype(token, COMMA);
		return nchars;
	} else if (0 < sscanf(input, " .%s%n", token->string, &nchars)) {
		settokentype(token, DIRECTIVE);
		return nchars;
	} else if (0 < sscanf(input, " #%d%n", &token->number, &nchars)) {
		settokentype(token, IMMEDIATE);
		return nchars;
	} else if (0 < sscanf(input, " &%[A-Za-z0-9]%n", token->string, &nchars)) {
		settokentype(token, RELATIVE);
		return nchars;
	} else if (0 < sscanf(input, " r%d%n", &token->number, &nchars)) {
		settokentype(token, REGISTER);
		return nchars;
	} else if (0 < sscanf(input, " %d%n", &token->number, &nchars)) {
		settokentype(token, NUMBER);
		return nchars;
	} else if (0 < sscanf(input, " \"%s%n", token->string, &nchars)) {
		strtok(token->string, "\"");
		settokentype(token, STRING);
		return nchars;
	} else if (0 < sscanf(input, " %31[A-Za-z0-9:]%n", token->string, &nchars)) {
		char first = token->string[0], last = token->string[strlen(token->string) - 1];
		if (isinstruction(token->string)) {
			settokentype(token, INSTRUCTION);
		} else if (last == ':') {
			strtok(token->string, ":");
			settokentype(token, LABELDEF);
		} else {
			settokentype(token, LABELREF);
		}
		return nchars;
	} else {
		settokentype(token, UNIDENTIFIED);
		return 0;
	}
}
