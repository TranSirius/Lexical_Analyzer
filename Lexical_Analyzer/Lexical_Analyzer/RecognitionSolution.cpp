#include "Automata.hpp"

/*
	funtion:	判断当前读取的是否是0到7
*/

bool Automata::is_octal()
{
	if (ch >= '0' && ch <= '7') {
		return true;
	}
	else {
		return false;
	}
}

/*
	funtion:	判断当前读取的是否是0-9，a-f，A-F
*/

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

/*
	funtion:	判断当前读取的是否是0-9
*/

bool Automata::is_digit()
{
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	else {
		return false;
	}
}

/*
	funtion:	判断当前读取的是否是英文符号字母
*/

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

/*
	funtion:	判断当前读取的是否是换行符，制表符和空格
*/

bool Automata::is_whitespace()
{
	if (ch == '\t' || ch == '\n' || ch == '\t') {
		return true;
	}
	else {
		return false;
	}
}

/*
	funtion:	判断当前读取的是否是浮点数的合法后缀
*/

bool Automata::is_float_suffix()
{
	if (ch == 'f' || ch == 'l' || ch == 'F' || ch == 'L') {
		return true;
	}
	else {
		return false;
	}
}

/*
	funtion:	判断当前读取的是否是字符常量中的不合法字符
*/

bool Automata::is_except()
{
	if (ch == '\'' || ch == '\\' || ch == '\n') {
		return true;
	}
	else {
		return false;
	}
}

/*
	funtion:	判断当前读取的是否是转义字符
*/

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
		ch == 'v' ||
		ch == '\n' ||
		ch == '\\' ||
		ch == '0' ||
		ch == '1' ||
		ch == '2' ||
		ch == '3' ||
		ch == '4' ||
		ch == '5' ||
		ch == '6' ||
		ch == '7' ||
		ch == '8' ||
		ch == '9'
		)
	{
		return true;
	}
	else {
		return false;
	}
}

/*
	funtion:	判断当前读取的是否是字母或下划线
*/

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