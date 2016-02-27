#include <iostream>
#include "CGame.h"

// Testing
//#include "CResourceMarket.h"
//#include "CPlayer.h"
//#include "CDeck.h"
//#include "CCard.h"

int main() {
	std::cout << "Welcome to Power Grid!\n\n";

	// create driver class
	CGame game;

	game.Initialize();

	//std::cout << "Welcome to Power Grid\n\n";

	//// take a look at the market
	//PrintResourceMarket();

	//CPlayer player("Mat");
	//player.Print();

	//// buy some stuff
	//player.AttemptToBuyCoal();
	//player.AttemptToBuyOil();
	//player.AttemptToBuyGarbage();
	//player.AttemptToBuyUranium();

	//// look at all out loot
	//player.Print();

	//// take a look at the market
	//PrintResourceMarket();

	//// Test the deck
	//CDeck deck;
	//deck.Draw().Print();

	return 0;
}