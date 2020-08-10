#include "symbol.h"

void symbolInsert(const char *name, int value, SymbolAttributes attr)
{
	struct Node *temp= (Node*) malloc(sizeof(Node));
	if (!temp) {
		printf("the memory is full");
		exit(0);
	}
	temp->name = name;
	temp->value = value;
	temp->SymbolAttributes = attr;
	temp->link=NULL;
	if (!head)
		head = temp;
	else {
		struct Node *current = head;
		while (current->link)
			current = current->link;
		temp = current->link;
	}


}

void symbolUpdate(const char *name, int value, SymbolAttributes attr)
{
}

void symbolLookup(const char *name, int *value, SymbolAttributes *attr)
{
}
