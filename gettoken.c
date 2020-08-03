#define MAXNAMELEN

typedef enum {
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

int gettoken(const char* input, Token* token);

// char line[MAXLINELEN];
// int i = 0;
// while () {
//     Token token;
//     i += gettoken(&line[i], &token);
//     switch (token.type) {
//     case DIRECTIVE:
//         directive(token.name);
//         break;
//     case LABEL:
//         label(token.name);
//         break;
//     case INSTRUCTION:
//     case REGISTER:
//     case NUMBER:
//     case COMMA:
//     }
// }
