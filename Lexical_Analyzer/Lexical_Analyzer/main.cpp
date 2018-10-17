#include"Automata.hpp"
#include"Buffer.hpp"
#include"SymbolTable.hpp"
#include<iostream>

int main()
{
	BufferPairs buffer("C:\\Users\\TranS\\Desktop\\test\\test.txt");
	char tmp = 0;

	
		for (int i = 1; i <= 2; i++) {
			tmp = buffer.Forward();
			if (tmp == EOF) {
				break;
			}
		}
		std::cout << buffer.Output();

		for (int i = 1; i <= 3; i++) {
			tmp = buffer.Forward();
			if (tmp == EOF) {
				break;
			}
		}
		std::cout << buffer.Output();

		for (int i = 1; i <= 2; i++) {
			tmp = buffer.Forward();
			if (tmp == EOF) {
				break;
			}
		}
		std::cout << buffer.Output();
	
		for (int i = 1; i <= 7; i++) {
			tmp = buffer.Forward();
			if (tmp == EOF) {
				break;
			}
		}
		std::cout << buffer.Output();

		for (int i = 1; i <= 7; i++) {
			tmp = buffer.Forward();
			if (tmp == EOF) {
				break;
			}
		}
		std::cout << buffer.Output();

	for (;;);
	return 0;
}
