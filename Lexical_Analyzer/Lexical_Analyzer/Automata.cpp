#include "Automata.hpp"

void Automata::get_char()
{
	ch = buffer_pairs.Forward();
	if (ch == '\n') {
		row_ptr++;
		lexeme_ptr = 0;
	}
}

void Automata::get_nbc()
{
	while (ch == '\n' || ch == ' ' || ch == '\t') {
		get_char();
	}
	buffer_pairs.Output();
}

void Automata::get_ch_type()
{
	if (ch >= '0' && ch <= '9') {
		ch_type = digits;
	}
	else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		ch_type = letter;
	}
	else {
		ch_type = others;
	}
}

void Automata::generate_error(ERROR_TYPE error_type)
{
	std::cerr << "Error detected at" << row_ptr << " : " << lexeme_ptr << std::endl;
}

bool Automata::is_octal()
{
	if (ch >= '0' && ch <= '7') {
		return true;
	}
	else {
		return false;
	}
}

bool Automata::is_hex()
{
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	else if (ch >= 'a' && ch <= 'f') {
		return true;
	}
	else if (ch >= 'A' && ch <= 'F') {
		return true;
	}
	else {
		return false;
	}
}

void Automata::run(void)
{
	state = 0;
	do {

	} while (ch != '\0');
}
