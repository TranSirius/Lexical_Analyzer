#include "Automata.hpp"

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

void Automata::returnComment()
{
	backward();
	std::string tmp = buffer_pairs.Output();
	state = 0;
	warning = 0;
	comment_count++;
}

void Automata::returnPunc()
{
	backward();
	std::string tmp = buffer_pairs.Output();
	output_file << "PUNCTUATION\t\t" << tmp << std::endl;
	state = 0;
	warning = 0;
	punctuation_count++;
}