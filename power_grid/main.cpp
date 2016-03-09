#include <iostream>
#include <random>

#include "CGame.h"

// MAT: get rid of these at some point AFTER testing
#include "CResourceMarket.h"
#include "CPlayer.h"
#include "CDeck.h"
#include "CCard.h"
#include "CMap.h"

// MAT: Leave this here I need it.
extern std::default_random_engine g_random;

int main() {
	std::cout << "Welcome to Power Grid!\n\n";

	// MAT: dont forget to uncomment this later, its faster to test without it
	// create driver class
//	CGame game;

//	game.Initialize();

//	game.Save();

	CMap map("map");
	map.Print();

	return 0;
}