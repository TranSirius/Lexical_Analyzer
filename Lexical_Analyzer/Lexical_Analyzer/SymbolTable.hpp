#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>

//定义枚举类型，确定在符号表中的项目是哪种类型
enum FirstType {
	NONE1,						//预留，作为后面空填充和空判断用
	IDENTIFIER,					//标识符类型
	RESERVED_WORD,				//保留字(关键字)
	OPERATOR					//运算符，但在实际实现中没有用上
};

//定义运算符的类型，和标识符的具体类型。这部分在词法分析程序中没有用上，但在后续的语法分析、语义分析中会用上
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
	WHILE,
	DEFINE
};

//定义符号表中，每个项目的属性信息的结构

typedef struct {
	FirstType firstType;
	SecondType secondType;
}attribute;

//定义符号表的哈希数据结构，该哈希表的key是符号名，例如，关键字"int"的key就是字符串"int"，它的entry中有具体属性

typedef std::unordered_map<std::string, attribute> Table;

class SymbolTable {
private:
	Table symbol_table;
public:
	SymbolTable();											//构造函数
	attribute toTable(std::string symbol_name);				//往符号表中存入数据
	attribute fromTable(std::string symbol_name);			//从符号表用key查一个数据的属性
	std::string tranlateSecondType(attribute attr);			//转换函数，将数据的属性转换成可以输出的字符串
	void outputToDisk(std::string file_name);				//输出函数，将符号表打印到文件
	void outputToDisk(void);
};

