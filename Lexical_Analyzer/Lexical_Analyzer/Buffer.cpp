#include "Buffer.hpp"

/*
	return:			void
	parameter:		void
	funtion:		��Ӳ���ж�ȡN���ַ�������buffer pairs�е�һ��buffer��
					���ļ����ܷ��ʱ������ڱ�׼������в���������Ϣ
*/
void BufferPairs::load_buffer()
{
	if (is_empty == true) {													//�����жϣ���һ��buffer���Ƿ��Ѿ��������ˣ�����Ϊ�˷�ֹ����֮������������
		if (_file.is_open()) {
			_file.get(buffer_pairs[forward_ptr], N + 1, EOF);
			buffer_pairs[forward_ptr][N] = '\0';							//��buffer�����������sentinel������ȡ����sentinelʱ���ж��Ƿ񵽴��ļ�β
			is_empty = false;
		}
		else {
			std::cerr << "Error! File was not opened!\n";
//			exit(0);
		}
	}
}

/*
	return:			bool
	parameter:		void
	funtion:		�жϵ�ǰ����ǰָ���Ƿ�����˵�һ�����ڵĻ����������Ҷ�
*/

bool BufferPairs::forward_is_left_end()
{
	if (forward_ptr == 0 && _forward == N) {
		return true;
	}
	else {
		return false;
	}
}

/*
	return:			bool
	parameter:		void
	funtion:		�жϵ�ǰ����ǰָ���Ƿ��ڵڶ��������������Ҷ�
*/

bool BufferPairs::forward_is_right_end()
{
	if (forward_ptr == 1 && _forward == N) {
		return true;
	}
	else {
		return false;
	}
}

/*
	return:			char
	parameter:		void
	funtion:		���ַ���ʼָ����ǰ�ƶ�һλ�������ظ�ָ���ǰָ��λ�õ��ַ�
*/

char BufferPairs::begin_word()
{
	char tmp;
	if (lexeme_begin == N) {								//�����ָ���ƶ�����һ��buffer�ı�Ե�����ͷŵ���buffer(�趨is_empty)
		lexeme_begin = 0;
		begin_ptr = (begin_ptr + 1) % 2;
		is_empty = true;
	}
	tmp = buffer_pairs[begin_ptr][lexeme_begin];
	return tmp;
}

/*
	return:			���캯��
	parameter:		void
	funtion:		Ĭ�Ϲ��캯��������������Ĺ���
*/

BufferPairs::BufferPairs()
{
	lexeme_begin = 0;
	_forward = 0;
	forward_ptr = 0;
	std::cerr << "Error! No input file!\n";
//	exit(0);
}

/*
	return:			void
	parameter:		file_name: �����ļ����ļ���
	funtion:		��һ���ļ��������û����������ں��������У������Ӹ��ļ����ȡ��Ϣ
*/

BufferPairs::BufferPairs(const std::string & file_name)
{
	lexeme_begin = 0;								//ָ���ʼ��	
	_forward = -1;
	forward_ptr = 0;
	begin_ptr = 0;
	_file.open(file_name.data(), std::ios::in);		//���ļ�����������buffer���ļ�������
	if (_file.is_open()) {							//�ļ��򿪺����ȶ���һ���֣������ļ���ʧ�ܴ���
		_file.get(buffer_pairs[forward_ptr], N + 1, EOF);
		buffer_pairs[forward_ptr][N] = '\0';
	}
	else {
		std::cerr << "Error ! no such file!\n";
//		exit(0);
	}
}

/*
	return:			char
	parameter:		void
	funtion:		����ǰָ��ǰ��һλ��ͬʱ����λ�õ��ַ����س���
*/

char BufferPairs::Forward()
{
	_forward++;
	char tmp = buffer_pairs[forward_ptr][_forward];
	if (tmp == '\0') {								//����sentinel���ж����ļ������ˣ����Ƕ���buffer��ĩβ��
		if (forward_is_left_end()) {
			_forward = 0;
			forward_ptr = 1;
			load_buffer();
			tmp = buffer_pairs[forward_ptr][_forward];
			return tmp;
		}
		else if (forward_is_right_end()) {
			_forward = 0;
			forward_ptr = 0;
			load_buffer();
			tmp = buffer_pairs[forward_ptr][_forward];
			return tmp;
		}
		else {
			return tmp;								//�ļ����꣬����\0
		}
	}
	else {
		return tmp;
	}
}

/*
	return:			char
	parameter:		void
	funtion:		������ǰָ�룬�����ػ���ǰ��ֵ
*/

char BufferPairs::Backward()
{
	char tmp = buffer_pairs[forward_ptr][_forward];
	if (_forward == 0) {
		_forward = N - 1;
		forward_ptr = (forward_ptr + 1) % 2;
	}
	else {
		_forward--;
	}
	return tmp;
}

/*
	return:			string
	parameter:		void
	funtion:		������ָ��֮����ַ������س�����ͬʱ��begin_lexemeָ���ƶ�����ǰָ���λ����
*/

std::string BufferPairs::Output()
{
	std::string out_put;
	char tmp;
	while (begin_ptr != forward_ptr || (begin_ptr == forward_ptr && lexeme_begin <= _forward)) {
		out_put.push_back(begin_word());
		lexeme_begin++;
	}
	if (lexeme_begin <= _forward) {
		lexeme_begin++;
	}
	return out_put;
}
