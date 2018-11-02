#include "Buffer.hpp"

/*
	return:			void
	parameter:		void
	funtion:		从硬盘中读取N个字符，填充进buffer pairs中的一个buffer里
					对文件不能访问报错，并在标准输出流中产生错误信息
*/
void BufferPairs::load_buffer()
{
	if (is_empty == true) {													//首先判断，下一个buffer中是否已经有数据了，这是为了防止回退之后遗留了数据
		if (_file.is_open()) {
			_file.get(buffer_pairs[forward_ptr], N + 1, EOF);
			buffer_pairs[forward_ptr][N] = '\0';							//在buffer的最后面填入sentinel，当读取遇到sentinel时，判断是否到达文件尾
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
	funtion:		判断当前的向前指针是否读到了第一个所在的缓冲区的最右端
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
	funtion:		判断当前的向前指针是否在第二个缓冲区的最右端
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
	funtion:		将字符开始指针往前移动一位，并返回该指针此前指向位置的字符
*/

char BufferPairs::begin_word()
{
	char tmp;
	if (lexeme_begin == N) {								//如果该指针移动到了一个buffer的边缘，则释放掉该buffer(设定is_empty)
		lexeme_begin = 0;
		begin_ptr = (begin_ptr + 1) % 2;
		is_empty = true;
	}
	tmp = buffer_pairs[begin_ptr][lexeme_begin];
	return tmp;
}

/*
	return:			构造函数
	parameter:		void
	funtion:		默认构造函数，避免无输入的构造
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
	parameter:		file_name: 输入文件的文件名
	funtion:		将一个文件关联到该缓冲区来，在后续操作中，都将从该文件里读取信息
*/

BufferPairs::BufferPairs(const std::string & file_name)
{
	lexeme_begin = 0;								//指针初始化	
	_forward = -1;
	forward_ptr = 0;
	begin_ptr = 0;
	_file.open(file_name.data(), std::ios::in);		//打开文件，并关联到buffer的文件输入流
	if (_file.is_open()) {							//文件打开后首先读入一部分，并做文件打开失败处理
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
	funtion:		将向前指针前移一位，同时将该位置的字符返回出来
*/

char BufferPairs::Forward()
{
	_forward++;
	char tmp = buffer_pairs[forward_ptr][_forward];
	if (tmp == '\0') {								//遇到sentinel，判断是文件读完了，还是读到buffer的末尾了
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
			return tmp;								//文件读完，返回\0
		}
	}
	else {
		return tmp;
	}
}

/*
	return:			char
	parameter:		void
	funtion:		回退向前指针，并返回回退前的值
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
	funtion:		将两个指针之间的字符串返回出来，同时将begin_lexeme指针移动到向前指针的位置上
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
