#pragma once

#define MAXNAMELEN 31
#define MAXTYPELEN 20

typedef enum {
	UNIDENTIFIED, // development only!!!
	DIRECTIVE,
	LABELDEF,
	LABELREF,
	INSTRUCTION,
	REGISTER,
	NUMBER,
	COMMA
} TokenType;

#define settokentype(ptok, typ) ((ptok)->type = (typ), strcpy((ptok)->_typename, #typ))

typedef struct {
	TokenType type;
	char _typename[MAXTYPELEN];
	union
	{
		char name[MAXNAMELEN + 1];
		int value;
		int regnum;
	};
} Token;

int gettoken(const char *input, Token *token);