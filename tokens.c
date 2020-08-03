#include <stdio.h>

void directive(const char *kind) {
	printf("directive(\"%s\")", kind);
}

void number(int n) {
	printf("number(%d)", n);
}

// label()
// instruction()
// register()
// comma()