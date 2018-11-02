#pragma once
#include "Buffer.hpp"
#include "SymbolTable.hpp"
#include <fstream>
typedef int State;

enum ERROR_TYPE {
	unknown,
	identifier
};

class Automata {
private:
	BufferPairs buffer_pairs;
	SymbolTable symbol_table;

	std::ofstream output_file;
	std::string symbol_table_file;
	std::string token_file;
	std::ofstream error_file;

	State state;
	char ch;

	int row_ptr;
	int lexeme_ptr;
	long lexeme_count = 0;

	int warning_count = 0;
	int error_count = 0;
	int identifier_count = 0;

	int int_count = 0;
	int float_count = 0;
	int hex_int_count = 0;
	int hex_float_count = 0;
	int octal_int_count = 0;

	int char_count = 0;
	int string_count = 0;
	int comment_count = 0;

	int punctuation_count = 0;

	std::ofstream token_stream;

	int warning = 0;
private:
	void get_char();
	void get_nbc();
	void generate_error(ERROR_TYPE error_type = unknown);

	void backward();

	bool is_octal();
	bool is_hex();
	bool is_digit();
	bool is_letter();
	bool is_whitespace();
	bool is_float_suffix();
	bool is_except();
	bool is_escape();
	bool is_nonedigit();

	void returnFloat();
	void returnInt();
	void returnOctInt();
	void returnHexFloat();
	void returnHexInt();
	void returnCharacterConstant();
	
	void returnString();
	void returnIdentifier();
	void returnComment();
	
	void returnPunc();

	void state2_19_20_21_22_23_24_25SuffixError();
	void state3LetterError();
	void state3_4DotError();
	void state5Error();
	void state6Error();
	void state8Error();
	void state9Error();
	void state10Error();
	void state11Error();
	void state15Error();
	void state16Error();
	void state101EmptyError();
	void state101_107Error();
	void state101Error();
	void state105Warning();
	void state107Error();
	void state104_108Error();
	void state108Error();
	void constantWarning();

	void state522Error();

public:
	/*
	Automata(std::string _input_file, std::string _output_file, std::string _symbol_table_file, std::string _token_file, std::string _error_file) :
		buffer_pairs(_input_file), output_file(_output_file), symbol_table_file(_symbol_table_file), token_file(_token_file), error_file(_error_file),
		state(0), row_ptr(1), lexeme_ptr(0) {};
	*/
	Automata(std::string _input_file, std::string _output_file, std::string _error_file, std::string _symbol_table):
		buffer_pairs(_input_file), output_file(_output_file), symbol_table_file(_symbol_table), error_file(_error_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
		output_file.clear();
	};
	
	Automata(std::string _input_file, std::string _output_file, std::string _error_file) :
		buffer_pairs(_input_file), output_file(_output_file), error_file(_error_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
		output_file.clear();
	};
	
	Automata(std::string _input_file, std::string _output_file) :
		buffer_pairs(_input_file), output_file(_output_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
		error_file.clear();
		token_file.clear();
		output_file.clear();
	};
	Automata(std::string _input_file) :
		buffer_pairs(_input_file),
		state(0), row_ptr(1), lexeme_ptr(0) {
	}

	void run(void);
};