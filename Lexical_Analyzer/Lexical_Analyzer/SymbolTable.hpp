#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>

//����ö�����ͣ�ȷ���ڷ��ű��е���Ŀ����������
enum FirstType {
	NONE1,						//Ԥ������Ϊ��������Ϳ��ж���
	IDENTIFIER,					//��ʶ������
	RESERVED_WORD,				//������(�ؼ���)
	OPERATOR					//�����������ʵ��ʵ����û������
};

//��������������ͣ��ͱ�ʶ���ľ������͡��ⲿ���ڴʷ�����������û�����ϣ����ں������﷨��������������л�����
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

//������ű��У�ÿ����Ŀ��������Ϣ�Ľṹ

typedef struct {
	FirstType firstType;
	SecondType secondType;
}attribute;

//������ű�Ĺ�ϣ���ݽṹ���ù�ϣ���key�Ƿ����������磬�ؼ���"int"��key�����ַ���"int"������entry���о�������

typedef std::unordered_map<std::string, attribute> Table;

class SymbolTable {
private:
	Table symbol_table;
public:
	SymbolTable();											//���캯��
	attribute toTable(std::string symbol_name);				//�����ű��д�������
	attribute fromTable(std::string symbol_name);			//�ӷ��ű���key��һ�����ݵ�����
	std::string tranlateSecondType(attribute attr);			//ת�������������ݵ�����ת���ɿ���������ַ���
	void outputToDisk(std::string file_name);				//��������������ű��ӡ���ļ�
	void outputToDisk(void);
};

