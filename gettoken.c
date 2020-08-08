#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gettoken.h"

int gettoken(const char *input, Token *token)
{
	int nchars, filled;
	settokentype(token, UNIDENTIFIED);
	filled = sscanf(input, " %[^ \t\n,]%n", token->name, &nchars);
	return filled ? nchars : 0;
}
