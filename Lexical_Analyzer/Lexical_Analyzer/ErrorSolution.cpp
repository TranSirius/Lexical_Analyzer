/*
		�ò���Ϊ���������洦��ʹ�������ָ�����
*/


#include "Automata.hpp"

/*
	funtion:	��ֹ�û���һ�������������������������������ĸ������������������������������ǰһ���ֵ���������
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
	funtion:	��ֹ�ڸ�����������ɺ��������˷Ƿ�����ĸ�����ų������ĸ�������׺
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
	funtion:	��ֹ�ڸ����������У��û������˶�����������С����
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
	funtion:	��ֹ��������ָ������û������
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
	funtion:	��ָֹ������û�и���ָ��(����)
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
	funtion:	�˽������м�⵽�����ڰ˽������Ĳ���
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
	funtion:	�˽������м�⵽�����ڰ˽������Ĳ���
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
	funtion:	�����û�����0X����0x��û����ȷ����ʮ�����Ƶ�����
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
	funtion:	��ֹ�û�������16��������ʱ����������ֵֹ��ַ�
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
	funtion:	��ֹ16����ָ������û������
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
	funtion:	��ֹ16����ָ������û������
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
	funtion:	��ֹ�û�����''
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
	funtion:	��ֹ�û��������ַ�����ʱ��ֻ��һ��������
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
	funtion:	��ֹ�û������˲��Ϸ��ĳ����ַ�
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
	funtion:	�澯���û�����ĳ����ַ�ת���ַ�����C��׼��
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
	funtion:	�����ַ������з���������
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
	funtion:	��ֹ�û�û�������ַ��������ĵڶ���˫����
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
	funtion:	�����ַ��������е��������
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
	funtion:	�澯�û���һ���ַ������������˹�����ַ�
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
	funtion:	���ż��������".."
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