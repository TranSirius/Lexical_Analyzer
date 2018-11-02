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

void Automata::backward()
{
	char tmp = buffer_pairs.Backward();
	if (tmp == '\n') {
		row_ptr--;
	}
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
			else if (ch == ',') {
				state = 401;
			}
			else if (ch == ';') {
				state = 402;
			}
			else if (ch == ':') {
				state = 403;
			}
			else if (ch == '?') {
				state = 404;
			}
			else if (ch == '|') {
				state = 405;
			}
			else if (ch == '^') {
				state = 406;
			}
			else if (ch == '=') {
				state = 407;
			}
			else if (ch == '>') {
				state = 408;
			}
			else if (ch == '<') {
				state = 409;
			}
			else if (ch == '%') {
				state = 410;
			}
			else if (ch == '!') {
				state = 412;
			}
			else if (ch == '~') {
				state = 413;
			}
			else if (ch == '*') {
				state = 414;
			}
			else if (ch == '&') {
				state = 415;
			}
			else if (ch == '+') {
				state = 416;
			}
			else if (ch == '-') {
				state = 417;
			}
			else if (ch == '.') {
				state = 418;
			}
			else if (ch == '}') {
				state = 419;
			}
			else if (ch == '{') {
				state = 420;
			}
			else if (ch == ')') {
				state = 421;
			}
			else if (ch == '(') {
				state = 422;
			}
			else if (ch == ']') {
				state = 423;
			}
			else if (ch == '[') {
				state = 424;
			}
			else if (ch == '#') {
				state = 425;
			}
			else {
				std::cout << buffer_pairs.Output() << std::endl;
				std::cerr << "state 0 error\n";
				std::cout << "state 0 error\n";
				state = 0;
			}

			break;
		case 1:

			if (is_digit()) {
				state = 3;
			}
			else if (ch == '.') {
				state = 522;
			}
			else {
				returnPunc();
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
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
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
			else if (is_letter()) {
				state3LetterError();
			}
			else if (ch == '.') {
				state3_4DotError();
			}
			else {
				returnFloat();
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
			else if (ch == '.') {
				state3_4DotError();
			}
			else {
				returnFloat();
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
				state5Error();
			}

			break;
		case 6:

			if (is_digit()) {
				state = 7;
			}
			else {
				state6Error();
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
				returnFloat();
			}

			break;
		case 8:

			if (ch == '8' || ch == '9') {
				state8Error();
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
				returnOctInt();
			}


			break;
		case 9:

			if (ch == '8' || ch == '9') {
				state9Error();
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
				returnOctInt();
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
				state10Error();
			}
			break;
		case 11:

			if (is_hex()) {
				state = 13;
			}
			else {
				state11Error();
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
				returnHexInt();
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
				returnHexFloat();
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
				returnHexFloat();
			}

			break;
		case 15:

			if (ch == '+' || ch == '-') {
				state = 16;
			}
			else if (is_digit()) {
				state = 17;
			}
			else {
				state15Error();
			}

			break;
		case 16:

			if (is_hex()) {
				state = 17;
			}
			else {
				state16Error();
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
				returnHexFloat();
			}

			break;

/*
	states from 18 to 41 will deal with suffix		
*/
		case 18:

			returnHexFloat();

			break;

		case 19:

			if (ch == 'l') {
				state = 22;
			}
			else if (ch == 'L') {
				state = 23;
			}
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
			}

			break;

		case 20:

			if (ch == 'u' || ch == 'U') {
				state = 28;
			}
			else if (ch == 'l') {
				state = 24;
			}
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
			}

			break;

		case 21:

			if (ch == 'L') {
				state = 25;
			}
			else if (ch == 'u' || ch == 'U') {
				state = 29;
			}
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
			}

			break;

		case 22:

			if (ch == 'l') {
				state = 26;
			}
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
			}

			break;

		case 23:

			if (ch == 'L') {
				state = 26;
			}
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
			}

			break;

		case 24:

			if (ch == 'u' || ch == 'U') {
				state = 26;
			}
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
			}

			break;

		case 25:

			if (ch == 'u' || ch == 'U') {
				state = 26;
			}
			else if (is_letter()) {
				state2_19_20_21_22_23_24_25SuffixError();
			}
			else {
				returnInt();
			}

			break;

		case 26:

			returnInt();

			break;

		case 30:

			returnFloat();

		case 31:

			if (ch == 'l') {
				state = 34;
			}
			else if (ch == 'L') {
				state = 35;
			}
			else {
				returnOctInt();
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
				returnOctInt();
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
				returnOctInt();
			}

			break;

		case 34:

			if (ch == 'l') {
				state = 38;
			}
			else {
				returnOctInt();
			}

			break;

		case 35:

			if (ch == 'L') {
				state = 38;
			}
			else {
				returnOctInt();
			}
			break;

		case 36:

			if (ch == 'u' || ch == 'U') {
				state = 38;
			}
			else {
				returnOctInt();
			}

			break;

		case 37:

			if (ch == 'u' || ch == 'U') {
				state = 38;
			}
			else {
				returnOctInt();
			}

			break;

		case 38:

			returnOctInt();

			break;

		case 101:

			if (ch == '\\') {
				state = 105;
			}
			else if (!is_except()) {
				state = 107;
			}
			else if (ch == '\'') {
				state101EmptyError();
			}
			else if (ch == '\n') {
				state101_107Error();
			}
			else {
				state101Error();
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
				backward();
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
				backward();
				std::cout << buffer_pairs.Output() << std::endl;
				state = 0;
				std::cout << "identifier l detected\n";
			}

			break;

		case 104:

			if (ch == '\\') {
				state = 106;
			}
			else if (ch == '\"') {
				state = 110;
			}
			else if (ch != '\n' && ch != '\\') {
				state = 108;
			}
			else if (ch == '\n') {
				state104_108Error();
			}
			else {
				state108Error();
			}
			break;

		case 105:

			if (is_escape()) {
				state = 107;
			}
			else {
				state = 107;
				state105Warning();
			}

			break;

		case 106:

			if (is_escape()) {
				state = 108;
			}
			else {
				state = 108;
				state105Warning();
			}

			break;

		case 107:

			if (ch == '\\') {
				constantWarning();
				state = 105;
			}
			else if (ch == '\'') {
				state = 109;
			}
			else if (ch != '\n' && ch != '\"' ) {
				state = 107;
				constantWarning();
			}
			else if (ch == '\n') {
				state101_107Error();
			}
			else {
				state107Error();
			}
			break;

		case 108:

			if (ch == '\"') {
				state = 110;
			}
			else if (ch == '\\') {
				state = 106;
			}
			else if (ch != '\n') {
				state = 108;
			}
			else if (ch == '\n') {
				state104_108Error();
			}
			else {
				state108Error();
			}

			break;

		case 109:

			returnCharacterConstant();

			break;

		case 110:

			returnString();

			break;

		case 201:

			if (is_nonedigit() || is_digit()) {
				state = 201;
			}
			else {
				returnIdentifier();
			}

			break;

		case 301:

			if (ch == '*') {
				state = 302;
			}
			else if (ch == '/') {
				state = 304;
			}
			else if (ch == '=') {
				state = 512;
			}
			else {
				returnPunc();
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
				returnComment();
														// Unsolved, though it is detected
			}
			else if (ch == '\\') {
				state = 306;
			}
			else if (ch != '\n') {
				state = 304;
			}

			break;

		case 305:

			returnComment();

			break;

			//punctuation

		case 306:

			state = 304;

			break;

		case 401:

			returnPunc();

			break;
		case 402:

			returnPunc();

			break;
		case 403:

			returnPunc();

			break;
		case 404:

			returnPunc();

			break;
		case 405:

			if (ch == '|') {
				state = 501;
			}
			else if (ch == '=') {
				state = 502;
			}
			else {
				returnPunc();
			}

			break;
		case 406:

			if (ch == '=') {
				state = 503;
			}
			else {
				returnPunc();
			}

			break;
		case 407:

			if (ch == '=') {
				state = 504;
			}
			else {
				returnPunc();
			}

			break;
		case 408:

			if (ch == '>') {
				state = 505;
			}
			else if (ch == '=') {
				state = 507;
			}
			else {
				returnPunc();
			}

			break;
		case 409:

			if (ch == '<') {
				state = 508;
			}
			else if (ch == '=') {
				state = 510;
			}
			else {
				returnPunc();
			}

			break;
		case 410:

			if (ch == '=') {
				state = 511;
			}
			else {
				returnPunc();
			}

			break;
		case 411:

			if (ch == '=') {
				state = 512;
			}
			else {
				returnPunc();
			}

			break;
		case 412:

			if (ch == '=') {
				state = 513;
			}
			else {
				returnPunc();
			}

			break;
		case 413:

			returnPunc();

			break;
		case 414:

			if (ch == '=') {
				state = 514;
			}
			else {
				returnPunc();
			}

			break;
		case 415:

			if (ch == '&') {
				state = 515;
			}
			else if (ch == '=') {
				state = 516;
			}
			else {
				returnPunc();
			}

			break;
		case 416:

			if (ch == '+') {
				state = 517;
			}
			else if (ch == '=') {
				state = 518;
			}
			else {
				returnPunc();
			}
			break;
		case 417:

			if (ch == '>') {
				state = 519;
			}
			else if (ch == '-') {
				state = 520;
			}
			else if (ch == '=') {
				state = 521;
			}
			else {
				returnPunc();
			}

			break;
		case 418:

			if (ch == '.') {
				state = 522;
			}
			else {
				returnPunc();
			}

			break;
		case 419:

			returnPunc();

			break;
		case 420:

			returnPunc();

			break;
		case 421:

			returnPunc();

			break;
		case 422:

			returnPunc();

			break;
		case 423:

			returnPunc();

			break;
		case 424:

			returnPunc();

			break;
		case 425:

			returnPunc();

			break;
		case 501:

			returnPunc();

			break;
		case 502:

			returnPunc();

			break;
		case 503:

			returnPunc();

			break;
		case 504:

			returnPunc();

			break;
		case 505:

			if (ch == '=') {
				state = 506;
			}
			else {
				returnPunc();
			}

			break;
		case 506:

			returnPunc();

			break;
		case 507:

			returnPunc();

			break;
		case 508:

			if (ch == '=') {
				state = 509;
			}
			else {
				returnPunc();
			}

			break;
		case 509:

			returnPunc();

			break;
		case 510:

			returnPunc();

			break;
		case 511:

			returnPunc();

			break;
		case 512:

			returnPunc();

			break;
		case 513:

			returnPunc();

			break;
		case 514:

			returnPunc();

			break;
		case 515:

			returnPunc();

			break;
		case 516:

			returnPunc();

			break;
		case 517:

			returnPunc();

			break;
		case 518:

			returnPunc();

			break;
		case 519:
			returnPunc();
			break;
		case 520:
			returnPunc();
			break;
		case 521:
			returnPunc();
			break;
		case 522:
			if (ch == '.') {
				state = 523;
			}
			else {
				state522Error();
			}
			break;
		case 523:
			returnPunc();
			break;
		default:
			break;
		}
	} while (ch != '\0');

	std::cout << "Total row = " << row_ptr << std::endl;
	std::cout << "Total lexeme(Punctuation and comments are not counted) = " << lexeme_count << std::endl;
	std::cout << "Total Error: \t\t" << error_count << std::endl;
	std::cout << "Total Warning:\t\t" << warning_count << std::endl << std::endl;
	std::cout << "Total Identifier:\t" << identifier_count << std::endl;
	std::cout << "Total Int:\t\t" << int_count << std::endl;
	std::cout << "Total Float:\t\t" << float_count << std::endl;
	std::cout << "Total Octal Int:\t" << octal_int_count << std::endl;
	std::cout << "Total Hex Int:\t\t" << hex_int_count << std::endl;
	std::cout << "Total Hex Float:\t" << hex_float_count << std::endl;
	std::cout << "Total Char Constant:\t" << char_count << std::endl;
	std::cout << "Total String Constant:\t" << string_count << std::endl;
	std::cout << "Total Comments:\t\t" << comment_count << std::endl;
	std::cout << "Total Puncturation:\t" << punctuation_count << std::endl;
	symbol_table.outputToDisk(symbol_table_file);
}
