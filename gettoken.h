#pragma once

#define MAXNAMELEN 1000

typedef enum {
	_ANYWORD, // development only!!!
	DIRECTIVE,
	LABELDEF,
	LABELREF,
	INSTRUCTION,
	REGISTER,
	NUMBER,
	COMMA
} TokenType;

typedef struct {
	TokenType type;
	union
	{
		char name[MAXNAMELEN];
		int value;
		int regnum;
	};
} Token;

int gettoken(const char *input, Token *token);