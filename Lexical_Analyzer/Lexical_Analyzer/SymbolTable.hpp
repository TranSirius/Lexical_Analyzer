#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>

enum FirstType {
	NONE1,
	IDENTIFIER,
	RESERVED_WORD
};

enum SecondType {
	NONE2,
	CHAR,
	UNSIGNED_CHAR,
	SIGNED_CHAR,
	INT,
	UNSIGNED_INT,
	SIGNED_INT,
	SHORT_INT,
	UNSIGNED_SHORT_INT,
	LONG_INT,
	SIGHNED_LONG_INT,
	UNSIGNED_LONG_INT,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE,
	WCHAR_T,

	AUTO,
//	DOUBLE,
//	INT,
	STRUCT,
	BREAK,
	ELSE,
	LONG,
	SWITCH,
	CASE,
	ENUM,
	REGISTER,
	TYPEDEF,
//	CHAR,
	EXTERN,
	RETURN,
	UNION,
	CONST,
//	FLOAT,
	SHORT,
	UNSIGNED,
	CONTINUE,
	FOR,
	SIGNED,
	VOID,
	DEFAULT,
	GOTO,
	SIZEOF,
	VOLATILE,
	DO,
	IF,
	STATIC,
	WHILE
};

typedef struct {
	FirstType firstType;
	SecondType secondType;
}attribute;

typedef std::unordered_map<std::string, attribute> Table;

class SymbolTable {
private:
	Table symbol_table;
public:
	SymbolTable();
	attribute toTable(std::string symbol_name);
	attribute fromTable(std::string symbol_name);
	void outputToDisk(std::string file_name);
};

