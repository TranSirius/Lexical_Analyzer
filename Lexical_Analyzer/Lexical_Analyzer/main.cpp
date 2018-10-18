#include "Automata.hpp"
#include "Buffer.hpp"
#include "SymbolTable.hpp"
#include <iostream>
#include <stack>
#include <time.h>

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

int main()
{
	srand((unsigned int)time(0));
	BufferPairs buffer("C:\\Users\\TranS\\Desktop\\test\\test.txt");

	SymbolTable table;
	std::cout << table.toTable("int").firstType << std::endl;
	std::cout << table.toTable("x").firstType << std::endl;
	std::cout << table.toTable("x").firstType << std::endl;
	table.toTable("mazige");
	table.toTable("adsfadf");
	table.outputToDisk("C:\\Users\\TranS\\Desktop\\test\\symbol_table.txt");
	for (;;);
	return 0;
}
