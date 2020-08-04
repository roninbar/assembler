#define MAXNAMELEN 1000

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

//int gettoken(const char *input, Token *token)
//{
//}
	//switch (input) {
	//case ';'||' ':
		//token.type = COMMA;
		//comma(input);
		//break;
	//case '.':
		//token.TokenType = directive;
		//directive(input);
		//break;
	//case '#':
		//token.type = NUMBER;
			//number(input);
		//break;
	//case 'r':
		//if((input=getchar()>='1' && input<='9')

		//token.type = REGISTER;
			//register(input);
		//break;

	//int i = 0;
	//while (1) {
		//input++;


	//}
	//return i;


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
