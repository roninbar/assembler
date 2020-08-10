#pragma once

#define MAXSTRINGLEN 80
#define MAXTYPELEN 20

typedef enum {
	UNIDENTIFIED, // development only!!!
	DIRECTIVE,
	LABELDEF,
	LABELREF,
	INSTRUCTION,
	REGISTER,
	IMMEDIATE,
	RELATIVE,
	NUMBER,
	STRING,
	COMMA,
} TokenType;

typedef struct {
	TokenType type;
	char _typename[MAXTYPELEN];
	union
	{
		char string[MAXSTRINGLEN + 1];
		int number;
	};
} Token;

int gettoken(const char *input, Token *token);
