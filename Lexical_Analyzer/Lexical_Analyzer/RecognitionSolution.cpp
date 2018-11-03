#include "Automata.hpp"

/*
	funtion:	�жϵ�ǰ��ȡ���Ƿ���0��7
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ���0-9��a-f��A-F
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ���0-9
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ���Ӣ�ķ�����ĸ
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ��ǻ��з����Ʊ���Ϳո�
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ��Ǹ������ĺϷ���׺
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ����ַ������еĲ��Ϸ��ַ�
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ���ת���ַ�
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
	funtion:	�жϵ�ǰ��ȡ���Ƿ�����ĸ���»���
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