#pragma once
#include<string>
#include<iostream>
#include<istream>
#include<fstream>

const int N = 4096;
typedef char buffer[N + 1];

class BufferPairs {
private:
	std::ifstream _file;
	int lexeme_begin = 0;
	int _forward = 0;
	int forward_ptr = 0;
	int begin_ptr = 0;
	buffer buffer_pairs[2];
	bool is_empty = true;
private:
	void load_buffer();
	bool forward_is_left_end();
	bool forward_is_right_end();
	char begin_word();
public:
	BufferPairs();
	BufferPairs(const std::string & file_name);
	char Forward(); 
	void Backward();
	std::string Output();
};