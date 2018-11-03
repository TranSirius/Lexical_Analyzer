#include "Automata.hpp"

/*
	funtion:	返回十进制小数
*/

void Automata::returnFloat()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	output_file << "FLOAT\t\t\t" << tmp << std::endl;
	warning = 0;
	float_count++;
}

/*
	funtion:	返回十进制整数
*/

void Automata::returnInt()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	output_file << "INTERGER\t\t" << tmp << std::endl;
	warning = 0;
	int_count++;
}

/*
	funtion:	返回八进制整数
*/

void Automata::returnOctInt()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	output_file << "OCTAL_INT\t\t" << tmp << std::endl;
	warning = 0;
	octal_int_count++;
}

/*
	funtion:	返回十六进制小数
*/

void Automata::returnHexFloat()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	output_file << "HEX_FLOAT\t\t" << tmp << std::endl;
	warning = 0;
	hex_float_count++;
}

/*
	funtion:	返回十六进制整数
*/

void Automata::returnHexInt()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	output_file << "HEX_INTERGER\t\t" << tmp << std::endl;
	warning = 0;
	hex_int_count++;
}

/*
	funtion:	返回字符常量
*/

void Automata::returnCharacterConstant()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	tmp.replace(tmp.find('\''), 1, "");
	tmp.replace(tmp.find('\''), 1, "");
	output_file << "CHARACTER_CONSTANT\t" << tmp << std::endl;
	warning = 0;
	char_count++;
}

/*
	funtion:	返回字符串常量
*/

void Automata::returnString()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	tmp.replace(tmp.find('\"'), 1, "");
	tmp.replace(tmp.size() - 1, 1, "");
	output_file << "CHARACTER_CONSTANT\t" << tmp << std::endl;
	warning = 0;
	string_count++;
}

/*
	funtion:	返回标识符和关键字
*/

void Automata::returnIdentifier()
{
	lexeme_count++;
	lexeme_ptr++;
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	attribute attr;
	attr = symbol_table.toTable(tmp);
	if (attr.firstType == RESERVED_WORD) {
		output_file << "RESERVED WORDS\t\t" << symbol_table.tranlateSecondType(attr) << std::endl;
	}
	else {
		output_file << "IDENTIFIER\t\t" << tmp << std::endl;
		identifier_count++;
	}
	warning = 0;
}

/*
	funtion:	返回注释
*/

void Automata::returnComment()
{
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	warning = 0;
	comment_count++;
}

/*
	funtion:	返回标点符号
*/

void Automata::returnPunc()
{
	backward();
	std::string tmp = buffer_pairs.Output();
	output_file << "PUNCTUATION\t\t" << tmp << std::endl;
	state = 0;
	warning = 0;
	punctuation_count++;
}