#include "Automata.hpp"
#include "Buffer.hpp"
#include "SymbolTable.hpp"
#include <iostream>
#include <stack>
#include <time.h>
#include <istream>


std::ostream & operator<<(std::ostream & out, FirstType first) {
	if (first == IDENTIFIER) {
		out << "IDENTIFIER";
	}
	else if (first == NONE1) {
		out << "NONE1";
	}
	else if (first == RESERVED_WORD) {
		out << "RESERVED WORD";
	}
	return out;
}

int main(int argc, char ** argv)
{
	std::string input_file;
	std::string token_stream_file;
	std::string error_file;
	std::string symbol_table;
	std::ifstream test;
	std::cout << "Please key in the file name of the input file" << std::endl;
	std::cin >> input_file;
	test.open(input_file, std::ios::in);
	while (!test.is_open()) {
		std::cout << "invalid file name, please confirm and input it again\n";
		std::cin >> input_file;
		test.open(input_file);
	}
	test.close();
	std::cout << "Please key in the file name of the output file" << std::endl;
	std::cin >> token_stream_file;
	if (token_stream_file == "\n") {
		token_stream_file = "output_token.txt";
	}
	std::cout << "Please key in the file name of the error file" << std::endl;
	std::cin >> error_file;
	if (error_file == "\n") {
		error_file = "error_file.txt";
	}
	std::cout << "Please key in the file name of the symbol table file" << std::endl;
	std::cin >> symbol_table;
	if (symbol_table == "\n") {
		symbol_table = "symbol_table.txt";
	}

	Automata analyzer(input_file, token_stream_file, error_file, symbol_table);
	analyzer.run();

	for (;;);
	return 0;
}
