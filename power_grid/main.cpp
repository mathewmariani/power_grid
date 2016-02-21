#include <iostream>

// Testing
#include "CDeck.h"

int main() {
	std::cout << "Welcome to Power Grid\n";

	CDeck deck;
	deck.Draw().Print();

	return 0;
}