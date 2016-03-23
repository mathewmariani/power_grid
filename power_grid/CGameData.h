#pragma once

// Model
#include "CPlayerData.h"
#include "CDeckData.h"
#include "CMarket.h"
#include "CMapData.h"
#include "CMarketView.h"

#include "base.h"

enum BuyResults_e {
	BUY_INSUFFICIENT_FUNDS,
	BUY_NOT_ENOUGH_RESOURCE,
	BUY_SUCCEED
};

class CGameData {
public:
	CGameData();

	int currentRound;
	float currentTime;

	vector<CPlayerData> playerList;

	CDeckData deck;

	CMarket market;
	CMarketView marketView;

	CMapData map;

	BuyResults_e PlayerAttemptsToBuyResource(int playerNum, int resourceType);

	//Junan: for testing
	void Print();
};

extern CGameData *pGameData;