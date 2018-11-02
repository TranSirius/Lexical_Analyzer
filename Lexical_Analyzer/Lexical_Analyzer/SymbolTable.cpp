#include "SymbolTable.hpp"

SymbolTable::SymbolTable()
{
	symbol_table.insert(Table::value_type("auto", { RESERVED_WORD, AUTO }));
	symbol_table.insert(Table::value_type("double", { RESERVED_WORD, DOUBLE }));
	symbol_table.insert(Table::value_type("int", { RESERVED_WORD, INT }));
	symbol_table.insert(Table::value_type("struct", { RESERVED_WORD, STRUCT }));
	symbol_table.insert(Table::value_type("break", { RESERVED_WORD, BREAK }));
	symbol_table.insert(Table::value_type("else", { RESERVED_WORD, ELSE }));
	symbol_table.insert(Table::value_type("long", { RESERVED_WORD, LONG }));
	symbol_table.insert(Table::value_type("switch", { RESERVED_WORD, SWITCH }));
	symbol_table.insert(Table::value_type("case", { RESERVED_WORD, CASE }));
	symbol_table.insert(Table::value_type("enum", { RESERVED_WORD, ENUM }));
	symbol_table.insert(Table::value_type("register", { RESERVED_WORD, REGISTER }));
	symbol_table.insert(Table::value_type("typedef", { RESERVED_WORD, TYPEDEF }));
	symbol_table.insert(Table::value_type("char", { RESERVED_WORD, CHAR }));
	symbol_table.insert(Table::value_type("extern", { RESERVED_WORD, EXTERN }));
	symbol_table.insert(Table::value_type("return", { RESERVED_WORD, RETURN }));
	symbol_table.insert(Table::value_type("union", { RESERVED_WORD, UNION }));
	symbol_table.insert(Table::value_type("const", { RESERVED_WORD, CONST }));
	symbol_table.insert(Table::value_type("float", { RESERVED_WORD, FLOAT }));
	symbol_table.insert(Table::value_type("short", { RESERVED_WORD, SHORT }));
	symbol_table.insert(Table::value_type("unsigned", { RESERVED_WORD, UNSIGNED }));
	symbol_table.insert(Table::value_type("continue", { RESERVED_WORD, CONTINUE }));
	symbol_table.insert(Table::value_type("for", { RESERVED_WORD, FOR }));
	symbol_table.insert(Table::value_type("signed", { RESERVED_WORD, SIGNED }));
	symbol_table.insert(Table::value_type("void", { RESERVED_WORD, VOID }));
	symbol_table.insert(Table::value_type("default", { RESERVED_WORD, DEFAULT }));
	symbol_table.insert(Table::value_type("goto", { RESERVED_WORD, GOTO }));
	symbol_table.insert(Table::value_type("sizeOf", { RESERVED_WORD, SIZEOF }));
	symbol_table.insert(Table::value_type("volatile", { RESERVED_WORD, VOLATILE }));
	symbol_table.insert(Table::value_type("do", { RESERVED_WORD, DO }));
	symbol_table.insert(Table::value_type("if", { RESERVED_WORD, IF }));
	symbol_table.insert(Table::value_type("static", { RESERVED_WORD, STATIC }));
	symbol_table.insert(Table::value_type("while", { RESERVED_WORD, WHILE }));
}

attribute SymbolTable::toTable(std::string symbol_name)
{
	attribute attr = { FirstType::NONE1, SecondType::NONE2 };
	try {
		attr = symbol_table.at(symbol_name);
	}
	catch (std::out_of_range err) {
		attr.firstType = IDENTIFIER;
		symbol_table.insert(Table::value_type(symbol_name, attr));
	}
	return attr;
}

attribute SymbolTable::fromTable(std::string symbol_name)
{
	attribute attr;
	attr = symbol_table.at(symbol_name);
	return attr;
}

std::string SymbolTable::tranlateSecondType(attribute attr)
{
	switch (attr.secondType)
	{
	case AUTO:
		return "AUTO";
	case INT:
		return "INT";
	case DOUBLE:
		return "DOUBLE";
	case STRUCT:
		return "STRUCT";
	case BREAK:
		return "BREAK";
	case ELSE:
		return "ELSE";
	case LONG:
		return "LONG";
	case SWITCH:
		return "SWITCH";
	case CASE:
		return "CASE";
	case ENUM:
		return "ENUM";
	case REGISTER:
		return "REGISTER";
	case TYPEDEF:
		return "TYPEDEF";
	case CHAR:
		return "CHAR";
	case EXTERN:
		return "EXTERN";
	case RETURN:
		return "RETURN";
	case UNION:
		return "UNION";
	case CONST:
		return "CONST";
	case FLOAT:
		return "FLOAT";
	case SHORT:
		return "SHORT";
	case UNSIGNED:
		return "UNSIGNED";
	case CONTINUE:
		return "CONTINUE";
	case FOR:
		return "FOR";
	case SIGNED:
		return "SIGNED";
	case VOID:
		return "VOID";
	case DEFAULT:
		return "DEFAULT";
	case GOTO:
		return "GOTO";
	case SIZEOF:
		return "SIZEOF";
	case VOLATILE:
		return "VOLATILE";
	case DO:
		return "DO";
	case IF:
		return "IF";
	case STATIC:
		return "STATIC";
	case WHILE:
		return "WHILE";
	default:
		break;
	}
	return std::string();
}

std::ofstream & operator<<(std::ofstream & out, FirstType first) {
	if (first == IDENTIFIER) {
		out << "IDENTIFIER";
	}
	else if (first == NONE1) {
		out << "NONE1";
	}
	else if (first == RESERVED_WORD) {
		out << "RESERVED WORD";
	}
	return out;
}

void SymbolTable::outputToDisk(std::string file_name = "SymbolTable.txt")
{
	std::ofstream file(file_name);
	for (auto it : symbol_table) {
		if (it.second.firstType == IDENTIFIER) {
			file << it.first << std::endl;
		}
	}
}

void SymbolTable::outputToDisk(void)
{
	std::ofstream file(stdout);
	for (auto it : symbol_table) {
		if (it.second.firstType == IDENTIFIER) {
			file << it.first << std::endl;
		}
	}
}