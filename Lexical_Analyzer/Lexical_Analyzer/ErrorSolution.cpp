#include "Automata.hpp"

void Automata::state2_19_20_21_22_23_24_25SuffixError()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid suffix detected" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state3LetterError()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid suffix detected" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state3_4DotError()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] too many decimal points in number" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state5Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] exponent has no digits" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state6Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] plus or minus has no digits" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state8Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in octal constant" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state9Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in octal constant" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state10Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] Empty dexical number" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state11Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in hex constant" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state15Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] [Error] P exponent has no digits" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state16Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] plus or minus has no digits" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state101EmptyError()
{
	lexeme_count++;
	lexeme_ptr++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] Empty character constant" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state101_107Error()
{
	lexeme_count++;
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr - 1 << ":" << " " << " [Error] missing terminating \' character" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state101Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid character" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state105Warning()
{
	if (warning == 0) {
		warning = 1;
		error_file << row_ptr << ":" << lexeme_ptr + 1 << " [Warning] unknow sequences detected" << std::endl;
		warning_count++;
	}
}

void Automata::state107Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] char constant error" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state104_108Error()
{
	lexeme_count++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr - 1<< ":" << " " << " [Error] missing terminating \" character" << std::endl;
	state = 0;
	error_count++;
}

void Automata::state108Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] string constant error" << std::endl;
	state = 0;
	error_count++;
}

void Automata::constantWarning()
{
	if (warning == 0) {
		warning = 1;
		error_file << row_ptr << ":" << lexeme_ptr + 1 << " [Warning] multi-character character constant" << std::endl;
		warning_count++;
	}
}

void Automata::state522Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] punctuation error an extra . has been detected" << std::endl;
	state = 0;
	error_count++;
}