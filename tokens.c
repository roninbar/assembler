#include <stdio.h>


void directive(const char *name) {
	printf("directive(\"%s\")", name);
}

void labeldef(const char *name) {
	printf("labeldef(\"%s\")", name);
}
void labelref(const char *name) {
	printf("labelref(\"%s\")", name);
}

void instruction(const char *name) {
	printf("instruction(\"%s\")", name);
}

void registerref (int n) {
	printf("register(%d)", n);
}

void number(int n) {
	printf("number(%d)", n);
}

void comma() {
	printf("comma()");
}

// label()
// instruction()
// register()
// comma()