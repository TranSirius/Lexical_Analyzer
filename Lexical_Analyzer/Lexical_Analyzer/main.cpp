#include "Automata.hpp"
#include "Buffer.hpp"
#include "SymbolTable.hpp"
#include <iostream>
#include <stack>
#include <time.h>

int main()
{
	srand((unsigned int)time(0));
	BufferPairs buffer("C:\\Users\\TranS\\Desktop\\test\\test.txt");
	char tmp = -1;
	int n = 5;

	while (1) {
		if (tmp == '\0') {
			break;
		}
		n = rand() % 7;
		for (int i = 1; i <= n; i++) {
			tmp = buffer.Forward();
			if (tmp == '\0') {
				break;
			}
		}
		if (n % 2) {
			n = rand() % n;
			for(int i = 1; i < n; i++)
				buffer.Backward();
		}
		std::cout << buffer.Output();
	}
	for (;;);
	return 0;
}
