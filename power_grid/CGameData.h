#pragma once

// Model
#include "CPlayerData.h"
#include "CDeckData.h"
#include "CMarket.h"

#include "base.h"

class CGameData {
public:
	CGameData();

	int currentRound;
	float currentTime;

	vector<CPlayerData> playerList;

	CDeckData deck;

	CMarket market;

	//Junan: for testing
	void Print();
};

extern CGameData *pGameData;