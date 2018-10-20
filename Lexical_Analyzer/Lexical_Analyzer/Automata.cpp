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
		buffer_pairs.Output();
		get_char();
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

bool Automata::is_digit()
{
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	else {
		return false;
	}
}

bool Automata::is_letter()
{
	if (ch >= 'a' && ch <= 'z') {
		return true;
	}
	else if (ch >= 'A' && ch <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

bool Automata::is_whitespace()
{
	if (ch == '\t' || ch == '\n' || ch == '\t') {
		return true;
	}
	else {
		return false;
	}
}

bool Automata::is_float_suffix()
{
	if (ch == 'f' || ch == 'l' || ch == 'F' || ch == 'L') {
		return true;
	}
	else {
		return false;
	}
}

bool Automata::is_except()
{
	if (ch == '\'' || ch == '\\' || ch == '\n') {
		return true;
	}
	else {
		return false;
	}
}

bool Automata::is_escape()
{
	if (
		ch == '\'' ||
		ch == '\"' ||
		ch == '?' ||
		ch == 'a' ||
		ch == 'b' ||
		ch == 'f' ||
		ch == 'n' ||
		ch == 'r' ||
		ch == 't' ||
		ch == 'v'
		)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Automata::is_nonedigit()
{
	if (ch == '_') {
		return true;
	}
	else if (ch >= 'a' && ch <= 'z') {
		return true;
	}
	else if (ch >= 'A' && ch <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

void Automata::returnFloat()
{
}

void Automata::returnInt()
{
}

void Automata::returnOctInt()
{
}

void Automata::returnHexFloat()
{
}

void Automata::returnHexInt()
{
}

void Automata::run(void)
{
	state = 0;
	do {
		get_char();
		switch (state) {
		case 0:

			get_nbc();

			if (ch == '.') {
				state = 1;
			}
			else if (ch == '0') {
				state = 8;
			}
			else if (ch >= '1' && ch <= '9') {
				state = 2;
			}
			else if (ch == '\0') {
				break;
			}

			else if (ch == '\'') {
				state = 101;
			}
			else if (ch == '\"') {
				state = 104;
			}
			else if (ch == 'L') {
				state = 102;
			}
			else if (ch == 'l') {
				state = 103;
			}
			else if (is_nonedigit()) {
				state = 201;
			}
			else if (ch == '/') {
				state = 301;
			}

			else {
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 0 error\n";
				state = 0;
			}

			break;
		case 1:

			if (is_digit()) {
				state = 3;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 1 error\n";
				state = 0;
			}

			break;
		case 2:

			if (is_digit()) {
				state = 2;
			}
			else if (ch == 'E' || ch == 'e') {
				state = 5;
			}
			else if (ch == '.') {
				state = 4;
			}
			else if (ch == 'u' || ch == 'U') {
				state = 19;
			}
			else if (ch == 'l') {
				state = 20;
			}
			else if (ch == 'L') {
				state = 21;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Integer\n";
			}

			break;
		case 3:

			if (is_digit()) {
				state = 3;
			}
			else if (ch == 'E' || ch == 'e') {
				state = 5;
			}
			else if (is_float_suffix()) {
				state = 30;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Float\n";
			}

			break;
		case 4:

			if (is_digit()) {
				state = 4;
			}
			else if (ch == 'E' || ch == 'e') {
				state = 5;
			}
			else if (is_float_suffix()) {
				state = 30;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Float\n";
			}

			break;
		case 5:

			if (is_digit()) {
				state = 7;
			}
			else if (ch == '+' || ch == '-') {
				state = 6;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 5 error\n";
				state = 0;
			}

			break;
		case 6:

			if (is_digit()) {
				state = 7;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 6 error\n";
				state = 0;
			}

			break;
		case 7:

			if (is_digit()) {
				state = 7;
			}
			else if (is_float_suffix()) {
				state = 30;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Float\n";
			}

			break;
		case 8:

			if (ch == '8' || ch == '9') {
				state = 2;
			}
			else if (ch == '.') {
				state = 4;
			}
			else if (is_octal()) {
				state = 9;
			}
			else if (ch == 'E' || ch == 'e') {
				state = 5;
			}
			else if (ch == 'X' || ch == 'x') {
				state = 10;
			}
			else if (ch == 'u' || ch == 'U') {
				state = 31;
			}
			else if (ch == 'l') {
				state = 32;
			}
			else if (ch == 'L') {
				state = 33;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Integer\n";
			}


			break;
		case 9:

			if (ch == '8' || ch == '9') {
				state = 2;
			}
			else if (ch == '.') {
				state = 4;
			}
			else if (ch == 'E' || ch == 'e') {
				state = 5;
			}
			else if (is_octal()) {
				state = 9;
			}
			else if (ch == 'u' || ch == 'U') {
				state = 31;
			}
			else if (ch == 'l') {
				state = 32;
			}
			else if (ch == 'L') {
				state = 33;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Int\n";
			}

			break;
		case 10:

			if (ch == '.') {
				state = 11;
			}
			else if (is_hex()) {
				state = 12;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 10 error\n";
				state = 0;
			}
			break;
		case 11:

			if (is_hex()) {
				state = 13;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 11 error\n";
				state = 0;
			}

			break;
		case 12:
			if (ch == 'p' || ch == 'P') {
				state = 15;
			}
			else if (ch == '.') {
				state = 14;
			}
			else if (is_hex()) {
				state = 12;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Hex Interger\n";
			}

			break;
		case 13:

			if (is_hex()) {
				state = 13;
			}
			else if (ch == 'p' || ch == 'P') {
				state = 15;
			}
			else if(is_float_suffix()) {
				state = 18;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Hex Float\n";
			}

			break;
		case 14:

			if (ch == 'p' || ch == 'P') {
				state = 15;
			}
			else if (is_hex()) {
				state = 14;
			}
			else if (is_float_suffix()) {
				state = 18;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Hex Float\n";
			}

			break;
		case 15:

			if (ch == '+' || ch == '-') {
				state = 16;
			}
			else if (is_hex()) {
				state = 17;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 15 error\n";
				state = 0;
			}

			break;
		case 16:

			if (is_hex()) {
				state = 17;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 16 error\n";
				state = 0;
			}

			break;

		case 17:

			if (is_hex()) {
				state = 17;
			}
			else if (is_float_suffix()) {
				state = 18;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Hex Float\n";
			}

			break;

/*
	states from 18 to 41 will deal with suffix		
*/
		case 18:

			buffer_pairs.Backward();
			std::cout << buffer_pairs.Output() << std::endl;
			state = 0;
			std::cout << "Detect Hex Float\n";

			break;

		case 19:

			if (ch == 'l') {
				state = 22;
			}
			else if (ch == 'L') {
				state = 23;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Interger\n";
			}

			break;

		case 20:

			if (ch == 'u' || ch == 'U') {
				state = 28;
			}
			else if (ch == 'l') {
				state = 24;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Interger\n";
			}

			break;

		case 21:

			if (ch == 'L') {
				state = 25;
			}
			else if (ch == 'u' || ch == 'U') {
				state = 29;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Interger\n";
			}

			break;

		case 22:

			if (ch == 'l') {
				state = 26;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Interger\n";
			}

			break;

		case 23:

			if (ch == 'L') {
				state = 26;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Interger\n";
			}

			break;

		case 24:

			if (ch == 'u' || ch == 'U') {
				state = 26;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Interger\n";
			}

			break;

		case 25:

			if (ch == 'u' || ch == 'U') {
				state = 26;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Interger\n";
			}

			break;

		case 26:

			buffer_pairs.Backward();
			std::cout << buffer_pairs.Output() << std::endl;
			state = 0;
			std::cout << "Detect Interger\n";

			break;

		case 31:

			if (ch == 'l') {
				state = 34;
			}
			else if (ch == 'L') {
				state = 35;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Interger\n";
			}

			break;

		case 32:

			if (ch == 'l') {
				state = 36;
			}
			else if (ch == 'u' || ch == 'U') {
				state = 38;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Interger\n";
			}
			break;

		case 33:

			if (ch == 'L') {
				state = 37;
			}
			else if (ch == 'u' || ch == 'U') {
				state = 38;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Interger\n";
			}

			break;

		case 34:

			if (ch == 'l') {
				state = 38;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Interger\n";
			}

			break;

		case 35:

			if (ch == 'L') {
				state = 38;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Interger\n";
			}
			break;

		case 36:

			if (ch == 'u' || ch == 'U') {
				state = 38;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Interger\n";
			}

			break;

		case 37:

			if (ch == 'u' || ch == 'U') {
				state = 38;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Detect Octal Interger\n";
			}

			break;

		case 38:

			buffer_pairs.Backward();
			std::cout << buffer_pairs.Output() << std::endl;
			state = 0;
			std::cout << "Detect Octal Interger\n";

			break;

		case 101:

			if (ch == '\\') {
				state = 105;
			}
			else if (!is_except()) {
				state = 107;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "state 101 error\n";
			}

			break;

		case 102:

			if (ch == '\'') {
				state = 101;
			}
			else if (is_nonedigit() || is_digit()) {
				state = 201;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Identifier L detecter\n";
			}

			break;

		case 103:

			if (ch == '\"') {
				state = 104;
			}
			else if (is_nonedigit() || is_digit()) {
				state = 201;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "identifier l detected\n";
			}

			break;

		case 104:

			if (ch == '\\') {
				state = 106;
			}
			else if (!is_except()) {
				state = 108;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "state 104 error\n";
			}
			break;

		case 105:

			if (is_escape()) {
				state = 107;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "state 105 error\n";
			}

			break;

		case 106:

			if (is_escape()) {
				state = 108;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "state 106 error\n";
			}

			break;

		case 107:

			if (ch == '\\') {
				state = 105;
			}
			else if (ch == '\'') {
				state = 109;
			}
			else if (!is_except()) {
				state = 107;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "state 107 error\n";
			}
			break;

		case 108:

			if (ch == '\"') {
				state = 110;
			}
			else if (ch == '\\') {
				state = 106;
			}
			else if (!is_except()) {
				state = 108;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "state 108 error\n";
			}

			break;

		case 109:

			buffer_pairs.Backward();
			std::cout << buffer_pairs.Output() << std::endl;
			state = 0;
			std::cout << "character constant detected\n";

			break;

		case 110:

			buffer_pairs.Backward();
			std::cout << buffer_pairs.Output() << std::endl;
			state = 0;
			std::cout << "string detecter\n";

			break;

		case 201:

			if (is_nonedigit() || is_digit()) {
				state = 201;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Identifier detected\n";
			}

			break;

		case 301:

			if (ch == '*') {
				state = 302;
			}
			else if (ch == '/') {
				state = 304;
			}
			else {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "state 301 error\n";
			}

			break;

		case 302:

			if (ch != '*') {
				state = 302;
			}
			else if (ch == '*') {
				state = 303;
			}

			break;

		case 303:

			if (ch == '/') {
				state = 305;
			}
			else if (ch != '/') {
				state = 302;
			}

			break;

		case 304:

			if (ch == '\n') {
				state = 305;
			}
			else if (ch == '\0') {
				buffer_pairs.Backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "Comments detected\n";
														// Unsolved, though it is detected
			}
			else if (ch != '\n') {
				state = 304;
			}

			break;

		case 305:

			buffer_pairs.Backward();
			std::cout << buffer_pairs.Output() << std::endl;
			state = 0;
			std::cout << "Comments detected\n";

			break;

		default:
			
			break;
		}
		
	} while (ch != '\0');
}
