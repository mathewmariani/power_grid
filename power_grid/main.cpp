#include <iostream>
#include "CGame.h"
#include "CResourceMarket.h"
#include "CPlayer.h"
#include "CDeck.h"
#include "CCard.h"

int main() {
	std::cout << "Welcome to Power Grid!\n\n";

	// create driver class
	CGame game;

	game.Initialize();

	game.SavePlayers();


	return 0;
}