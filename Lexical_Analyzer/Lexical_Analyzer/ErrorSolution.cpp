/*
		该部分为错误处理、警告处理和错误紧急恢复功能
*/


#include "Automata.hpp"

/*
	funtion:	防止用户在一个完整的整数后，又输入了无意义的字母，如果发生这种情况，则进入错误处理，对前一部分的整数计数
*/

void Automata::state2_19_20_21_22_23_24_25SuffixError()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid suffix detected" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止在浮点数输入完成后，又输入了非法的字母，已排除正常的浮点数后缀
*/

void Automata::state3LetterError()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid suffix detected" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止在浮点数输入中，用户输入了多个不明意义的小数点
*/

void Automata::state3_4DotError()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] too many decimal points in number" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止浮点数的指数部分没有数字
*/

void Automata::state5Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] exponent has no digits" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] exponent has no digits" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止指数部分没有给处指数(数字)
*/

void Automata::state6Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] plus or minus has no digits" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] plus or minus has no digits" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	八进制数中检测到不属于八进制数的部分
*/

void Automata::state8Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in octal constant" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	八进制数中检测到不属于八进制数的部分
*/

void Automata::state9Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit in octal constant" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	避免用户输入0X或者0x后，没有明确输入十六进制的数字
*/

void Automata::state10Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] Empty dexical number" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] Empty dexical number" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止用户在输入16进制数的时候输入奇奇怪怪的字符
*/

void Automata::state11Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] invalid digit or letter in hex constant" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid digit or letter in hex constant" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

void Automata::state13_14Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] hexadecimal floating constants require an exponent" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] hexadecimal floating constants require an exponent" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止16进制指数部分没有数字
*/

void Automata::state15Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] P exponent has no digits" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] P exponent has no digits" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止16进制指数部分没有数字
*/

void Automata::state16Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] plus or minus has no digits" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] plus or minus has no digits" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止用户输入''
*/

void Automata::state101EmptyError()
{
	lexeme_count++;
	lexeme_ptr++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] Empty character constant" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止用户在输入字符常量时，只有一个单引号
*/

void Automata::state101_107Error()
{
	lexeme_count++;
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] missing terminating \' character" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] missing terminating \' character" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止用户输入了不合法的常量字符
*/

void Automata::state101Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {
		error_file << row_ptr - 1 << ":" << 0 << " [Error] invalid character" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] invalid character" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	告警当用户输入的常量字符转义字符不是C标准的
*/

void Automata::state105Warning()
{
	if (warning == 0) {
		warning = 1;
		error_file << row_ptr << ":" << lexeme_ptr + 1 << " [Warning] unknow sequences detected" << std::endl;
		warning_count++;
	}
}

/*
	funtion:	处理字符常量中发生的意外
*/

void Automata::state107Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	if (ch == '\n') {

		error_file << row_ptr - 1<< ":" << 0 << " [Error] char constant error" << std::endl;
	}
	else {
		error_file << row_ptr << ":" << lexeme_ptr << " [Error] char constant error" << std::endl;
	}
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	防止用户没有输入字符串常量的第二个双引号
*/

void Automata::state104_108Error()
{
	lexeme_count++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr - 1<< ":" << " " << " [Error] missing terminating \" character" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	处理字符串常量中的意外情况
*/

void Automata::state108Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] string constant error" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}

/*
	funtion:	告警用户在一个字符常量中输入了过多的字符
*/

void Automata::constantWarning()
{
	if (warning == 0) {
		warning = 1;
		error_file << row_ptr << ":" << lexeme_ptr + 1 << " [Warning] multi-character character constant" << std::endl;
		warning_count++;
	}
}

/*
	funtion:	符号检测中遇到".."
*/

void Automata::state522Error()
{
	lexeme_count++;
	lexeme_ptr++;
	//backward();
	std::string tmp = buffer_pairs.Output();
	error_file << row_ptr << ":" << lexeme_ptr << " [Error] punctuation error an extra . has been detected" << std::endl;
	error_file << "\t\t" << tmp << std::endl;
	state = 0;
	error_count++;
}