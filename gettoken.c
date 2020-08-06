#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gettoken.h"

int gettoken(const char *input, Token *token)
{
	int full;
	sscanf(input, "%s%n", token->name,&full);
	return full;//strlen(token->name)
}
