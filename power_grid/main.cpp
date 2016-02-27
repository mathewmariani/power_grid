#include <iostream>

// Testing
#include "CResourceMarket.h"
#include "CPlayer.h"

int main() {
	std::cout << "Welcome to Power Grid\n\n";

	// take a look at the market
	PrintResourceMarket();

	CPlayer player("Mat");
	player.Print();

	// buy some stuff
	player.AttemptToBuyCoal();
	player.AttemptToBuyOil();
	player.AttemptToBuyGarbage();
	player.AttemptToBuyUranium();

	// look at all out loot
	player.Print();

	// take a look at the market
	PrintResourceMarket();

	return 0;
}