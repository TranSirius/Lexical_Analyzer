#include "Automata.hpp"

void Automata::state5Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] exponent has no digits" << std::endl;
	state = 0;
}

void Automata::state6Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] plus or minus has no digits" << std::endl;
	state = 0;
}

void Automata::state8Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in octal constant" << std::endl;
	state = 0;
}

void Automata::state9Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in octal constant" << std::endl;
	state = 0;
}

void Automata::state10Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] Empty dexical number" << std::endl;
	state = 0;
}

void Automata::state11Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in hex constant" << std::endl;
	state = 0;
}

void Automata::state15Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] [Error] P exponent has no digits" << std::endl;
	state = 0;
}

void Automata::state16Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] plus or minus has no digits" << std::endl;
	state = 0;
}

void Automata::state105Warning()
{
	error_file << row_ptr << ":" << lexeme_ptr << " [Warning] unknow sequences detected" << std::endl;
}

void Automata::state522Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] punctuation error an extra . has been detected" << std::endl;
	state = 0;
}