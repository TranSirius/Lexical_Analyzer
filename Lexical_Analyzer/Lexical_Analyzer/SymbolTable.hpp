#pragma once
#include <hash_map>

enum _type {
	CHAR,
	UNSIGHED_CHAR,
	SIGNED_CHAR,
	INT,
	UNSIGHEND_INT,
	SIGHED_INT,
	SHORT_INT,
	UNSIGNED_SHORT_INT,
	LONG_INT,
	SIGHNED_LONG_INT,
	UNSIGNED_LONG_INT,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE,
	WCHAR_T,

	RESERVED_WORD
};

typedef struct _attribute {
	
}attribute;

class SymbolTable {
private:
	std::hash_map<std::string, attribute> symbol_table;
public:
};