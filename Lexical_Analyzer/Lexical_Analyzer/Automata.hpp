#pragma once
#include "Buffer.hpp"
#include "SymbolTable.hpp"
#include <fstream>
typedef int State;

enum CH_TYPE {
	letter,
	digits,
	others
};

enum ERROR_TYPE {
	unknown,
	identifier
};

class Automata {
private:
	BufferPairs buffer_pairs;
	SymbolTable symbol_table;

	std::string output_file;
	std::string symbol_table_file;
	std::string token_file;
	std::string error_file;

	State state;
	char ch;
	CH_TYPE ch_type;

	int row_ptr;
	int lexeme_ptr;
private:
	void get_char();
	void get_nbc();
	void get_ch_type();
	void generate_error(ERROR_TYPE error_type = unknown);

	bool is_octal();
	bool is_hex();
	bool is_digit();
	bool is_letter();
	bool is_whitespace();

public:
	Automata(std::string _input_file, std::string _output_file, std::string _symbol_table_file, std::string _token_file, std::string _error_file) :
		buffer_pairs(_input_file), output_file(_output_file), symbol_table_file(_symbol_table_file), token_file(_token_file), error_file(_error_file),
		state(0), row_ptr(1), lexeme_ptr(0) {};
	Automata(std::string _input_file, std::string _output_file, std::string _symbol_table_file, std::string _token_file):
		buffer_pairs(_input_file), output_file(_output_file), symbol_table_file(_symbol_table_file), token_file(_token_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
	};
	Automata(std::string _input_file, std::string _output_file, std::string _symbol_table_file) :
		buffer_pairs(_input_file), output_file(_output_file), symbol_table_file(_symbol_table_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
		token_file.clear();
	};
	Automata(std::string _input_file, std::string _output_file) :
		buffer_pairs(_input_file), output_file(_output_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
		token_file.clear();
		symbol_table_file.clear();
	};

	void run(void);
};