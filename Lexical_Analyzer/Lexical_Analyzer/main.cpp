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

	Automata analyzer("C:\\Users\\TranS\\Desktop\\test\\test.txt");
	analyzer.run();

	for (;;);
	return 0;
}
