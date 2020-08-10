#pragma once

typedef enum {
	ATTR_CODE,
	ATTR_DATA,
	ATTR_ENTRY,
	ATTR_EXTERNAL
} SymbolAttributes;

void symbolInsert(const char *name, int value, SymbolAttributes attr);

void symbolLookup(const char *name);