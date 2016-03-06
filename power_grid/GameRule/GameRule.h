#pragma once

#include "player.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Player;

class GameRule{

private:
	int numberOfPlayers;
	Player_ player[4];



public:
	GameRule();	
	
	void initializeOrder();

	void inGameOrder();

	void reverseGameOrder();

	//int IWantSupply();

	void EarnMoney();

	void showOrder();
	
};

