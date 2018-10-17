#include "Buffer.hpp"

void BufferPairs::load_buffer()
{
	if (is_empty == true) {
		if (_file.is_open()) {
			_file.get(buffer_pairs[forward_ptr], N + 1, EOF);
			buffer_pairs[forward_ptr][N] = EOF;
			is_empty = false;
		}
		else {
			std::cerr << "Error! File was not opened!\n";
//			exit(0);
		}
	}
}

bool BufferPairs::forward_is_left_end()
{
	if (forward_ptr == 0 && _forward == N) {
		return true;
	}
	else {
		return false;
	}
}

bool BufferPairs::forward_is_right_end()
{
	if (forward_ptr == 1 && _forward == N) {
		return true;
	}
	else {
		return false;
	}
}

char BufferPairs::begin_word()
{
	char tmp;
	if (lexeme_begin == N) {
		lexeme_begin = 0;
		begin_ptr = (begin_ptr + 1) % 2;
		is_empty = true;
	}
	tmp = buffer_pairs[begin_ptr][lexeme_begin];
	return tmp;
}

BufferPairs::BufferPairs()
{
	lexeme_begin = 0;
	_forward = 0;
	forward_ptr = 0;
	std::cerr << "Error! No input file!\n";
//	exit(0);
}

BufferPairs::BufferPairs(std::string file_name)
{
	lexeme_begin = 0;
	_forward = -1;
	forward_ptr = 0;
	begin_ptr = 0;
	_file.open(file_name.data(), std::ios::in);
	if (_file.is_open()) {
		_file.get(buffer_pairs[forward_ptr], N + 1, EOF);
		buffer_pairs[forward_ptr][N] = EOF;
	}
	else {
		std::cerr << "Error ! no such file!\n";
//		exit(0);
	}
}

char BufferPairs::Forward()
{
	_forward++;
	char tmp = buffer_pairs[forward_ptr][_forward];
	if (tmp == EOF) {
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
			return tmp;
		}
	}
	else {
		return tmp;
	}
}

void BufferPairs::Backward()
{
	if (_forward == 0) {
		_forward = N - 1;
		forward_ptr = (forward_ptr + 1) % 2;
	}
	else {
		_forward--;
	}
}

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
