#pragma once
#include<string>
#include<iostream>
#include<istream>
#include<fstream>

const int N = 4096;									//buffer pairs中，每个缓冲区的大小
typedef char buffer[N + 1];							//定义buffer pairs中的一个buffer的结构为长度为N+1的字符数组
 

class BufferPairs {
private:
	std::ifstream _file;							//输入文件流
	int lexeme_begin = 0;							//缓冲区读取指针，指向单词开始的位置
	int _forward = 0;								//缓冲区向前指针，指向当前读到的位置
	int forward_ptr = 0;							//双buffer指针，指示当前向前指针所在的缓冲区是两个中的哪一个
	int begin_ptr = 0;								//双buffer指针，指示当前开始指针所在的缓冲区是两个中的哪一个
	buffer buffer_pairs[2];							//定义buffer pairs的结构
	bool is_empty = true;							//标志变量，用于明确上一步是否有回退发生
private:
	void load_buffer();								//将N个字符读进缓冲区内
	bool forward_is_left_end();						//判断向前指针是否在缓冲区的左边缘
	bool forward_is_right_end();					//判断向前指针是否在缓冲区的右边缘
	char begin_word();								//返回当前状态下，begin指针指向的字符
public:
	BufferPairs();									//无参构造函数，防止无意义的缓冲区被创造
	BufferPairs(const std::string & file_name);		//构造函数，传入的参数为打开的文件的文件名
	char Forward();									//向前指针往前读一位
	char Backward();								//向前指针回退一位
	std::string Output();							//将lexeme_begin和_forward之间的字符串输出出来
};